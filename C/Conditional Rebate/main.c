#include <stdio.h>
#include <stdlib.h>

int main()
{
	int purchaseAmount, numberOfKids;
	float rebatePercentage, payementAmount;
	printf("Entrez le montant des achats\n");
	scanf("%d", &purchaseAmount);
	printf("Entrez le nombre d'enfants\n");
	scanf("%d", &numberOfKids);
	if ((purchaseAmount >= 10 && numberOfKids >= 3) || purchaseAmount >= 25)
	{
		rebatePercentage = 0.10;
	}
	else
	{
		rebatePercentage = 0.05;
	}
	payementAmount = purchaseAmount - (purchaseAmount * rebatePercentage);
	printf("Le montant a payer est de %.2f\n", payementAmount);
	return 0;
}
