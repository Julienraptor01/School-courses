#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	short edgeLength;
	double volume;
	printf("Entrez la longueur de l'arete du cube\n");
	scanf("%d", &edgeLength);
	volume = pow(edgeLength, 3);
	printf("Le volume du cube est de %e\n", volume);
}
