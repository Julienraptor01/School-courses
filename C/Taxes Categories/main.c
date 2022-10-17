#include <stdio.h>
#include <stdlib.h>

int main()
{
	int productPrice, purchasedQuantity, productCategory;
	float taxValue, totalPrice;
	printf("Entrez le prix du produit\n");
	scanf("%d", &productPrice);
	printf("Entrez la quantite achetee\n");
	scanf("%d", &purchasedQuantity);
	printf("Entrez la categorie du produit\n");
	scanf("%d", &productCategory);
	switch (productCategory)
	{
	case 1:
		taxValue = 0.06;
		break;
	case 2:
		taxValue = 0.09;
		break;
	case 3:
		taxValue = 0.25;
		break;
	case 4:
		taxValue = 0.30;
		break;
	default:
		taxValue = 0;
		break;
	}
	totalPrice = productPrice * purchasedQuantity * (1 + taxValue);
	printf("Le prix total est de %.2f", totalPrice);
	return 0;
}
