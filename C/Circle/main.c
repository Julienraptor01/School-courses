#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _USE_MATH_DEFINES

int main()
{
	int radius;
	float perimeter, area;
	printf("Entrez la longueur du rayon du cercle\n");
	scanf("%d", &radius);
	perimeter = 2 * M_PI * radius;
	area = M_PI * pow(radius, 2);
	printf("Le perimetre du cercle est %.2f\n", perimeter);
	printf("L'aire du cercle est %.2f\n", area);
	return 0;
}
