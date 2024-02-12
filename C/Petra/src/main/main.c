#include "main.h"

#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	main_thread = pthread_self();

	actuateurs.packedByte = 0b00000000;
	thread_printf("Actuateurs: "BINARY_BYTE"\n", actuateurs.packedByte);

	actuateurs.unpackedByte.plungerVacuum = 1;
	thread_printf("Actuateurs: "BINARY_BYTE"\n", actuateurs.packedByte);

	int petra_actuateurs = open(PETRA_ACTUATEURS, O_WRONLY);

	if (petra_actuateurs == -1)
	{
		thread_perror("Erreur ouverture \""PETRA_ACTUATEURS"\"");
		return -1;
	}
	else
		thread_printf("\""PETRA_ACTUATEURS"\" opened\n");

	int petra_capteurs = open(PETRA_CAPTEURS, O_RDONLY);
	if (petra_capteurs == -1)
	{
		thread_perror("Erreur ouverture \""PETRA_CAPTEURS"\"");
		return -1;
	}
	else
		thread_printf("\""PETRA_CAPTEURS"\" opened\n");

	for (int i = 0; i < 10; sleep(1), i++)
	{
		read(petra_capteurs, &capteurs.word.unpackedByteLow, 1);
		thread_printf("CAPTEURS = "BINARY_BYTE"\n", capteurs.word.unpackedByteLow);
	}

	for (int i = 0; i < 10; sleep(1), i++)
	{
		thread_printf("ACTUATEURS ecriture d'un 1\n");
		actuateurs.unpackedByte.plungerVacuum = 1;
		int rc = write(petra_actuateurs, &actuateurs.packedByte, 1);
		if (rc <= 0)
		{
			thread_printf("rc: %d\n", rc);
			thread_perror("");
		}

		sleep(1);

		thread_printf("ACTUATEURS ecriture d'un 0\n");
		actuateurs.unpackedByte.plungerVacuum = 0;
		rc = write(petra_actuateurs, &actuateurs.packedByte, 1);
		if (rc <= 0)
		{
			thread_printf("rc: %d\n", rc);
			thread_perror("");
		}
	}

	actuateurs.packedByte = 0b00000000;
	write(petra_actuateurs, &actuateurs.packedByte, 1);

	close(petra_capteurs);
	close(petra_actuateurs);

	return 0;
}

void thread_printf(const char *format, ...)
{
	if (pthread_equal(pthread_self(), main_thread))
		printf("Main: ");
	else
		printf("Thread %lu: ", (unsigned long)pthread_self());

	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

void thread_perror(const char *str)
{
	char buffer[256];
	if (pthread_equal(pthread_self(), main_thread))
		sprintf(buffer, "Main: %s", str);
	else
		sprintf(buffer, "Thread %lu: %s", (unsigned long)pthread_self(), str);
	perror(buffer);
}
