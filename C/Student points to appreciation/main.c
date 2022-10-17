#include <stdio.h>
#include <stdlib.h>

int main()
{
	int points, appreciation;
	printf("Entrez les points\n");
	scanf("%d", &points);
	if (points >= 0 && points <= 100)
	{
		switch (points / 10)
		{
		case 6:
			printf("A ameliorer\n");
			break;
		case 7:
			printf("Bien\n");
			break;
		case 8:
			printf("Tres bien\n");
			break;
		case 9:
		case 10:
			printf("Bravo\n");
			break;
		default:
			printf("Insuffisant\n");
			break;
		}
	}
	else
	{
		printf("Les points doivent etre 0 inclus et 100 inclus\n");
	}
	return 0;
}
