#include <stdio.h>
#include <stdlib.h>

#define NEXTLINE printf("\n")

void ex1();
void ex2();
void ex3();
//void ex4();

void addTwo2DimensionalVectors(int *, int *, int *, int, int);
//void subtractTwo2DimensionalVectors(int *, int *, int *, int, int);
//void multiplyA2DimensionalVectorByAScalar(int *, int, int *, int, int);

int lenghtOfTheLongestNumberOfA2DimensionalVector(int *, int, int);
int lengthOfAScalar(int);
int negativeNumberFix(int);

int main()
{

	//ask the user which exercise they want to run
	int exercise;
	//this is an infinite loop since EVERY case is handled in my program
	for (;;)
	{
		printf("\nWhich exercise do you want to run ? (1-4)\nYou can use 5 to run them all\nYou can also enter -1 to exit\n");
		scanf("%d", &exercise);
		//simple case here
		switch (exercise)
		{
		case 1:
			printf("\nExercise 1:\n");
			ex1();
			break;
		case 2:
			printf("\nExercise 2:\n");
			ex2();
			break;
		case 3:
			printf("\nExercise 3:\n");
			ex3();
			break;
		/*case 4:
			printf("\nExercise 4:\n");
			ex4();
			break;
		case 5:
			printf("\nExercise 1:\n");
			ex1();
			printf("\nExercise 2:\n");
			ex2();
			printf("\nExercise 3:\n");
			ex3();
			printf("\nExercise 4:\n");
			ex4();
			break;*/
		case -1:
			printf("Exiting the program...\n");
			return 0;
		default:
			printf("Invalid input, please try again.\n");
			break;
		}
	}
	//if i get this value i know smth f up because it shouldn't show up
	return -1;
}

void ex1()
{
	//Adding 2 matrices
	int numberOfColumns, numberOfLines, i, j;
	//Read the number of lines and columns
	printf("Number of lines of the matrices : ");
	scanf("%d", &numberOfLines);
	printf("Number of columns of the matrices : ");
	scanf("%d", &numberOfColumns);
	NEXTLINE;
	//Create the matrices
	//int matrixA[numberOfLines][numberOfColumns], matrixB[numberOfLines][numberOfColumns], matrixC[numberOfLines][numberOfColumns];
	//hardcode the sizes to 3
	int matrixA[3][3], matrixB[3][3], matrixC[3][3];
	//Read the values of the first matrix with a for and indicate the position of the value
	for (i = 0; i < numberOfLines; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("Value of the matrix A at position %d %d : ", i, j);
			scanf("%d", &matrixA[i][j]);
		}
	}
	NEXTLINE;
	//Read the values of the second matrix with a for and indicate the position of the value
	for (i = 0; i < numberOfLines; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("Value of the matrix B at position %d %d : ", i, j);
			scanf("%d", &matrixB[i][j]);
		}
	}
	NEXTLINE;
	//Add the values of the matrices and put the result in the third matrix
	addTwo2DimensionalVectors(matrixA, matrixB, matrixC, numberOfLines, numberOfColumns);
	//i have to align all numbers in terms of columns otherwise it's not pretty
	//i need to find the length of the longest number and force all numbers to print at this length
	//i need to find the length of the longest numbers out of all the matrices
	//i need to print the matrices with the correct spacing
	for (i = 0; i < numberOfLines; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("%*d ", lenghtOfTheLongestNumberOfA2DimensionalVector(matrixA, numberOfLines, numberOfColumns), matrixA[i][j]);
		}
		if (i == numberOfLines / 2)
		{
			printf("+ ");
		}
		else
		{
			printf("  ");
		}
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("%*d ", lenghtOfTheLongestNumberOfA2DimensionalVector(matrixB, numberOfLines, numberOfColumns), matrixB[i][j]);
		}
		if (i == numberOfLines / 2)
		{
			printf("= ");
		}
		else
		{
			printf("  ");
		}
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("%*d ", lenghtOfTheLongestNumberOfA2DimensionalVector(matrixC, numberOfLines, numberOfColumns), matrixC[i][j]);
		}
		NEXTLINE;
	}
}

void ex2()
{
	//same but this time we substract
	int numberOfColumns, numberOfLines, i, j;
	//Read the number of lines and columns
	printf("Number of lines of the matrices : ");
	scanf("%d", &numberOfLines);
	printf("Number of columns of the matrices : ");
	scanf("%d", &numberOfColumns);
	NEXTLINE;
	//Create the matrices
	int matrixA[numberOfLines][numberOfColumns], matrixB[numberOfLines][numberOfColumns], matrixC[numberOfLines][numberOfColumns];
	//Read the values of the first matrix with a for and indicate the position of the value
	for (i = 0; i < numberOfLines; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("Value of the matrix A at position %d %d : ", i, j);
			scanf("%d", &matrixA[i][j]);
		}
	}
	NEXTLINE;
	//Read the values of the second matrix with a for and indicate the position of the value
	for (i = 0; i < numberOfLines; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("Value of the matrix B at position %d %d : ", i, j);
			scanf("%d", &matrixB[i][j]);
		}
	}
	NEXTLINE;
	//Substract the values of the matrices and put the result in the third matrix
	for (i = 0; i < numberOfLines; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
		}
	}
	//i have to align all numbers in terms of columns otherwise it's not pretty
	//i need to find the length of the longest number and force all numbers to print at this length
	//i need to find the length of the longest numbers out of all the matrices
	//i need to print the matrices with the correct spacing
	for (i = 0; i < numberOfLines; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("%*d ", lenghtOfTheLongestNumberOfA2DimensionalVector(matrixA, numberOfLines, numberOfColumns), matrixA[i][j]);
		}
		if (i == numberOfLines / 2)
		{
			printf("- ");
		}
		else
		{
			printf("  ");
		}
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("%*d ", lenghtOfTheLongestNumberOfA2DimensionalVector(matrixB, numberOfLines, numberOfColumns), matrixB[i][j]);
		}
		if (i == numberOfLines / 2)
		{
			printf("= ");
		}
		else
		{
			printf("  ");
		}
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("%*d ", lenghtOfTheLongestNumberOfA2DimensionalVector(matrixC, numberOfLines, numberOfColumns), matrixC[i][j]);
		}
		NEXTLINE;
	}
}

void ex3()
{
	//matrix multiplication by a scalar
	int numberOfColumns, numberOfLines, i, j, k, scalar;
	//Read the number of lines and columns
	printf("Number of lines of the matrices : ");
	scanf("%d", &numberOfLines);
	printf("Number of columns of the matrices : ");
	scanf("%d", &numberOfColumns);
	NEXTLINE;
	//Create the matrix
	//int matrixA[numberOfLines][numberOfColumns], matrixB[numberOfLines][numberOfColumns];
	// hardcode length to 3
	int matrixA[3][3], matrixB[3][3];
	//Read the values of the matrix with a for and indicate the position of the value
	for (i = 0; i < numberOfLines; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("Value of the matrix A at position %d %d : ", i, j);
			scanf("%d", &matrixA[i][j]);
		}
	}
	NEXTLINE;
	//Read the scalar
	printf("Scalar a : ");
	scanf("%d", &scalar);
	NEXTLINE;
	//Multiply the values of the matrix by the scalar and put the result in the second matrix
	for (i = 0; i < numberOfLines; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			matrixB[i][j] = matrixA[i][j] * scalar;
		}
	}
	//i have to align all numbers in terms of columns otherwise it's not pretty
	//i need to find the length of the longest number and force all numbers to print at this length
	//i need to find the length of the longest numbers out of all the matrices
	//i need to print the matrices with the correct spacing
	for (i = 0; i < numberOfLines; i++)
	{
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("%*d ", lenghtOfTheLongestNumberOfA2DimensionalVector(matrixA, numberOfLines, numberOfColumns), matrixA[i][j]);
		}
		if (i == numberOfLines / 2)
		{
			printf("* ");
		}
		else
		{
			printf("  ");
		}
		if (i == numberOfLines / 2)
		{
			printf("%*d ", lengthOfAScalar(scalar), scalar);
		}
		else
		{
			for (k = 0; k <= lengthOfAScalar(scalar); k++)
			{
				printf("  ");
			}
		}
		if (i == numberOfLines / 2)
		{
			printf("= ");
		}
		else
		{
			printf("  ");
		}
		for (j = 0; j < numberOfColumns; j++)
		{
			printf("%*d ", lenghtOfTheLongestNumberOfA2DimensionalVector(matrixB, numberOfLines, numberOfColumns), matrixB[i][j]);
		}
		NEXTLINE;
	}
}

void addTwo2DimensionalVectors(int *vectorA, int *vectorB, int *vectorC, int positionInColumn, int positionInLine)
{
	for (int i = 0; i < positionInColumn; i++)
	{
		for (int j = 0; j < positionInLine; j++)
		{
			vectorC[i * positionInLine + j] = vectorA[i * positionInLine + j] + vectorB[i * positionInLine + j];
		}
	}
}

int lenghtOfTheLongestNumberOfA2DimensionalVector(int *vector, int positionInColumn, int positionInLine)
{
	int i, j, *longestNumber = &vector[0], definitiveLongestNumber, lengthOfLongestNumber = 0;
	//i need to to this with absolute values otherwise, i could have a very big number in negatives
	//instead of storing the value of the longest number i'll store a pointer to it and i need to compared the pointed value but keep the pointer
	// if a negative number with the same number of digits as a positive number exist and the negative number absolute value is smaller than the positive number, the length of the longest number will be wrong so i need a fix
	for (i = 0; i < positionInColumn; i++)
	{
		for (j = 0; j < positionInLine; j++)
		{
			if (abs(negativeNumberFix(vector[i * positionInLine + j])) > abs(negativeNumberFix(*longestNumber)))
			{
				longestNumber = &vector[i * positionInLine + j];
			}
		}
	}
	//i need to move the value of the pointer to a variable so i can use it and fix the negative problem at the same time
	definitiveLongestNumber = negativeNumberFix(*longestNumber);
	//i need to find the length of the longest number in terms of characters
	do
	{
		definitiveLongestNumber /= 10;
		lengthOfLongestNumber++;
	}
	while (definitiveLongestNumber != 0);
	return lengthOfLongestNumber;
}

int lengthOfAScalar(int scalar)
{
	int tempScalar = negativeNumberFix(scalar), lengthOfTheScalar = 0;
	//i need to find the length of the scalar in terms of characters
	do
	{
		tempScalar /= 10;
		lengthOfTheScalar++;
	}
	while (tempScalar != 0);
}

int negativeNumberFix(int number)
{
	if (number < 0)
	{
		return (number * 10);
	}
	else
	{
		return number;
	}
}