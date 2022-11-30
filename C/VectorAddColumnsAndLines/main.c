#include <stdio.h>
#include <stdlib.h>

int main()
{
	int vectorMatrix[10][10], vectorAddedColumns[10], vectorAddedLines[10];
	int numberOfUsedLines, numberOfUsedColumns;
	int i, j;
	//ask the user how many lines and columns he wants to use
	printf("How many lines do you want to use ? ");
	scanf("%d", &numberOfUsedLines);
	printf("How many columns do you want to use ? ");
	scanf("%d", &numberOfUsedColumns);
	//ask the user to fill the matrix
	for (i = 0; i < numberOfUsedLines; i++)
	{
		for (j = 0; j < numberOfUsedColumns; j++)
		{
			printf("Enter the value for the line %d and the column %d : ", i + 1, j + 1);
			scanf("%d", &vectorMatrix[i][j]);
		}
	}
	//add the lines and columns at the same time
	for (i = 0; i < numberOfUsedLines; i++)
	{
		if (i == 0)
		{
			for (j = 0; j < numberOfUsedColumns; j++)
			{
				vectorAddedColumns[j] = vectorMatrix[i][j];
				if (j == 0)
				{
					vectorAddedLines[i] = vectorMatrix[i][j];
				}
				else
				{
					vectorAddedLines[i] += vectorMatrix[i][j];
				}
			}
		}
		else
		{
			for (j = 0; j < numberOfUsedColumns; j++)
			{
				vectorAddedColumns[j] += vectorMatrix[i][j];
				if (j == 0)
				{
					vectorAddedLines[i] = vectorMatrix[i][j];
				}
				else
				{
					vectorAddedLines[i] += vectorMatrix[i][j];
				}
			}
		}
	}
	//print the 2 vectors
	printf("The vector of the added lines is : \n");
	for (i = 0; i < numberOfUsedLines; i++)
	{
		printf("%d \n", vectorAddedLines[i]);
	}
	printf("\nThe vector of the added columns is : \n");
	for (i = 0; i < numberOfUsedColumns; i++)
	{
		printf("%d \n", vectorAddedColumns[i]);
	}
	return 0;
}