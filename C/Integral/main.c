#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NEXTLINE printf("\n")

void ex1();
void ex2();
void ex3();
void ex4();

float integralXCube(int, int, int, float);

float step(int, int, int);

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
		case 4:
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
			break;
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
	//finding the integral of a function using the low rectangles method
	//the integral is from x1 to x2 of x^3 dx with a step of n
	//the a will be 0 and the b will be 2 but user inputed
	//the number of iteration will be user inputed
	//i need to find the area of each rectangle and then add them all up
	int lowerBound, higherBound, iteration;
	float integral;
	printf("Enter the value of the lower bound of the integral : ");
	scanf("%d", &lowerBound);
	printf("Enter the value of the upper bound of the integral : ");
	scanf("%d", &higherBound);
	printf("Enter the number of iterations : ");
	scanf("%d", &iteration);
	integral = integralXCube(lowerBound, higherBound, iteration, lowerBound);
	NEXTLINE;
	printf("The integral of x^3 from %d to %d with %d iterations is : %f\n", lowerBound, higherBound, iteration, integral);
}

void ex2()
{
	//finding the integral of a function using the high rectangles method
	//the integral is from x1 to x2 of x^3 dx with a step of n
	//the a will be 0 and the b will be 2 but user inputed
	//the number of iteration will be user inputed
	//i need to find the area of each rectangle and then add them all up
	float integral;
	int lowerBound, higherBound, iteration;
	printf("Enter the value of the lower bound of the integral : ");
	scanf("%d", &lowerBound);
	printf("Enter the value of the upper bound of the integral : ");
	scanf("%d", &higherBound);
	printf("Enter the number of iterations : ");
	scanf("%d", &iteration);
	integral = integralXCube(lowerBound, higherBound, iteration, lowerBound + step(lowerBound, higherBound, iteration));
	NEXTLINE;
	printf("The integral of x^3 from %d to %d with %d iterations is : %f\n", lowerBound, higherBound, iteration, integral);
}

void ex3()
{
	//finding the integral of a function using the average of both rectangles method
	//the integral is from x1 to x2 of x^3 dx with a step of n
	//the a will be 0 and the b will be 2 but user inputed
	//the number of iteration will be user inputed
	//i need to find the area of each rectangle and then add them all up
	int lowerBound, higherBound, iteration;
	float integral;
	printf("Enter the value of the lower bound of the integral : ");
	scanf("%d", &lowerBound);
	printf("Enter the value of the upper bound of the integral : ");
	scanf("%d", &higherBound);
	printf("Enter the number of iterations : ");
	scanf("%d", &iteration);
	integral = (integralXCube(lowerBound, higherBound, iteration, lowerBound) + integralXCube(lowerBound, higherBound, iteration, lowerBound + step(lowerBound, higherBound, iteration))) / 2;
	NEXTLINE;
	printf("The integral of x^3 from %d to %d with %d iterations is : %f\n", lowerBound, higherBound, iteration, integral);
}

void ex4()
{
	//finding the integral of a function using the tangent method (middle rectangles)
	//the integral is from x1 to x2 of x^3 dx with a step of n
	//the a will be 0 and the b will be 2 but user inputed
	//the number of iteration will be user inputed
	//i need to find the area of each rectangle and then add them all up
	int lowerBound, higherBound, iteration;
	float integral;
	printf("Enter the value of the lower bound of the integral : ");
	scanf("%d", &lowerBound);
	printf("Enter the value of the upper bound of the integral : ");
	scanf("%d", &higherBound);
	printf("Enter the number of iterations : ");
	scanf("%d", &iteration);
	integral = integralXCube(lowerBound, higherBound, iteration, lowerBound + step(lowerBound, higherBound, iteration) / 2);
	NEXTLINE;
	printf("The integral of x^3 from %d to %d with %d iterations is : %f\n", lowerBound, higherBound, iteration, integral);
}

float integralXCube(int lowerBound, int higherBound, int iteration, float x)
{
	//integral of x^3 from a to b
	//using the x
	int i;
	float integral = 0;
	for (i = 0; i < iteration; i++)
	{
		//the height of the rectangle is x^3
		//the height need to change for each reactangle, it's x + the width of the rectangle * i
		//the width of the rectangle is (b-a)/n
		integral += pow(x + step(lowerBound, higherBound, iteration) * i, 3) * step(lowerBound, higherBound, iteration);
	}
	return integral;
}

float step(int lowerBound, int higherBound, int iteration)
{
	//the width of the rectangle is (b-a)/n
	return (higherBound - lowerBound) / (float)iteration;
}
