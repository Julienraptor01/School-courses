#include <stdio.h>
#include <stdlib.h>

int search(int*, int, int);
void insert(int*, int, int);
void show(int*, int);

int main()
{
	int sortedVector[10] = { 1, 2, 4, 8, 10 }, size = 5, value, maxSize = 10;
	do
	{
		printf("Enter a value : ");
		scanf("%d", &value);
		if (search(sortedVector, size, value) == 0)
		{
			insert(sortedVector, size, value);
			size++;
		}
		show(sortedVector, size);
	}
	while (size < maxSize);
	return 0;
}

int search(int* ptrVector, int size, int value)
{
	int i = size - 1;
	while (i > 0 && *(ptrVector + i) > value)
	{
		i--;
	}
	return *(ptrVector + i) == value;
}

void insert(int* ptrVector, int size, int value)
{
	int i = size;
	while (i > 0 && *(ptrVector + i - 1) > value)
	{
		*(ptrVector + i) = *(ptrVector + i - 1);
		i--;
	}
	*(ptrVector + i) = value;
}

void show(int* ptrVector, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", *(ptrVector + i));
	}
	printf("\n");
}