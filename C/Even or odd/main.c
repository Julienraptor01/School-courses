#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number;
	printf("Entrez un nombre\n");
	scanf("%d", &number);
	if (number % 2 == 0)
	{
		printf("Le nombre est pair\n");
	}
	else
	{
		printf("Le nombre est impair\n");
	}
	return 0;
}
