//heap sort algorithm in c
#include<stdio.h>

void heapify(int array[], int length, int currentIndex)
{
	int largestIndex = currentIndex, leftChildIndex = 2 * currentIndex + 1, rightChildIndex = 2 * currentIndex + 2, temp;
	if (leftChildIndex < length && array[leftChildIndex] > array[largestIndex])
	{
		largestIndex = leftChildIndex;
	}
	if (rightChildIndex < length && array[rightChildIndex] > array[largestIndex])
	{
		largestIndex = rightChildIndex;
	}
	if (largestIndex != currentIndex)
	{
		temp = array[currentIndex];
		array[currentIndex] = array[largestIndex];
		array[largestIndex] = temp;
		heapify(array, length, largestIndex);
	}
}

void heapsort(int array[], int length)
{
	int i, temp;
	for (i = length / 2 - 1; i >= 0; i--)
	{
		heapify(array, length, i);
	}
	for (i = length - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		heapify(array, i, 0);
	}
}

void main()
{
	int array[100], length, i;
	printf("Enter the number of elements : ");
	scanf("%d", &length);
	for (i = 0; i < length; i++)
	{
		printf("Enter the element %d : ", i+1);
		scanf("%d", &array[i]);
	}
	heapsort(array, length);
	printf("The sorted array is : ");
	for (i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
