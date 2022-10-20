#include <stdio.h>
#include <stdlib.h>

int main()
{
	int day, month, year, maxDays;
	printf("Entrez la date au format jj/mm/aaaa\n");
	scanf("%d/%d/%d", &day, &month, &year);
	if (year >= 1600 || month >= 1 || month <= 12)
	{
		switch (month)
		{
			case 2:
			{
				if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
				{
					maxDays = 29;
				}
				else
				{
					maxDays = 28;
				}
				break;
			}
			case 4:
			case 6:
			case 9:
			case 11:
			{
				maxDays = 30;
				break;
			}
			default:
			{
				maxDays = 31;
				break;
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
