#include <stdio.h>
#include <stdlib.h>

int main()
{
	int day1, day2, month1, month2, year1, year2, timeDifference, dayDifference, monthDifference, yearDifference;
	printf("Entrez le premier jour\n");
	scanf("%d", &day1);
	printf("Entrez le premier mois\n");
	scanf("%d", &month1);
	printf("Entrez la premiere annee\n");
	scanf("%d", &year1);
	printf("Entrez le deuxieme jour\n");
	scanf("%d", &day2);
	printf("Entrez le deuxieme mois\n");
	scanf("%d", &month2);
	printf("Entrez la deuxieme annee\n");
	scanf("%d", &year2);
	timeDifference = abs((day2 - day1) + (month2 - month1) * 30 + (year2 - year1) * 360);
	printf("Il y a %d jours de difference\n", timeDifference);
	yearDifference = timeDifference / 360;
	monthDifference = timeDifference % 360 / 30;
	dayDifference = timeDifference % 360 % 30;
	printf("Il y a %d ans, %d mois et %d jours de difference\n", yearDifference, monthDifference, dayDifference);
	return 0;
}
