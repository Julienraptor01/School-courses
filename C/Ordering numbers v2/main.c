#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number1, number2, number3, temp;
	printf("Entrez le premier nombre\n");
	scanf("%d", &number1);
	printf("Entrez le deuxieme nombre\n");
	scanf("%d", &number2);
	printf("Entrez le troisieme nombre\n");
	scanf("%d", &number3);
	if (number1 > number2)
	{
		temp = number1;
		number1 = number2;
		number2 = temp;
	}
	if (number2 > number3)
	{
		temp = number2;
		number2 = number3;
		number3 = temp;
	}
	if (number1 > number2)
	{
		temp = number1;
		number1 = number2;
		number2 = temp;
	}
	printf("Les nombres dans l'ordre croissant sont %d, %d et %d\n", number1, number2, number3);
	return 0;
}
