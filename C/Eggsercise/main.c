#include <stdio.h>
#include <stdlib.h>

void fillTable(int *, int, int);
void permutTable2By2Vertically(int *, int, int);
void printTable(int *, int, int);

int main()
{
	int table[10][15], numberOfRows, numberOfColumns;
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
	fillTable(&table[0][0], numberOfRows, numberOfColumns);
	printf("\n");
	printTable(&table[0][0], numberOfRows, numberOfColumns);
	printf("\n");
	permutTable2By2Vertically(&table[0][0], numberOfRows, numberOfColumns);
	printTable(&table[0][0], numberOfRows, numberOfColumns);
	printf("\n");
	return 0;
}

void fillTable(int *table, int numberOfRows, int numberOfColumns)
{
	int i, j, *pointerToFirstCell = &table[0];
	for (i = 0; i < numberOfRows; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			*(pointerToFirstCell + i * numberOfColumns + j) = rand() % 16 + 5;
		}
	}
}

void permutTable2By2Vertically(int *table, int numberOfRows, int numberOfColumns)
{
	int i, j, *pointerToFirstCell = &table[0], temp;
	for (i = 0; i < numberOfRows; i += 2)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			temp = *(pointerToFirstCell + i * numberOfColumns + j);
			*(pointerToFirstCell + i * numberOfColumns + j) = *(pointerToFirstCell + (i + 1) * numberOfColumns + j);
			*(pointerToFirstCell + (i + 1) * numberOfColumns + j) = temp;
		}
	}
}

void printTable(int *table, int numberOfRows, int numberOfColumns)
{
	int i, j, *pointerToFirstCell = &table[0];
	for (i = 0; i < numberOfRows; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("%*d ", 2, *(pointerToFirstCell + i * numberOfColumns + j));
		}
		printf("\n");
	}
}