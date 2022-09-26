#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int sideLength, perimeter, area;
	printf("\nEntrez la longueur du cote\n");
	scanf("%d", &sideLength);
	perimeter = sideLength * 4;
	printf("\nLe perimetre vaut %d\n", perimeter);
	area = pow(sideLength, 2);
	printf("\nL'aire vaut %d\n", area);
	return 0;
}
