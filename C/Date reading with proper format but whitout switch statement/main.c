#include <stdio.h>
#include <stdlib.h>

int main()
{
	int day, month, year, maxDays;
	printf("Entrez la date au format jj/mm/aaaa\n");
	scanf("%d/%d/%d", &day, &month, &year);
	if (year >= 1600 || month >= 1 || month <= 12)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			maxDays = 31;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			maxDays = 30;
		}
		else if (month == 2)
		{
			if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
			{
				maxDays = 29;
			}
			else
			{
				maxDays = 28;
			}
		}
		if (day >= 1 && day <= maxDays)
		{
			printf("La date est valide\n");
		}
		else
		{
			printf("La date est invalide\n");
		}
	}
	else
	{
		printf("La date est invalide\n");
	}
	return 0;
}
