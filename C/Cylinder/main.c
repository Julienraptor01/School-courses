#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _USE_MATH_DEFINES

int main()
{
	int height, diameter;
	float radius, baseArea, volume, basePerimeter, lateralSurfaceArea, totaleSurfaceArea;
	printf("Entrez la hauteur du cylindre\n");
	scanf("%d", &height);
	printf("Entrez le diametre du cylindre\n");
	scanf("%d", &diameter);
	radius = diameter / 2.0;
	baseArea = M_PI * pow(radius, 2);
	volume = baseArea * height;
	basePerimeter = 2 * M_PI * radius;
	lateralSurfaceArea = basePerimeter * height;
	totaleSurfaceArea = 2 * baseArea + lateralSurfaceArea;
	printf("Le rayon du cylindre est de %f\n", radius);
	printf("La surface de la base du cylindre est de %f\n", baseArea);
	printf("Le volume du cylindre est de %f\n", volume);
	printf("Le perimetre de la base du cylindre est de %f\n", basePerimeter);
	printf("La surface laterale du cylindre est de %f\n", lateralSurfaceArea);
	printf("La surface totale du cylindre est de %f\n", totaleSurfaceArea);
	return 0;
}
