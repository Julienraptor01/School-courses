#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number, i, arithmeticProgression, smallGauss;
	do
	{
		printf("Enter a number between 1 excluded and 100 excluded : ");
		scanf("%d", &number);
	}
	while (number <= 1 || number >= 100);
	arithmeticProgression = 0;
	printf("\nThe arithmetic progression is :\n");
	for (i = 1; i <= number; i++)
	{
		arithmeticProgression += i;
		printf("%d, %d\n", i, arithmeticProgression);
	}
	smallGauss = (number * (number + 1)) / 2;
	printf("\nVerification : %d * (%d + 1) / 2 = %d\n", number, number, smallGauss);
	return 0;
}
