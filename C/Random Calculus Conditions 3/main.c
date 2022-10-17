#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number;
	printf("Entrez un nombre\n");
	scanf("%d", &number);
	if (1 <= number && number <= 100)
	{
		if ((number % 2 != 0 && number % 3 == 0) && ((number < 30 || number > 80) || (40 <= number && number <= 75)))
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
