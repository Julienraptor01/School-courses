#ifndef MAIN_H
#define MAIN_H

#include <pthread.h>

#define DEBUG

#ifndef DEBUG
#define PETRA_ACTUATEURS "/dev/actuateursPETRA"
#define PETRA_CAPTEURS "/dev/capteursPETRA"
#else
#define PETRA_ACTUATEURS "./actuateursPETRA"
#define PETRA_CAPTEURS "./capteursPETRA"
#endif

#define BINARY_BYTE "%.8b"

union actuateurs
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
} actuateurs;

union capteurs
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
} capteurs;

pthread_t main_thread;

int main();
void thread_printf(const char *format, ...);
void thread_perror(const char *str);

#endif
