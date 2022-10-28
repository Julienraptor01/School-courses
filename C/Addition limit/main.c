#include <stdio.h>
#include <stdlib.h>

int main()
{
	int startNumber, limitNumber, counter;
	printf("Entrez le nombre de depart : ");
	scanf("%d", &startNumber);
	printf("Entrez le nombre limite : ");
	scanf("%d", &limitNumber);
	if (startNumber * 2 + 1 > limitNumber)
	{
	printf("Pas d'addition de nombres consecutifs possible\n");
	}
	else
	{
		startNumberIncreased = startNumber;
		counter = 1;
		do
		{
			startNumberIncreased += startNumber + counter;
			counter++;
		}
		while (startNumberIncreased + startNumber + 1 <= limitNumber);
		printf("Le nombre de nombres consecutifs additionnes en demarrant a %d avec un nombre limite de %d est de %d\n", startNumber, limitNumber, counter);
	}
	return 0;
}
