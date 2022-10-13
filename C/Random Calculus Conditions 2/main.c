#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number;
	printf("Entrez un nombre\n");
	scanf("%d", &number);
	if (1 <= number && number <= 100)
	{
		if ((30 <= number && number <= 80) && number % 5 != 0)
		{
			printf("VRAI\n");
		}
	}
	else
	{
		printf("Le nombre doit etre compris entre 1 inclus et 100 inclus\n");
	}
	return 0;
}
