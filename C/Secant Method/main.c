#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	// secant method to get square roots of a function
	// f(x) = x^3 - 2x - 5
	// range ]a = 2;b = 3[
	// precision = 0.001 (10^-3)
	float a = 2, b = 3, p = 0.001;
	float fa = pow(a, 3) - 2 * a - 5;
	float fb = pow(b, 3) - 2 * b - 5;
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
			x = a - fa * (b - a) / (fb - fa);
			fx = pow(x, 3) - 2 * x - 5;
			if (fx * fa < 0)
			{
				b = x;
				fb = fx;
			}
			else
			{
				a = x;
				fa = fx;
			}
			i++;
		} while (fabs(fx) > p);
		printf("The root of the function is %f\n", x);
	}
	printf("The number of iteration is %d\n", i);
	return 0;
}
