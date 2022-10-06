#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number1, number2, number3;
	printf("Entrez le premier nombre\n");
	scanf("%d", &number1);
	printf("Entrez le deuxieme nombre\n");
	scanf("%d", &number2);
	printf("Entrez le troisieme nombre\n");
	scanf("%d", &number3);
	if (number1 < number2)
	{
		if (number1 < number3)
		{
			if (number2 < number3)
			{
				printf("Les nombre dans l'ordre croissant sont %d, %d et %d", number1, number2, number3);
			}
			else
			{
				printf("Les nombre dans l'ordre croissant sont %d, %d et %d", number1, number3, number2);
			}
		}
		else
		{
			printf("Les nombre dans l'ordre croissant sont %d, %d et %d", number3, number1, number2);
		}
	}
	else
	{
		if (number2 < number3)
		{
			if (number1 < number3)
			{
				printf("Les nombre dans l'ordre croissant sont %d, %d et %d", number2, number1, number3);
			}
			else
			{
				printf("Les nombre dans l'ordre croissant sont %d, %d et %d", number2, number3, number1);
			}
		}
		else
		{
			printf("Les nombre dans l'ordre croissant sont %d, %d et %d", number3, number2, number1);
		}
	}
	return 0;
}
