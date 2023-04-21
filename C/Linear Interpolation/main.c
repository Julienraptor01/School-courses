#include <stdio.h>

typedef struct point
{
	float x;
	float y;
} point;

float coordinateFinder(point *coordinates, char choice, float a, float b, float c);

int main()
{
	float a, b, c;
	point coordinates = { 0 };
	//ask for the a b and c values of the line
	printf("Enter the a value of the line : ");
	fflush(stdin);
	scanf("%f", &a);
	printf("Enter the b value of the line : ");
	fflush(stdin);
	scanf("%f", &b);
	printf("Enter the c value of the line : ");
	fflush(stdin);
	scanf("%f", &c);
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
	scanf("%f", choice == 'x' ? &coordinates.y : &coordinates.x);
	printf("The %c coordinate of the point is %f", choice, coordinateFinder(&coordinates, choice, a, b, c));
	return 0;
}

float coordinateFinder(point *coordinates, char choice, float a, float b, float c)
{
	return choice == 'x' ? (coordinates->x = -(b * coordinates->y + c) / a) : (coordinates->y = -(a * coordinates->x + c) / b);
}