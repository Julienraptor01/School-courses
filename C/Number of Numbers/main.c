#include <stdio.h>
#include <stdlib.h>

int main()
{
	int vector[10] = { 0 }, number, digit;
	printf("Le programme va vous demander de saisir un nombre entier positif en boucle tant que vous n'entrez pas -1.\n\n");
	do
	{
		printf("Entrez un nombre entier positif : ");
		scanf("%d", &number);
		if (number > 0)
		{
			do
			{
				digit = number % 10;
				vector[digit]++;
				number = number / 10;
			}
			while (number > 0);
		}
	}
	while (number > -1);
	if (number < -1)
	{
		printf("\nJ'avais dis -1 pour quitter, mais on va dire que n'importe quel nombre negatif est bon aussi...");
	}
		printf("\nVoici le nombre de fois que chaque chiffre a ete entre : \n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d : %d\n", i, vector[i]);
	}
	return 0;
}
