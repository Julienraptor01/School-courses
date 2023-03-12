#include <stdio.h>

#define EXERCISE 3

extern int celsiusToFahrenheit(int celsius);
extern int ohmsLaw(int resistance, int current);
extern double circlePerimeter(double radius);

void main()
{
#if EXERCISE == 1
	int celsius;
	const char askInput[] = "Enter temperature in Celsius: ";
	const char tellOutput[] = "Temperature in Fahrenheit : %d";
	const char format[] = "%d";
	/*
	printf("Enter temperature in Celsius: ");
	scanf("%d", &celsius);
	printf("Temperature in Fahrenheit : %d", celsiusToFahrenheit(celsius));
	*/
	//rewrite the above code using inline assembly
	_asm
	{
		//print the askInput string
		lea eax, askInput
		push eax
		call printf
		add esp, 4

		//read the input
		lea eax, celsius
		push eax
		lea eax, format
		push eax
		call scanf
		add esp, 8

		//convert celsius to fahrenheit
		mov eax, celsius
		push eax
		call celsiusToFahrenheit
		add esp, 4

		//print the output
		push eax
		lea eax, tellOutput
		push eax
		call printf
		add esp, 8
	}
#elif EXERCISE == 2
	int resistance, current;
	const char askResistance[] = "Enter the resistance : ";
	const char askCurrent[] = "Enter the current : ";
	const char tellOutput[] = "The voltage is : %d";
	const char format[] = "%d";
	_asm
	{
		//print the askResistance string
		lea eax, askResistance
		push eax
		call printf
		add esp, 4

		//read the resistance
		lea eax, resistance
		push eax
		lea eax, format
		push eax
		call scanf
		add esp, 8

		//print the askCurrent string
		lea eax, askCurrent
		push eax
		call printf
		add esp, 4

		//read the current
		lea eax, current
		push eax
		lea eax, format
		push eax
		call scanf
		add esp, 8

		//calculate the voltage
		mov eax, resistance
		push eax
		mov eax, current
		push eax
		call ohmsLaw
		add esp, 8

		//print the output
		push eax
		lea eax, tellOutput
		push eax
		call printf
		add esp, 8
	}
#elif EXERCISE == 3
	double radius, perimeter;
	const char askInput[] = "Enter the radius : ";
	const char tellOutput[] = "The perimeter is : %f";
	const char format[] = "%lf";
	_asm
	{
		//print the askInput string
		lea eax, askInput
		push eax
		call printf
		add esp, 4

		//read the input
		lea eax, radius
		push eax
		lea eax, format
		push eax
		call scanf
		add esp, 8

		//calculate the perimeter
		movsd xmm0, radius
		sub esp, 8
		movsd qword ptr[esp], xmm0
		call circlePerimeter
		add esp, 8
		fstp perimeter

		//print the output
		movsd xmm0, perimeter
		sub esp, 8
		movsd qword ptr[esp], xmm0
		lea eax, tellOutput
		push eax
		call printf
		add esp, 12
	}
#endif
}