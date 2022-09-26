#include <stdio.h>
#include <stdlib.h>

int main()
{
	int Fahrenheit;
	float Celsius;
	printf("Donnez une temperature en Fahrenheit\n");
	scanf("%d", &Fahrenheit);
	Celsius = (Fahrenheit - 32) * 5 / 9.0;
	printf("La temperature en Celsius est %.1f\n", Celsius);
	return 0;
}
