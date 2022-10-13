#include <stdio.h>
#include <stdlib.h>

int main()
{
	int posX, posY;
	printf("Entrez la valeur pour l'axe des abscisses\n");
	scanf("%d", &posX);
	printf("Entrez la valeur pour l'axe des ordonnees\n");
	scanf("%d", &posY);
	if (posX > 0)
	{
		if (posY > 0)
		{
			printf("Le point est dans le premier quadrant\n");
		}
		else if (posY < 0)
		{
			printf("Le point est dans le quatrieme quadrant\n");
		}
		else
		{
			printf("Le point est positif sur l'axe des abscisses\n");
		}
	}
	else if (posX < 0)
	{
		if (posY > 0)
		{
			printf("Le point est dans le deuxieme quadrant\n");
		}
		else if (posY < 0)
		{
			printf("Le point est dans le troisieme quadrant\n");
		}
		else
		{
			printf("Le point est negatif sur l'axe des abscisses\n");
		}
	}
	else
	{
		if (posY > 0)
		{
			printf("Le point est positif sur l'axe des ordonnees\n");
		}
		else if (posY < 0)
		{
			printf("Le point est negatif sur l'axe des ordonnees\n");
		}
		else
		{
			printf("Le point est sur l'origine\n");
		}
	}
	return 0;
}
