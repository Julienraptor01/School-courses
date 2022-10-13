#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a, b, c;
	float delta, x1, x2;
	printf("Entrez a\n");
	scanf("%d", &a);
	printf("Entrez b\n");
	scanf("%d", &b);
	printf("Entrez c\n");
	scanf("%d", &c);
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				printf("L'equation est indeterminee\n");
			}
			else
			{
				printf("L'equation est impossible\n");
			}
		}
		else
		{
			x1 = -c / b;
			printf("L'equation a pour solution %g\n", x1);
		}
	}
	else
	{
		delta = pow(b, 2) - 4 * a * c;
		if (delta < 0)
		{
			printf("L'equation est impossible\n");
		}
		else if (delta == 0)
		{
			x1 = -b / (2 * a);
			printf("L'equation a pour solution %g\n", x1);
		}
		else
		{
			x1 = (-b - sqrt(delta)) / (2 * a);
			x2 = (-b + sqrt(delta)) / (2 * a);
			printf("L'equation a pour solutions %g et %g\n", x1, x2);
		}
	}
	return 0;
}
