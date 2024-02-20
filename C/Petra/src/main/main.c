#include "main.h"

#include <fcntl.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

actuators_t actuators = {0};
sensors_t sensors = {0};
threads_t threads = {0};
bool actuatorsIsReady = false;
bool sensorsIsReady = false;
bool shouldWrite = false;

int main()
{
	struct termios oldt, newt;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~ICANON;
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
	printf("\e[3 q");
	fflush(stdout);

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
	if (pthread_create(&threads.sensors, NULL, sensorThread, &(threadArgs_t){petra_sensors}) != 0)
	{
		threadPerror("Error creating the capteur thread");
		return -1;
	}
	if (pthread_create(&threads.actuators, NULL, actuatorThread, &(threadArgs_t){petra_actuators}) != 0)
	{
		threadPerror("Error creating the actuator thread");
		return -1;
	}

	pthread_join(threads.console, NULL);
	pthread_cancel(threads.sensors);
	pthread_cancel(threads.actuators);

	close(petra_sensors);
	close(petra_actuators);

	printf("\e[0 q");
	fflush(stdout);
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

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

	char *bitsBuffer = (char *)malloc(9);
	if (bitsBuffer == NULL)
	{
		threadPerror("Error allocating memory for the bitsBuffer");
		return NULL;
	}
	char *messageBuffer = (char *)malloc(233);
	if (messageBuffer == NULL)
	{
		threadPerror("Error allocating memory for the messageBuffer");
		free(bitsBuffer);
		return NULL;
	}

	while (!actuatorsIsReady || !sensorsIsReady)
		nanosleep((const struct timespec[]){{0, 1000000L}}, NULL);

	sensors_t lastSensors = {0};
	bool shouldRefresh = true;
	bool shouldStop = false;
	char input[2];

	printf("\e[2J\e[H");
	fflush(stdout);
	do
	{
		if (sensors.word.unpackedByteLow != lastSensors.word.unpackedByteLow || shouldRefresh)
		{
			sPrintBits(bitsBuffer, sizeof(sensors.word.unpackedByteLow), &sensors.word.unpackedByteLow);
			sThreadPrintf(messageBuffer, "SENSORS = %s\n1 / 2 / 4 - Position of the carrier\n\tf - First conveyor toggle\n\ts - Second conveyor toggle\n\tv - Plunger vacuum toggle\n\tp - Plunger activation\n\ta - Arm activation\n\tg - Graple activation\n\tq - Quit\n", bitsBuffer);
			printf("\e[2J\e[H%s", messageBuffer);
			lastSensors.word.unpackedByteLow = sensors.word.unpackedByteLow;
			shouldRefresh = false;
		}
		if (read(STDIN_FILENO, input, 1) > 0)
		{
			switch (input[0])
			{
			case '1':
				actuators.unpackedByte.carrierPosition = 0;
				shouldWrite = true;
				break;
			case '2':
				actuators.unpackedByte.carrierPosition = 1;
				shouldWrite = true;
				break;
			/*
			case '3':
				actuators.unpackedByte.carrierPosition = 2;
				shouldWrite = true;
				break;
			*/
			case '4':
				actuators.unpackedByte.carrierPosition = 3;
				shouldWrite = true;
				break;
			case 'c':
				actuators.unpackedByte.conveyor1 = true;
				shouldWrite = true;
				break;
			case 'C':
				actuators.unpackedByte.conveyor2 = true;
				shouldWrite = true;
				break;
			case 'v':
				actuators.unpackedByte.plungerVacuum = true;
				shouldWrite = true;
				break;
			case 'p':
				actuators.unpackedByte.plungerActivate = true;
				shouldWrite = true;
				break;
			case 'a':
				actuators.unpackedByte.armActivate = true;
				shouldWrite = true;
				break;
			case 'g':
				actuators.unpackedByte.grapleActivate = true;
				shouldWrite = true;
				break;
			case 'q':
				shouldStop = true;
				shouldWrite = true;
				break;
			}
			shouldRefresh = true;
		}
	} while (!shouldStop && nanosleep((const struct timespec[]){{0, 10000000L}}, NULL) == 0);

	free(bitsBuffer);
	free(messageBuffer);
	pthread_exit(NULL);
}

/**
 * @brief The thread function for the sensors
 * @param arg The file descriptor of the sensors
 * @return void
 */
void *sensorThread(void *arg)
{
	int petra_sensors = ((threadArgs_t *)arg)->fd;

	sensorsIsReady = true;

#ifndef DEBUG
	while (true)
#else
	while (nanosleep((const struct timespec[]){{0, 10000000L}}, NULL) == 0)
#endif
		read(petra_sensors, &sensors.word.unpackedByteLow, 1);
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
	int petra_actuators = ((threadArgs_t *)arg)->fd;

	actuatorsIsReady = true;

	while (true)
		if (shouldWrite)
		{
			write(petra_actuators, &actuators.packedByte, 1);
			actuators.packedByte = 0;
			shouldWrite = false;
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
 * @brief Print the message in a string, with the thread id
 * @param buffer The buffer to write to
 * @param format The format string
 * @param ... The arguments
 * @return void
 */
void sThreadPrintf(char *buffer, const char *format, ...)
{
	char *newFormat = (char *)malloc(strlen(format) + 28);
	if (newFormat == NULL)
	{
		perror("Error allocating memory for the new format");
		return;
	}
	prefix(newFormat, format);
	va_list args;
	va_start(args, format);
	vsprintf(buffer, newFormat, args);
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
	else
		sprintf(newFormat, "Thread %lu: %s", pthread_self(), format);
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