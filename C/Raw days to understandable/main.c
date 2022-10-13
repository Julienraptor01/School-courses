#include <stdio.h>
#include <stdlib.h>

int main()
{
	int rawDays, years, months, days;
	printf("Entrez un nombre de jours\n");
	scanf("%d", &rawDays);
	if (rawDays < 0)
	{
		printf("Le nombre de jours doit etre positif\n");
	}
	else if (rawDays < 360)
	{
		if (rawDays < 30)
		{
			printf("%d jours vaut %d jours\n", rawDays, rawDays);
		}
		else
		{
			months = rawDays / 30;
			days = rawDays % 30;
			printf("%d jours vaut %d mois et %d jours\n", rawDays, months, days);
		}
	}
	else
	{
		if (rawDays % 360 / 30 == 0)
		{
			years = rawDays / 360;
			days = rawDays % 30;
			printf("%d jours vaut %d ans et %d jours\n", rawDays, years, days);
		}
		else
		{
		years = rawDays / 360;
		months = (rawDays % 360) / 30;
		days = (rawDays % 360) % 30;
		printf("%d jours vaut %d ans, %d mois et %d jours\n", rawDays, years, months, days);
		}
	}
	return 0;
}
