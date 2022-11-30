#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ex1();
void ex2();
void ex3();
void ex4();
void ex5();

int main()
{
	//ask the user which exercise they want to run
	int exercise;
	do
	{
		printf("\nWhich exercise do you want to run ? (1-5)\nYou can use 6 to run them all\nYou can also enter -1 to exit\n");
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
			printf("\nExercise 5:\n");
			ex5();
			break;
		case 6:
			printf("\nExercise 1:\n");
			ex1();
			printf("\nExercise 2:\n");
			ex2();
			printf("\nExercise 3:\n");
			ex3();
			printf("\nExercise 4:\n");
			ex4();
			printf("\nExercise 5:\n");
			ex5();
			break;
		case -1:
			printf("Exiting the program...\n");
			return 0;
		default:
			printf("Invalid input, please try again.\n");
			break;
		}
	}
	while (exercise != -1);
}

void ex1()
{
	// Ex: 1
	// y = x^4-3x+1 [a=1, b=1,5] précision=0,1
	// Binary search the interval where the root of the function is
	// f(x) = x^4 - 3x + 1
	// in the interval [a, b] with precision p
	float a = 1, b = 1.5, p = 0.1;
	float fa = pow(a, 4) - 3 * a + 1;
	float fb = pow(b, 4) - 3 * b + 1;
	float x, fx;
	int i = 0;
	if (fa * fb >= 0)
	{
		if (fa == 0 && fb == 0)
		{
			printf("The 2 points %f and %f are roots of the function\n", a, b);
		}
		else if (fa == 0)
		{
			printf("The point %f is a root of the function\n", a);
		}
		else if (fb == 0)
		{
			printf("The point %f is a root of the function\n", b);
		}
		else
		{
			printf("The interval [%f, %f] does not contain a root of the function\n", a, b);
		}
	}
	else
	{
		do
		{
			x = (a + b) / 2;
			fx = pow(x, 4) - 3 * x + 1;
			if (fx * fa <= 0)
			{
				b = x;
			}
			else
			{
				a = x;
				fa = fx;
			}
			i++;
		}
		while (b - a > p);
		printf("The root of the function is in the interval [%.2f, %.2f]\n", a, b);
	}
	printf("The number of iteration is %d\n", i);
}

void ex2()
{
	// Ex: 2
	// y = 2x^2+x-1 [a=0, b=4] précision=0,01
	// Binary search the interval where the root of the function is
	// f(x) = 2x^2 + x - 1
	// in the interval [a, b] with precision p
	float a = 0, b = 4, p = 0.01;
	float fa = 2 * pow(a, 2) + a - 1;
	float fb = 2 * pow(b, 2) + b - 1;
	float x, fx;
	int i = 0;
	if (fa * fb >= 0)
	{
		if (fa == 0 && fb == 0)
		{
			printf("The 2 points %f and %f are roots of the function\n", a, b);
		}
		else if (fa == 0)
		{
			printf("The point %f is a root of the function\n", a);
		}
		else if (fb == 0)
		{
			printf("The point %f is a root of the function\n", b);
		}
		else
		{
			printf("The interval [%f, %f] does not contain a root of the function\n", a, b);
		}
	}
	else
	{
		do
		{
			x = (a + b) / 2;
			fx = 2 * pow(x, 2) + x - 1;
			if (fx * fa <= 0)
			{
				b = x;
			}
			else
			{
				a = x;
				fa = fx;
			}
			i++;
		}
		while (b - a > p);
		printf("The root of the function is in the interval [%.3f, %.3f]\n", a, b);
	}
	printf("The number of iteration is %d\n", i);
}

void ex3()
{
	// Ex: 3
	// y = 2x^2+x-1 [a=-3, b=0] précision=0,01
	// Binary search the interval where the root of the function is
	// f(x) = 2x^2 + x - 1
	// in the interval [a, b] with precision p
	float a = -3, b = 0, p = 0.01;
	float fa = 2 * pow(a, 2) + a - 1;
	float fb = 2 * pow(b, 2) + b - 1;
	float x, fx;
	int i = 0;
	if (fa * fb >= 0)
	{
		if (fa == 0 && fb == 0)
		{
			printf("The 2 points %f and %f are roots of the function\n", a, b);
		}
		else if (fa == 0)
		{
			printf("The point %f is a root of the function\n", a);
		}
		else if (fb == 0)
		{
			printf("The point %f is a root of the function\n", b);
		}
		else
		{
			printf("The interval [%f, %f] does not contain a root of the function\n", a, b);
		}
	}
	else
	{
		do
		{
			x = (a + b) / 2;
			fx = 2 * pow(x, 2) + x - 1;
			if (fx * fa <= 0)
			{
				b = x;
			}
			else
			{
				a = x;
				fa = fx;
			}
			i++;
		}
		while (b - a > p);
		printf("The root of the function is in the interval [%.3f, %.3f]\n", a, b);
	}
	printf("The number of iteration is %d\n", i);
}

void ex4()
{
	// Ex: 4
	// y = x^3-3x^2-3x+5 [a=0, b=3] précision=0,1
	// Binary search the interval where the root of the function is
	// f(x) = x^3 - 3x^2 - 3x + 5
	// in the interval [a, b] with precision p
	float a = 0, b = 3, p = 0.1;
	float fa = pow(a, 3) - 3 * pow(a, 2) - 3 * a + 5;
	float fb = pow(b, 3) - 3 * pow(b, 2) - 3 * b + 5;
	float x, fx;
	int i = 0;
	if (fa * fb >= 0)
	{
		if (fa == 0 && fb == 0)
		{
			printf("The 2 points %f and %f are roots of the function\n", a, b);
		}
		else if (fa == 0)
		{
			printf("The point %f is a root of the function\n", a);
		}
		else if (fb == 0)
		{
			printf("The point %f is a root of the function\n", b);
		}
		else
		{
			printf("The interval [%f, %f] does not contain a root of the function\n", a, b);
		}
	}
	else
	{
		do
		{
			x = (a + b) / 2;
			fx = pow(x, 3) - 3 * pow(x, 2) - 3 * x + 5;
			if (fx * fa <= 0)
			{
				b = x;
			}
			else
			{
				a = x;
				fa = fx;
			}
			i++;
		}
		while (b - a > p);
		printf("The root of the function is in the interval [%.2f, %.2f]\n", a, b);
	}
	printf("The number of iteration is %d\n", i);
}

void ex5()
{
	// Ex: 5
	// y = x^3-3x^2-3x+5 [a=-2, b=4] précision=0,1
	// Binary search the interval where the root of the function is
	// f(x) = x^3 - 3x^2 - 3x + 5
	// in the interval [a, b] with precision p
	float a = -2, b = 4, p = 0.1;
	float fa = pow(a, 3) - 3 * pow(a, 2) - 3 * a + 5;
	float fb = pow(b, 3) - 3 * pow(b, 2) - 3 * b + 5;
	float x, fx;
	int i = 0;
	if (fa * fb >= 0)
	{
		if (fa == 0 && fb == 0)
		{
			printf("The 2 points %f and %f are roots of the function\n", a, b);
		}
		else if (fa == 0)
		{
			printf("The point %f is a root of the function\n", a);
		}
		else if (fb == 0)
		{
			printf("The point %f is a root of the function\n", b);
		}
		else
		{
			printf("The interval [%f, %f] does not contain a root of the function\n", a, b);
		}
	}
	else
	{
		do
		{
			x = (a + b) / 2;
			fx = pow(x, 3) - 3 * pow(x, 2) - 3 * x + 5;
			if (fx * fa <= 0)
			{
				b = x;
			}
			else
			{
				a = x;
				fa = fx;
			}
			i++;
		}
		while (b - a > p);
		printf("The root of the function is in the interval [%.2f, %.2f]\n", a, b);
	}
	printf("The number of iteration is %d\n", i);
}