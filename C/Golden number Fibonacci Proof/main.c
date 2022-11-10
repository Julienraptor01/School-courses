#include <stdio.h>
#include <stdlib.h>

#define printf __mingw_printf
#define scanf __mingw_scanf

int main()
{
	long double startNumber, numberAfter;
	int iterationNumber;
	printf("Entrez le nombre de depart: ");
	scanf("%Lf", &startNumber);
	printf("Entrez le nombre de nombres de la suite: ");
	scanf("%d", &iterationNumber);
	numberAfter = startNumber + 1;
	for (int i = 0; i < iterationNumber; i++)
	{
		numberAfter += startNumber;
		startNumber = numberAfter - startNumber;
		printf("%Lf / %Lf = %.63Lf\n", numberAfter, startNumber, numberAfter / startNumber);
	}
	return 0;
}