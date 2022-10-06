#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number;
	printf("Entrez un nombre\n");
	scanf("%d", &number);
	if (number > 0)
	{
		printf("Le nombre est positif\n");
	}
	else if (number < 0)
	{
		printf("Le nombre est negatif\n");
	}
	else
	{
		printf("Le nombre est nul\n");
	}
	return 0;
}
