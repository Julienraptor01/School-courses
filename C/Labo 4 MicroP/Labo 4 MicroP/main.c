#include <avr/io.h>

#define SetBit(x,y) (x |= (1 << y))
#define ClearBit(x,y) (x &= ~(1 << y))
#define TestBit(x,y) (x & (1 << y))

#define BaseDelay 500
#define ClockFrequency 8
#define Prescalar 64

void waitBaseDelayCTC(long);

int main(void)
{
	//set the PORTD in output
	DDRD = 0xFF;
	//clear the whole PORTD
	PORTD = 0;
	//loop through LEDs with some timings
	do
	{
		//turn on LED 0 for 0.2s
		SetBit(PORTD, PORTD0);
		waitBaseDelayCTC(200000);
		ClearBit(PORTD, PORTD0);
		//turn on LED 1 for 1s
		SetBit(PORTD, PORTD1);
		waitBaseDelayCTC(1000000);
		ClearBit(PORTD, PORTD1);
		//turn on LED 2 for 0.4s
		SetBit(PORTD, PORTD2);
		waitBaseDelayCTC(400000);
		ClearBit(PORTD, PORTD2);
		//turn on LED 3 for 1s
		SetBit(PORTD, PORTD3);
		waitBaseDelayCTC(1000000);
		ClearBit(PORTD, PORTD3);
		//turn on LED 4 for 0.6s
		SetBit(PORTD, PORTD4);
		waitBaseDelayCTC(600000);
		ClearBit(PORTD, PORTD4);
		//turn on LED 5 for 1s
		SetBit(PORTD, PORTD5);
		waitBaseDelayCTC(1000000);
		ClearBit(PORTD, PORTD5);
		//turn on LED 6 for 0.8s
		SetBit(PORTD, PORTD6);
		waitBaseDelayCTC(800000);
		ClearBit(PORTD, PORTD6);
		//turn on LED 7 for 1s
		SetBit(PORTD, PORTD7);
		waitBaseDelayCTC(1000000);
		ClearBit(PORTD, PORTD7);
		//wait 2s
		waitBaseDelayCTC(2000000);
	}
	while (1);
	return 0;
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
