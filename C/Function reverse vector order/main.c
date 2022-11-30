#include <stdio.h>
#include <stdlib.h>

void reverseOrder(int*, int);

int main()
{
	int vector[10], size = 10, i;
	for (i = 0; i < size; i++)
	{
		printf("Entrez l'element %d : ", i + 1);
		scanf("%d", &vector[i]);
	}
	reverseOrder(vector, size);
	for (i = 0; i < size; i++)
	{
		printf("%d ", vector[i]);
	}
	return 0;
}

void reverseOrder(int *vector, int size)
{
	int i, temp;
	for (i = 0; i < size / 2; i++)
	{
		temp = vector[i];
		vector[i] = vector[size - i - 1];
		vector[size - i - 1] = temp;
	}
}