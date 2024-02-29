#include "main.h"

#include <fcntl.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

actuators_t actuators = {0};
sensors_t sensors = {0};
threads_t threads = {0};
bool actuatorsIsReady = false;
bool sensorsIsReady = false;

int main()
{
	threads.main = pthread_self();

	int petra_sensors = openSensors();
	if (petra_sensors == -1)
		return -1;
	int petra_actuators = openActuators();
	if (petra_actuators == -1)
		return -1;

	if (pthread_create(&threads.console, NULL, consoleThread, NULL) != 0)
	{
		threadPerror("Error creating the console thread");
		return -1;
	}
	if (pthread_create(&threads.sensors, NULL, sensorThread, &(petraThreadArgs_t){petra_sensors}) != 0)
	{
		threadPerror("Error creating the capteur thread");
		return -1;
	}
	if (pthread_create(&threads.actuators, NULL, actuatorThread, &(petraThreadArgs_t){petra_actuators}) != 0)
	{
		threadPerror("Error creating the actuator thread");
		return -1;
	}

	pthread_join(threads.console, NULL);
	pthread_cancel(threads.sensors);
	pthread_cancel(threads.actuators);

	close(petra_sensors);
	close(petra_actuators);

	return 0;
}

/**
 * @brief The thread function for the console
 * @param arg !!!UNUSED!!!
 * @return void
 */
void *consoleThread(void *arg)
{
	(void)arg;

	printf("\e[?25l");
	fflush(stdout);

	initscr();
	WINDOW *top = newwin(TOP_CONSOLE_HEIGHT, COLS, 0, 0);
	WINDOW *middle = newwin(MIDDLE_CONSOLE_HEIGHT, COLS, TOP_CONSOLE_HEIGHT, 0);
	WINDOW *bottom = newwin(BOTTOM_CONSOLE_HEIGHT, COLS, TOP_CONSOLE_HEIGHT + MIDDLE_CONSOLE_HEIGHT, 0);

	keypad(top, FALSE);
	keypad(middle, FALSE);
	keypad(bottom, TRUE);

	mvwprintw(middle, 0, 0, "1 / 2 / 4 - Position of the carrier\n\tf - First conveyor toggle\n\ts - Second conveyor toggle\n\tv - Plunger vacuum toggle\n\tp - Plunger toggle\n\ta - Arm toggle\n\tg - Graple toggle\n\tq - Quit\n");
	wrefresh(middle);

	if (pthread_create(&threads.topWindow, NULL, topWindowThread, &(windowThreadArgs_t){top}) != 0)
	{
		threadPerror("Error creating the top window thread");
		pthread_exit(NULL);
	}
	if (pthread_create(&threads.bottomWindow, NULL, bottomWindowThread, &(windowThreadArgs_t){bottom}) != 0)
	{
		threadPerror("Error creating the bottom window thread");
		pthread_cancel(threads.topWindow);
		pthread_exit(NULL);
	}

	pthread_join(threads.bottomWindow, NULL);
	pthread_cancel(threads.topWindow);

	delwin(top);
	delwin(middle);
	delwin(bottom);
	endwin();

	printf("\e[?25h");
	fflush(stdout);

	pthread_exit(NULL);
}

/**
 * @brief The thread function for the top window
 * @param arg The window
 * @return void
 */
void *topWindowThread(void *arg)
{
	WINDOW *window = ((windowThreadArgs_t *)arg)->window;

	char *bitsBuffer = (char *)malloc(9);
	if (bitsBuffer == NULL)
	{
		threadPerror("Error allocating memory for the bitsBuffer");
		pthread_exit(NULL);
	}
	char *messageBuffer = (char *)malloc(41);
	if (messageBuffer == NULL)
	{
		threadPerror("Error allocating memory for the messageBuffer");
		free(bitsBuffer);
		pthread_exit(NULL);
	}

	sensors_t lastSensors = {0};

	while (!sensorsIsReady);

	while (true)
	{
		if (sensors.word.unpackedByteLow != lastSensors.word.unpackedByteLow)
		{
			sPrintBits(bitsBuffer, sizeof(sensors.word.unpackedByteLow), &sensors.word.unpackedByteLow);
			mvwprintw(window, 0, 0, "SENSORS = %s\n", bitsBuffer);
			wrefresh(window);
			lastSensors.word.unpackedByteLow = sensors.word.unpackedByteLow;
		}
	}
}

/**
 * @brief The thread function for the bottom window
 * @param arg The window
 * @return void
 */
void *bottomWindowThread(void *arg)
{
	WINDOW *window = ((windowThreadArgs_t *)arg)->window;

	char input[2];

	while (!actuatorsIsReady);

	while (true)
	{
		wgetnstr(window, input, 1);
		switch (input[0])
		{
			case '1':
				actuators.unpackedByte.carrierPosition = 0;
				break;
			case '2':
				actuators.unpackedByte.carrierPosition = 1;
				break;
			case '3':
				actuators.unpackedByte.carrierPosition = 2;
				break;
			case '4':
				actuators.unpackedByte.carrierPosition = 3;
				break;
			case 'f':
				actuators.unpackedByte.conveyor1 = !actuators.unpackedByte.conveyor1;
				break;
			case 's':
				actuators.unpackedByte.conveyor2 = !actuators.unpackedByte.conveyor2;
				break;
			case 'v':
				actuators.unpackedByte.plungerVacuum = !actuators.unpackedByte.plungerVacuum;
				break;
			case 'p':
				actuators.unpackedByte.plungerActivate = !actuators.unpackedByte.plungerActivate;
				break;
			case 'a':
				actuators.unpackedByte.armActivate = !actuators.unpackedByte.armActivate;
				break;
			case 'g':
				actuators.unpackedByte.grapleActivate = !actuators.unpackedByte.grapleActivate;
				break;
			case 'q':
				pthread_exit(NULL);
		}
		flushinp();
		wclear(window);
		wrefresh(window);
	}
}

/**
 * @brief The thread function for the sensors
 * @param arg The file descriptor of the sensors
 * @return void
 */
void *sensorThread(void *arg)
{
	int petra_sensors = ((petraThreadArgs_t *)arg)->fd;

	sensorsIsReady = true;

#ifndef DEBUG
	while (true)
#else
	while (nanosleep((const struct timespec[]){{0, 10000000L}}, NULL) == 0)
#endif
		if (read(petra_sensors, &sensors.word.unpackedByteLow, 1) <= 0)
			threadPerror("Error reading from the sensors");
#ifdef DEBUG
	pthread_exit(NULL);
#endif
}

/**
 * @brief The thread function for the actuators
 * @param arg The file descriptor of the actuators
 * @return void
 */
void *actuatorThread(void *arg)
{
	int petra_actuators = ((petraThreadArgs_t *)arg)->fd;

	actuators_t lastActuators = {0};

	actuatorsIsReady = true;

	while (true)
		if (lastActuators.packedByte != actuators.packedByte)
		{
			if (write(petra_actuators, &actuators.packedByte, 1) <= 0)
				threadPerror("Error writing to the actuators");
			lastActuators.packedByte = actuators.packedByte;
		}
}

/**
 * @brief Open the Petra sensors
 * @return The file descriptor or -1 on error
 */
int openSensors()
{
	return openPetra(PETRA_SENSORS, O_RDONLY);
}

/**
 * @brief Open the Petra actuators
 * @return The file descriptor or -1 on error
 */
int openActuators()
{
	return openPetra(PETRA_ACTUATORS, O_WRONLY);
}

/**
 * @brief Open the Petra interface file with the given flags
 * @param path The path of the IO file
 * @param flags The flags to open the file with
 * @return The file descriptor or -1 on error
 */
int openPetra(const char *path, int flags)
{
	int file = open(path, flags);
	file == -1 ? threadPerror("Error opening \"%s\"", path) : threadPrintf("\"%s\" opened\n", path);
	return file;
}

/**
 * @brief Print a message to the console, with the thread id
 * @param format The format string
 * @param ... The arguments
 * @return void
 */
void threadPrintf(const char *format, ...)
{
	char *newFormat = (char *)malloc(strlen(format) + 13);
	if (newFormat == NULL)
	{
		perror("Error allocating memory for the new format");
		return;
	}
	prefix(newFormat, format);
	va_list args;
	va_start(args, format);
	vprintf(newFormat, args);
	va_end(args);
	free(newFormat);
}

/**
 * @brief Print the perror message to the console, with the thread id
 * @param format The format string
 * @param ... The arguments
 * @return void
 */
void threadPerror(const char *format, ...)
{
	char *newFormat = (char *)malloc(strlen(format) + 23);
	if (newFormat == NULL)
	{
		perror("Error allocating memory for the buffer");
		return;
	}
	prefix(newFormat, format);
	char *buffer = (char *)malloc(strlen(newFormat) + 10);
	if (buffer == NULL)
	{
		perror("Error allocating memory for the buffer");
		free(newFormat);
		return;
	}

	va_list args;
	va_start(args, format);
	vsprintf(buffer, newFormat, args);
	va_end(args);
	perror(buffer);

	free(newFormat);
	free(buffer);
}

/**
 * @brief Add the thread id to the format string
 * @param newFormat The new format string
 * @param format The format string
 * @return void
 */
void prefix(char *newFormat, const char *format)
{
	if (pthread_equal(pthread_self(), threads.main))
		sprintf(newFormat, "Main: %s", format);
	else if (pthread_equal(pthread_self(), threads.sensors))
		sprintf(newFormat, "Sensors: %s", format);
	else if (pthread_equal(pthread_self(), threads.actuators))
		sprintf(newFormat, "Actuators: %s", format);
	else if (pthread_equal(pthread_self(), threads.console))
		sprintf(newFormat, "Console: %s", format);
	else if (pthread_equal(pthread_self(), threads.topWindow))
		sprintf(newFormat, "Top Window: %s", format);
	else if (pthread_equal(pthread_self(), threads.bottomWindow))
		sprintf(newFormat, "Bottom Window: %s", format);
	else
		sprintf(newFormat, "Thread %lu: %s", (unsigned long)pthread_self(), format);
}

/**
 * @brief Print the bits of a variable in a string due to the lack of support for %.8b by the Petra
 * @param buffer The buffer to write to
 * @param size The size of the variable
 * @param ptr The pointer to the variable
 * @return void
 */
void sPrintBits(char *buffer, size_t const size, void const *const ptr)
{
	unsigned char *b = (unsigned char *)ptr;
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = 7; j >= 0; j--)
		{
			unsigned char byte = (b[i] >> j) & 1;
			sprintf(buffer, "%u", byte);
			buffer++;
		}
	}
}
