#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number1, number2, number3, max, numberOfMax=0;
	printf("Entrez le premier nombre\n");
	scanf("%d", &number1);
	printf("Entrez le deuxieme nombre\n");
	scanf("%d", &number2);
	printf("Entrez le troisieme nombre\n");
	scanf("%d", &number3);
	if (a > b)
	{
		if (a > c)
		{
			max = a;
		}
		else
		{
			max = c;
		}
	}
	else
	{
		if (b > c)
		{
			max = b;
		}
		else
		{
			max = c;
		}
	}
	printf("Le plus grand nombre est %d\n", max);
	if (number1 == max)
	{
		numberOfMax++;
	}
	if (number2 == max)
	{
		numberOfMax++;
	}
	if (number3 == max)
	{
		numberOfMax++;
	}
	printf("Le plus grand nombre est apparu %d fois\n", numberOfMax);
	return 0;
}
