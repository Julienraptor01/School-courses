#include <stdio.h>
#include <stdlib.h>

void fillTable(int*, int, int, int);
void permutTable2By2Vertically(int *, int, int, int);
void printTable(int *, int, int, int);

int main()
{
	int table[10][15], numberOfRows, numberOfColumns, maxNumberOfColumns = 15;
	srand(time(NULL));
	do
	{
		printf("Enter an even number of rows inferior to 10 : ");
		scanf("%d", &numberOfRows);
	}
	while (numberOfRows % 2 != 0 || numberOfRows > 10);
	do
	{
		printf("Enter a number of columns inferior to 15 : ");
		scanf("%d", &numberOfColumns);
	}
	while (numberOfColumns > 15);
	fillTable(&table[0][0], numberOfRows, numberOfColumns, maxNumberOfColumns);
	printf("\n");
	printTable(&table[0][0], numberOfRows, numberOfColumns, maxNumberOfColumns);
	printf("\n");
	permutTable2By2Vertically(&table[0][0], numberOfRows, numberOfColumns, maxNumberOfColumns);
	printTable(&table[0][0], numberOfRows, numberOfColumns, maxNumberOfColumns);
	printf("\n");
	return 0;
}

void fillTable(int *tableOrigin, int numberOfRows, int numberOfColumns, int maxNumberOfColumns)
{
	int i, j;
	for (i = 0; i < numberOfRows; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			*(tableOrigin + i * maxNumberOfColumns + j) = rand() % 16 + 5;
		}
	}
}

void permutTable2By2Vertically(int *tableOrigin, int numberOfRows, int numberOfColumns, int maxNumberOfColumns)
{
	int i, j, temp;
	for (i = 0; i < numberOfRows; i += 2)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			temp = *(tableOrigin + i * maxNumberOfColumns + j);
			*(tableOrigin + i * maxNumberOfColumns + j) = *(tableOrigin + (i + 1) * maxNumberOfColumns + j);
			*(tableOrigin + (i + 1) * maxNumberOfColumns + j) = temp;
		}
	}
}

void printTable(int *tableOrigin, int numberOfRows, int numberOfColumns, int maxNumberOfColumns)
{
	int i, j;
	for (i = 0; i < numberOfRows; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("%*d ", 2, *(tableOrigin + i * maxNumberOfColumns + j));
		}
		printf("\n");
	}
}