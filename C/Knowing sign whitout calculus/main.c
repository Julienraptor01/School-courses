#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int number1, number2;
	printf("Entrez le premier nombre\n");
	scanf("%d", &number1);
	printf("Entrez le deuxieme nombre\n");
	scanf("%d", &number2);
	// sign after multiplication whitout doing calculus
	if (number1 > 0 && number2 < 0 || number1 < 0 && number2 > 0)
	{
		printf("Le signe apres multiplication est negatif\n");
	}
	else
	{
		printf("Le signe apres multiplication est positif\n");
	}
	// sign after addition whitout doing calculus
	if (number1 >= 0 && number2 >= 0)
	{
		printf("Le signe apres addition est positif\n");
	}
	else if (number1 < 0 && number2 < 0)
	{
		printf("Le signe apres addition est negatif\n");
	}
	else if (number1 >= 0 && number2 < 0)
	{
		if (number1 > abs(number2))
		{
			printf("Le signe apres addition est positif\n");
		}
		else
		{
			printf("Le signe apres addition est negatif\n");
		}
	}
	else if (number1 < 0 && number2 >= 0)
	{
		if (abs(number1) > number2)
		{
			printf("Le signe apres addition est negatif\n");
		}
		else
		{
			printf("Le signe apres addition est positif\n");
		}
	}
	else
	{
		printf("J'ai oublié ce cas\n");
	}
	return 0;
}
