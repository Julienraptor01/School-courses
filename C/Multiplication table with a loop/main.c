#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("  *||");
	for (int j = 1; j <= 10; j++)
	{
		printf("%4d|", j);
	}
	printf("\n");
	printf("---++");
	for (int i = 1; i <= 10; i++)
	{
		printf("----+");
	}
	printf("\n");
	for (int i = 1; i <= 10; i++)
	{
		printf("%3d||", i);
		for (int j = 1; j <= 10; j++)
		{
			printf("%4d|", i * j);
		}
		printf("\n");
	}
	return 0;
}
