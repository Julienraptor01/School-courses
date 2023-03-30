#include <stdio.h>

typedef struct point
{
	int x;
	int y;
} point;

int coordinateFinder(point coordinates[], char choice);

int main()
{
	point coordinates[3] = { 0 };
	for (int i = 1; i < 3; i++)
	{
		printf("Enter the x coordinate of point %d : ", i);
		fflush(stdin);
		scanf("%d", &coordinates[i].x);
		printf("Enter the y coordinate of point %d : ", i);
		fflush(stdin);
		scanf("%d", &coordinates[i].y);
	}
	char choice;
	do
	{
		printf("Enter x to find the x coordinate of the point and y to find the y coordinate of the point : ");
		fflush(stdin);
		scanf("%c", &choice);
	}
	while (choice != 'x' && choice != 'y');
	printf("Enter the %c coordinate of the point : ", choice == 'x' ? 'y' : 'x');
	fflush(stdin);
	scanf("%d", choice == 'x' ? &coordinates[0].y : &coordinates[0].x);
	printf("The %c coordinate of the point is %d", choice, coordinateFinder(coordinates, choice));
	return 0;
}

int coordinateFinder(point coordinates[], char choice)
{
	return choice == 'x' ? (coordinates[0].x = (coordinates[2].x - coordinates[1].x) / (coordinates[2].y - coordinates[1].y) * (coordinates[0].y - coordinates[1].y) + coordinates[1].x) : (coordinates[0].y = (coordinates[2].y - coordinates[1].y) / (coordinates[2].x - coordinates[1].x) * (coordinates[0].x - coordinates[1].x) + coordinates[1].y);
}
