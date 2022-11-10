#include <stdio.h>
#include <stdlib.h>

int main()
{
	int version;
	do
	{
		printf("Quelle version voulez-vous utiliser ?\nVersion : ");
		scanf("%d", &version);
		printf("\n", version);
	}
	while (version < 1 || version > 2);
	switch (version)
	{
	case 1:
	{
		int scan = -2147483648, previousScan;
		do
		{
			previousScan = scan;
			printf("Entrez un entier plus grand que %d : ", previousScan);
			scanf("%d", &scan);
		}
		while (scan > previousScan);
		break;
	}
	case 2:
	{
		int scan = -2147483648, previousScan;
		do
		{
			previousScan = scan;
			printf("Entrez un entier plus grand que %d : ", previousScan);
			scanf("%d", &scan);
			if (scan <= previousScan)
			{
				previousScan = scan;
				printf("Entrez un entier plus grand que %d : ", previousScan);
				scanf("%d", &scan);
			}
		}
		while (scan > previousScan);
		break;
	}
	}
	return 0;
}
