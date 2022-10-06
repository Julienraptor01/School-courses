#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number1, number2, sum, difference;
	printf("Entrez le premier nombre\n");
	scanf("%d", &number1);
	printf("Entrez le deuxieme nombre\n");
	scanf("%d", &number2);
	sum = number1 + number2;
	printf("La somme de %d et de %d est %d\n", number1, number2, sum);
	if (number1 >= number2)
	{
		difference = number1 - number2;
		printf("La difference entre %d et %d est %d\n", number1, number2, difference);
	}
	else
	{
		difference = number2 - number1;
		printf("La difference entre %d et %d est %d\n", number2, number1, difference);
	}
	return 0;
}
