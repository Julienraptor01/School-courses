#include <stdio.h>
#include <stdlib.h>

int search(int, int *, int, int *);

int main()
{
	int vector[11], minRandom = 0, maxRandom = 20, number, size = 10, i, pos, exist;
	srand(time(NULL));
	for (i = 0; i < size; i++)
	{
		vector[i] = rand() % (maxRandom - minRandom + 1) + minRandom;
	}
	printf("Entrez un nombre entre %d et %d : ", minRandom, maxRandom);
	scanf("%d", &number);
	exist = search(number, vector, size, &pos);
	if (exist)
		printf("Le nombre %d existe dans le tableau et se trouve a la position %d\n", number, pos + 1);
	else
		printf("Le nombre %d n'existe pas dans le tableau\n", number);
	printf("| ");
	for (i = 0; i < size; i++)
	{
		printf("%d | ", vector[i]);
	}
	return 0;
}

int search(int number, int *vector, int size, int *pos)
{
	int i, exist;
	vector[size + 1] = number;
	while (vector[i] != number)
	{
		i++;
	}
	if (i < size + 1)
	{
		exist = 1;
		*pos = i;
	}
	else
	{
		exist = 0;
	}
	return exist;
}