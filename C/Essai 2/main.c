#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1=420,num2=69, sum, diff, prod, quot, rem;
	printf("\nEntrez le premier nombre\n");
	scanf("%d", &num1);
	printf("\nEntrez le deuxieme nombre\n");
	scanf("%d", &num2);
	sum = num1 + num2;
	printf("\nLa somme vaut %d\n", sum);
	diff = num1 - num2;
	printf("\nLa difference vaut %d\n", diff);
	prod = num1 * num2;
	printf("\nLe produit vaut %d\n", prod);
	quot = num1 / num2;
	printf("\nLe quotient vaut %d\n", quot);
	rem = num1 % num2;
	printf("\nLe reste vaut %d\n", rem);
	return 0;
}
