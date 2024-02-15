#include "main.h"

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

actuateurs_t actuateurs = {0};
capteurs_t capteurs = {0};
pthread_t mainThread = 0;

int main()
{
	mainThread = pthread_self();

	int petra_actuateurs = open(PETRA_ACTUATEURS, O_WRONLY);

	if (petra_actuateurs == -1)
	{
		threadPerror("Erreur ouverture \""PETRA_ACTUATEURS"\"");
		return -1;
	}
	else
		threadPrintf("\""PETRA_ACTUATEURS"\" opened\n");

	int petra_capteurs = open(PETRA_CAPTEURS, O_RDONLY);
	if (petra_capteurs == -1)
	{
		threadPerror("Erreur ouverture \""PETRA_CAPTEURS"\"");
		return -1;
	}
	else
		threadPrintf("\""PETRA_CAPTEURS"\" opened\n");

	printf("\e[?25l");
	char *buffer = (char *)malloc(9);
	if (buffer == NULL)
	{
		threadPerror("Error allocating memory for the buffer");
		return -1;
	}
	for (unsigned int i = 0; i < USHRT_MAX + 1; nanosleep((const struct timespec[]){{0, 1000000L}}, NULL), i++)
	{
		read(petra_capteurs, &capteurs.word.unpackedByteLow, 1);
		sPrintBits(buffer, sizeof(capteurs.word.unpackedByteLow), &capteurs.word.unpackedByteLow);
		printf("\e[2J\e[HMain: CAPTEURS = %s\n", buffer);
	}
	free(buffer);
	printf("\e[?25h");

	close(petra_capteurs);
	close(petra_actuateurs);

	return 0;
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
 * @param str The message
 * @return void
 */
void threadPerror(const char *str)
{
	int length = strlen(str);
	char *buffer = (char *)malloc(length + 30);
	if (buffer == NULL)
	{
		perror("Error allocating memory for the buffer");
		return;
	}
	strcpy(buffer, str);
	if (pthread_equal(pthread_self(), mainThread))
		sprintf(buffer, "Main: %s", str);
	else
		sprintf(buffer, "Thread %lu: %s", (unsigned long)pthread_self(), str);
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