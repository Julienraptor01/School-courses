#include <stdio.h>
#include <stdlib.h>

int main()
{
	int startNumber, startNumberIncreased, limitNumber;
	printf("Entrez le nombre de depart : ");
	scanf("%d", &startNumber);
	printf("Entrez le nombre limite : ");
	scanf("%d", &limitNumber);
	if (startNumber > limitNumber / 2)
	{
	printf("Pas d'addition de nombres consecutifs possible\n");
	}
	else
	{
		startNumberIncreased = startNumber;
		do
		{
			startNumberIncreased += startNumber + 1;
			startNumber++;
		}
		while (startNumberIncreased < limitNumber);
		startNumberIncreased -= startNumber;
		printf("La somme des nombres consecutifs est : %d\n", startNumberIncreased);
	}
	return 0;
}
