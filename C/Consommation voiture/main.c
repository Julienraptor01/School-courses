#include <stdio.h>
#include <stdlib.h>

int main()
{
	int mileage1, refuel, mileage2;
	float consumption;
	printf("Entrez le kilometrage lors du premier plein\n");
	scanf("%d", &mileage1);
	printf("Entrez le nombre de litres de carburant mis dans le reservoir\n");
	scanf("%d", &refuel);
	printf("Entrez le kilometrage lors du second plein\n");
	scanf("%d", &mileage2);
	consumption = (float)refuel / (mileage2 - mileage1) * 100;
	printf("La consommation est de %.1f litres au 100km\n", consumption);
	return 0;
}
