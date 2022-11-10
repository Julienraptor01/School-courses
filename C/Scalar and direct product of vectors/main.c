#include <stdio.h>
#include <stdlib.h>

int main()
{
	int vector1[6], vector2[6], vector3[6];
	//input
	for (int i = 0; i < 6; i++)
	{
		printf("Entrez la valeur du vecteur 1 a la position %d : ", i + 1);
		scanf("%d", &vector1[i]);
		printf("Entrez la valeur du vecteur 2 a la position %d : ", i + 1);
		scanf("%d", &vector2[i]);
	}
	//get the scalar product of the two vectors
	vector3[0] = 0;
	for (int i = 0; i < 6; i++)
	{
		vector3[0] += vector1[i] * vector2[i];
	}
	//output
	printf("\nLe produit scalaire des deux vecteurs est : %d\n\n", vector3[0]);
	//get the direct product of the two vectors
	for (int i = 0; i < 6; i++)
	{
		vector3[i] = vector1[i] * vector2[i];
	}
	//output
	for (int i = 0; i < 6; i++)
	{
		printf("La valeur du vecteur 3 a la position %d est : %d\n", i + 1, vector3[i]);
	}
	return 0;
}
