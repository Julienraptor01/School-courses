#include <avr/io.h>

#define SetBit(x,y) (x |= (1 << y))
#define ClearBit(x,y) (x &= ~(1 << y))
#define TestBit(x,y) (x & (1 << y))

#define EXERCICE 2

#define BaseDelay 500
#define ClockFrequency 8
#define Prescalar 64

void waitBaseDelayNormal(long);
void waitBaseDelayCTC(long);

int main(void)
{
#if EXERCICE == 1
	SetBit(DDRB, DDB0);
	do
	{
		PORTB ^= (1 << PORTB0);
		waitBaseDelay(2000000);
	}
	while (1);
#elif EXERCICE == 2
	SetBit(DDRB, DDB2);
	do
	{
		PORTB ^= (1 << PORTB2);
		waitBaseDelayNormal(500000);
	}
	while (1);
#endif
	return 0;
}

void waitBaseDelayNormal(long timeToWait)
{
	TCCR0A = 0;
	SetBit(TCCR0B, CS01);
	for (int i = 0; i < timeToWait / BaseDelay; i++)
	{
		TCNT0 = 256 - ((ClockFrequency / Prescalar) * BaseDelay);
		TIFR0 = 1 << TOV0;
		while (!TestBit(TIFR0, TOV0));
		TCCR0B = 0;
	}
}

void waitBaseDelayCTC(long timeToWait)
{
	TCCR0A = 1 << WGM01;
	TCNT0 = 0;
	OCR0A = 256 - (256 - ((ClockFrequency / Prescalar) * BaseDelay));
	TCCR0B = 1 << CS01 | 1 << CS00;
	for (int i = 0; i < timeToWait / BaseDelay; i++)
	{
		TIFR0 = 1 << OCF0A;
		while (!TestBit(TIFR0, OCF0A));
	}
	TCCR0B = 0;
}
