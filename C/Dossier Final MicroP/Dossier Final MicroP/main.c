#include <avr/io.h>

#define FOSC 8000000 // Clock Speed
#define BAUD 4800 // Baud Rate
#define MYUBRR FOSC/16/BAUD-1 // UBRR Value

#define SetBit(x,y) (x |= (1 << y))
#define ClearBit(x,y) (x &= ~(1 << y))
#define TestBit(x,y) (x & (1 << y))

void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);
unsigned char USART_Receive(void);
void USART_SendString(char* sMsg);

int main(void)
{
	char cCommande, cPort = 'B', cPin, cValue;
	//set the port B and C as output by default
	DDRB = 0xFF;
	DDRC = 0xFF;
	//clear the port B and C by default
	PORTB = 0x00;
	PORTC = 0x00;
	USART_Init(MYUBRR);
	do
	{
		//tell the user to input with the menu list
		//TODO : add the menu list
		USART_SendString("Entrez une commande\r\n");
		//get the input
		cCommande = USART_Receive();
		switch (cCommande)
		{
		//(P)ort : select port (B or C)
		case 'P':
			do
			{
				//tell the user to input
				USART_SendString("Entrez le port (B ou C)\r\n");
				//get the input
				cPort = USART_Receive();
			}
			while ((cPort != 'B') && (cPort != 'C'));
			//tell the user what port was selected
			USART_SendString("Port ");
			USART_Transmit(cPort);
			USART_SendString(" selectionne\r\n");
			break;
		//(L)ecture : read one pin (0 to 7)
		case 'L':
			do
			{
				//tell the user to input
				USART_SendString("Entrez le numero de broche (0 a 7)\r\n");
				//get the input
				cPin = USART_Receive();
			}
			while ((cPin < '0') || (cPin > '7'));
			//read the pin on the selected port
			if (cPort == 'B')
			{
				//set the pin as input
				ClearBit(DDRB, cPin);
				//read the pin
				cValue = TestBit(PINB, cPin);
			}
			else
			{
				//set the pin as input
				ClearBit(DDRC, cPin);
				//read the pin
				cValue = TestBit(PINC, cPin);
			}
			//tell the user the value of the pin
			USART_SendString("La valeur de la broche ");
			USART_Transmit(cPin);
			USART_SendString(" est ");
			USART_Transmit(cValue);
			USART_SendString("\r\n");
			break;
		//(Allumer) : turn on one pin (0 to 7)
		case 'A':
			do
			{
				//tell the user to input
				USART_SendString("Entrez le numero de broche (0 a 7)\r\n");
				//get the input
				cPin = USART_Receive();
			}
			while ((cPin < '0') || (cPin > '7'));
			//turn on the pin on the selected port
			if (cPort == 'B')
			{
				//set the pin as output
				SetBit(DDRB, cPin);
				//turn on the pin
				SetBit(PORTB, cPin);
			}
			else
			{
				//set the pin as output
				SetBit(DDRC, cPin);
				//turn on the pin
				SetBit(PORTC, cPin);
			}
			//tell the user the pin was turned on
			USART_SendString("La broche ");
			USART_Transmit(cPin);
			USART_SendString(" est allume\r\n");
			break;
		//(Eteindre) : turn off one pin (0 to 7)
		case 'E':
			do
			{
				//tell the user to input
				USART_SendString("Entrez le numero de broche (0 a 7)\r\n");
				//get the input
				cPin = USART_Receive();
			}
			while ((cPin < '0') || (cPin > '7'));
			//turn off the pin on the selected port
			if (cPort == 'B')
			{
				//set the pin as output
				SetBit(DDRB, cPin);
				//turn off the pin
				ClearBit(PORTB, cPin);
			}
			else
			{
				//set the pin as output
				SetBit(DDRC, cPin);
				//turn off the pin
				ClearBit(PORTC, cPin);
			}
			//tell the user the pin was turned off
			USART_SendString("La broche ");
			USART_Transmit(cPin);
			USART_SendString(" est eteinte\r\n");
			break;
		//(C)lignoter : blink one pin (0 to 7) 5 times at a rate of 1Hz
		case 'C':
			do
			{
				//tell the user to input
				USART_SendString("Entrez le numero de broche (0 a 7)\r\n");
				//get the input
				cPin = USART_Receive();
			}
			while ((cPin < '0') || (cPin > '7'));
			//blink the pin on the selected port
			if (cPort == 'B')
			{
				//set the pin as output
				SetBit(DDRB, cPin);
				//blink the pin
				for (i = 0; i < 5; i++)
				{
					SetBit(PORTB, cPin);
					_delay_ms(500);
					ClearBit(PORTB, cPin);
					_delay_ms(500);
				}
			}
			else
			{
				//set the pin as output
				SetBit(DDRC, cPin);
				//blink the pin
				for (i = 0; i < 5; i++)
				{
					SetBit(PORTC, cPin);
					_delay_ms(500);
					ClearBit(PORTC, cPin);
					_delay_ms(500);
				}
			}
			//tell the user the pin was blinked
			USART_SendString("La broche ");
			USART_Transmit(cPin);
			USART_SendString(" a clignote\r\n")
			break;
		default:
			USART_SendString("Commande inconnue\r\n");
			break;
		}
	}
	while (1);
}

void USART_Init(unsigned int ubrr)
{
	//set baud rate
	UBRR0 = ubrr;
	//enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	//set frame format: 8data, 2stop bit
	UCSR0C = (3<<UCSZ00);
}

void USART_Transmit(unsigned char data)
{
	//wait for empty transmit buffer
	while(!(UCSR0A & (1<<UDRE0)));
	//put data into buffer, sends the data
	UDR0 = data;
}

unsigned char USART_Receive(void)
{
	//wait for data to be received
	while(!(UCSR0A & (1<<RXC0)));
	//get and return received data from buffer
	return UDR0;
}

void USART_SendString(char* sMsg)
{
	while (*sMsg != 0)
	{
		USART_Transmit(*sMsg);
		sMsg++;
	}
}