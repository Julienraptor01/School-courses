#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number, numberAfterFactorial;
	do
	{
		printf("Entrez un nombre entier positif : ");
		scanf("%d", &number);
	} while (number < 0);
	if (number == 0)
	{
		printf("La factorielle de 0 est 1\n");
	}
	else
	{
		numberAfterFactorial = number;
		for (int i = number - 1; i > 1; i--)
		{
			numberAfterFactorial *= i;
		}
		printf("La factorielle de %d est %d\n", number, numberAfterFactorial);
	}
	return 0;
}
