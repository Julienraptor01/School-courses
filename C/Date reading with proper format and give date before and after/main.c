#include <stdio.h>
#include <stdlib.h>

int main()
{
	int day, month, year, maxDays, dayBefore, monthBefore, yearBefore, dayAfter, monthAfter, yearAfter;
	printf("Entrez la date au format jj/mm/aaaa : ");
	scanf("%d/%d/%d", &day, &month, &year);
	if (year >= 1600 && month >= 1 && month <= 12)
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
			if (day == 1)
			{
				if (month == 1)
				{
					dayBefore = 31;
					monthBefore = 12;
					yearBefore = year - 1;
				}
				else
				{
					switch (month)
					{
					case 2:
					{
						if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
						{
							dayBefore = 29;
						}
						else
						{
							dayBefore = 28;
						}
						break;
					}
					case 4:
					case 6:
					case 9:
					case 11:
					{
						dayBefore = 30;
						break;
					}
					default:
					{
						dayBefore = 31;
						break;
					}
					}
					monthBefore = month - 1;
					yearBefore = year;
				}
			}
			else
			{
				dayBefore = day - 1;
				monthBefore = month;
				yearBefore = year;
			}
			if (day == maxDays)
			{
				if (month == 12)
				{
					dayAfter = 1;
					monthAfter = 1;
					yearAfter = year + 1;
				}
				else
				{
					dayAfter = 1;
					monthAfter = month + 1;
					yearAfter = year;
				}
			}
			else
			{
				dayAfter = day + 1;
				monthAfter = month;
				yearAfter = year;
			}
			printf("La date est valide, celle du la veille est %d/%d/%d et celle du lendemain est %d/%d/%d\n", dayBefore, monthBefore, yearBefore, dayAfter, monthAfter, yearAfter);
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
