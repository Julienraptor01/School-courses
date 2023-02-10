#include <avr/io.h>

#define SetBit(x,y) (x |= (1<<y))
#define ClearBit(x,y) (x &= ~(1<<y))

#define EXERCICE 7

/* useless here
void delay_500ms(void)
{
	volatile long int i;
	for (i = 0; i < 117646; i++);
}
*/

int main(void)
{
#if EXERCICE == 1
	// allumer les LEDs 2, 4 et 5 du port B
	DDRB |= (1 << DDB2) | (1 << DDB4) | (1 << DDB5);
	PORTB |= (1 << PORTB2) | (1 << PORTB4) | (1 << PORTB5);
#elif EXERCICE == 2
	// allumer les LEDs 0, 2, 4 et 6 du port D
	DDRD |= (1 << DDD0) | (1 << DDD2) | (1 << DDD4) | (1 << DDD6);
	PORTD |= (1 << PORTD0) | (1 << PORTD2) | (1 << PORTD4) | (1 << PORTD6);
#elif EXERCICE == 3
	// copier la valeur d'entr�e du port C vers le port D
	DDRC = 0x00;
	DDRD = 0xFF;
	PORTD = PINC;
#elif EXERCICE == 4
	// copier la valeur de PC1 vers PD2 sans changer les autres bits
	ClearBit(DDRC, DDC1);
	SetBit(DDRD, DDD2);
	/*if (PINC & (1 << PINC1))
	{
		SetBit(PORTD, PORTD2);
	}
	else
	{
		ClearBit(PORTD, PORTD2);
	}*/
	// rewrite in one line
	PORTD = (PORTD & ~(1 << PORTD2)) | ((PINC & (1 << PINC1)) << (PORTD2 - PINC1));
#elif EXERCICE == 5
	// copier la valeur de PC0 vers PD1 et la valeur de PC1 vers PD2 sans changer les autres bits
	DDRC &= ~((1 << DDC0) | (1 << DDC1));
	DDRD |= (1 << DDD1) | (1 << DDD2);
	/*switch (PINC & ((1 << PINC0) | (1 << PINC1)))
	{
	case 0:
		PORTD &= ~((1 << PORTD1) | (1 << PORTD2));
		break;
	case 1:
		SetBit(PORTD, PORTD1);
		ClearBit(PORTD, PORTD2);
		break;
	case 2:
		ClearBit(PORTD, PORTD1);
		SetBit(PORTD, PORTD2);
		break;
	case 3:
		PORTD |= (1 << PORTD1) | (1 << PORTD2);
		break;
	}*/
	// rewrite in one line
	PORTD = (PORTD & ~((1 << PORTD1) | (1 << PORTD2))) | ((PINC & ((1 << PINC0) | (1 << PINC1))) << (PORTD1 - PINC0));
#elif EXERCICE == 6
	// copier la valeur de PB2 vers PC0 et la valeur de PB0 vers PC4 sans changer les autres bits
	DDRB &= ~((1 << DDB0) | (1 << DDB2));
	DDRC |= (1 << DDC0) | (1 << DDC4);
	/*switch (PINB & ((1 << PINB0) | (1 << PINB2)))
	{
	case 0:
		PORTC &= ~((1 << PORTC0) | (1 << PORTC4));
		break;
	case 1:
		ClearBit(PORTC, PORTC0);
		SetBit(PORTC, PORTC4);
		break;
	case 4:
		SetBit(PORTC, PORTC0);
		ClearBit(PORTC, PORTC4);
		break;
	case 5:
		PORTC |= (1 << PORTC0) | (1 << PORTC4);
		break;
	}*/
	// rewrite in one line
	PORTC = (PORTC & ~((1 << PORTC0) | (1 << PORTC4))) | ((PINB & (1 << PINB0)) << (PORTC4 - PINB0)) | ((PINB & (1 << PINB2)) >> (PINB2 - PORTC0));
#elif EXERCICE == 7
	// copier la valeur de PC1 vers PD2 sans changer les autres bits uniquement quand PB2 = 1
	DDRB &= ~(1 << DDB2);
	DDRC &= ~(1 << DDC1);
	DDRD |= (1 << DDD2);
	/*if (PINB & (1 << PINB2))
	{
		if (PINC & (1 << PINC1))
		{
			SetBit(PORTD, PORTD2);
		}
		else
		{
			ClearBit(PORTD, PORTD2);
		}
	}*/
	// rewrite in one line
	PORTD = (PORTD & ~(1 << PORTD2)) | (((PINB & (1 << PINB2)) && (PINC & (1 << PINC1))) << PORTD2);
	// alternative with & instead of &&
	// PORTD = (PORTD & ~(1 << PORTD2)) | (PINB & (1 << PINB2)) & (((PINC & (1 << PINC1))) << (PINB2 - PINC1));
#endif
}