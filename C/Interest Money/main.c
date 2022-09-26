#include <stdio.h>
#include <stdlib.h>

int main()
{
	int capital, interest;
	float profit, capital1Year;
	printf("Quel est votre capital ?\n");
	scanf("%d", &capital);
	printf("Quel est votre taux d'interet ?\n");
	scanf("%d", &interest);
	profit = capital * interest / 100.0;
	printf("Votre profit est de %.2f\n", profit);
	capital1Year = capital + profit;
	printf("Votre capital acquis est de %.2f\n", capital1Year);
	return 0;
}
