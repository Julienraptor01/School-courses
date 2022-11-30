#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	// newton method to get square root of a function
	// f(x) = x^3 - 2x - 5
	// f'(x) = 3x^2 - 2
	// range ]a = 2;b = 3[
	// precision = 0.001 (10^-3)
	// x0 = 2.5
	// x1 = x0 - f(x0)/f'(x0)
	float a = 2, b = 3, p = 0.001;
	float fa = pow(a, 3) - 2 * a - 5, fb = pow(b, 3) - 2 * b - 5;
	float x = 2.5, fx = pow(x, 3) - 2 * x - 5, fpx = 3 * pow(x, 2) - 2;
	int i = 0;
	// ask a start value for x in the range
	do
	{
		printf("Enter a start value for x in the range ]%g;%g[ : ", a, b);
		scanf("%f", &x);
	} while (x <= a || x >= b);
	fx = pow(x, 3) - 2 * x - 5;
	// in theory this is a good idea but in practice since computers can't calcutate values exactly it's not
	if (fa * fb >= 0 || fx == 0)
	{
		if (fa == 0 && fb == 0 && fx == 0)
		{
			printf("The 3 points %f, %f and %f are roots of the function.\n", a, b, x);
		}
		else if (fa == 0 && fb == 0)
		{
			printf("The 2 points %f and %f are roots of the function.\n", a, b);
		}
		else if (fa == 0 && fx == 0)
		{
			printf("The 2 points %f and %f are roots of the function.\n", a, x);
		}
		else if (fb == 0 && fx == 0)
		{
			printf("The 2 points %f and %f are roots of the function.\n", b, x);
		}
		else if (fa == 0)
		{
			printf("The point %f is a root of the function.\n", a);
		}
		else if (fb == 0)
		{
			printf("The point %f is a root of the function.\n", b);
		}
		else if (fx == 0)
		{
			printf("The point %f is a root of the function.\n", x);
		}
		else
		{
			printf("The interval [%f, %f] does not contain a root of the function\n", a, b);
		}
	}
	else
	{
		fpx = 3 * pow(x, 2) - 2;
		do
		{
			x = x - fx / fpx;
			fx = pow(x, 3) - 2 * x - 5;
			fpx = 3 * pow(x, 2) - 2;
			i++;
		} while (fabs(fx) > p);
		printf("The root of the function is %f\n", x);
	}
	printf("The number of iteration is %d\n", i);
	return 0;
}