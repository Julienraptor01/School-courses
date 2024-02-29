#ifndef MAIN_H
#define MAIN_H

#include <ncurses.h>
#include <pthread.h>

#ifndef DEBUG
#define PETRA_SENSORS "/dev/capteursPETRA"
#define PETRA_ACTUATORS "/dev/actuateursPETRA"
#else
#define PETRA_SENSORS "./capteursPETRA"
#define PETRA_ACTUATORS "./actuateursPETRA"
#endif

#define TOP_CONSOLE_HEIGHT 2
#define MIDDLE_CONSOLE_HEIGHT 9
#define BOTTOM_CONSOLE_HEIGHT 2

typedef union actuators_t
{
	struct unpackedByte
	{
		unsigned carrierPosition : 2;
		unsigned conveyor1 : 1;
		unsigned conveyor2 : 1;
		unsigned plungerVacuum : 1;
		unsigned plungerActivate : 1;
		unsigned armActivate : 1;
		unsigned grapleActivate : 1;
	} unpackedByte;
	unsigned char packedByte;
} actuators_t;

typedef union sensors_t
{
	struct unpackedWord
	{
		unsigned lengthEntry : 1;
		unsigned lengthExit : 1;
		unsigned H : 1;
		unsigned slot : 1;
		unsigned carrierStable : 1;
		unsigned armPosition : 1;
		unsigned plungerPosition : 1;
		unsigned dispenserEmpty : 1;
		// unsigned H1 : 1; // Hole 1
		// unsigned H2 : 1; // Hole 2
		// unsigned H3 : 1; // Hole 3
		// unsigned H4 : 1; // Hole 4
		// unsigned H5 : 1; // Hole 5
		// unsigned H6 : 1; // Hole 6
		// unsigned : 2;    // unnassigned
	} unpackedWord;
	struct word
	{
		unsigned char unpackedByteLow;
		// unsigned char unpacked_byte_high;
	} word;
	// unsigned short packedWord;
} sensors_t;

typedef struct threads_t
{
	pthread_t main;
	pthread_t sensors;
	pthread_t actuators;
	pthread_t console;
	pthread_t topWindow;
	pthread_t bottomWindow;
} threads_t;

typedef struct petraThreadArgs_t
{
	int fd;
} petraThreadArgs_t;

typedef struct windowThreadArgs_t
{
	WINDOW *window;
} windowThreadArgs_t;

typedef struct check_t
{
	bool isReady;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
} check_t;

int main();
void *consoleThread(void *arg);
void *topWindowThread(void *arg);
void *bottomWindowThread(void *arg);
void *sensorThread(void *arg);
void *actuatorThread(void *arg);
int openSensors();
int openActuators();
int openPetra(const char *path, int flags);
void threadPrintf(const char *format, ...);
void threadPerror(const char *format, ...);
void prefix(char * newFormat, const char * format);
void sPrintBits(char *buffer, size_t const size, void const *const ptr);

#endif
