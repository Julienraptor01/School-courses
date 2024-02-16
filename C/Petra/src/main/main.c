#include "main.h"

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <pthread.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

actuators_t actuators = {0};
sensors_t sensors = {0};
pthread_t mainThread = 0;
bool shouldStop = false;

int main()
{
	mainThread = pthread_self();

	int petra_sensors = openSensors();
	if (petra_sensors == -1)
		return -1;

	close(petra_sensors);

	int petra_actuators = openActuators();
	if (petra_actuators == -1)
		return -1;

	close(petra_actuators);

	pthread_t sensorThreadID;
	if (pthread_create(&sensorThreadID, NULL, sensorThread, NULL) != 0)
	{
		threadPerror("Error creating the capteur thread");
		return -1;
	}

	char *buffer = (char *)malloc(9);
	if (buffer == NULL)
	{
		threadPerror("Error allocating memory for the buffer");
		return -1;
	}
	do
	{
		sPrintBits(buffer, sizeof(sensors.word.unpackedByteLow), &sensors.word.unpackedByteLow);
		printf("\e[2J\e[HMain: SENSORS = %s\n", buffer);
	} while (!shouldStop == true && nanosleep((const struct timespec[]){{0, 10000000L}}, NULL) == 0);
	free(buffer);

	pthread_join(sensorThreadID, NULL);

	return 0;
}

/**
 * @brief The thread function for the sensors
 * @param arg TODO
 * @return void
 */
void *sensorThread(void *arg)
{
	(void)arg;

	int petra_sensors = openSensors();
	if (petra_sensors == -1)
		return NULL;

	while (!shouldStop)
		read(petra_sensors, &sensors.word.unpackedByteLow, 1);

	close(petra_sensors);
	return NULL;
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
	char *newFormat = (char *)malloc(strlen(format) + 30);
	if (newFormat == NULL)
	{
		perror("Error allocating memory for the new format");
		return;
	}
	if (pthread_equal(pthread_self(), mainThread))
		sprintf(newFormat, "Main: %s", format);
	else
		sprintf(newFormat, "Thread %lu: %s", (unsigned long)pthread_self(), format);
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
	char *buffer = (char *)malloc(strlen(format) + 30);
	if (buffer == NULL)
	{
		perror("Error allocating memory for the buffer");
		return;
	}
	if (pthread_equal(pthread_self(), mainThread))
		sprintf(buffer, "Main: %s", format);
	else
		sprintf(buffer, "Thread %lu: %s", (unsigned long)pthread_self(), format);
	va_list args;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	perror(buffer);
	free(buffer);
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