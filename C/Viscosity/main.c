#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
	float x;
	float y;
} point;

float coordinateFinder(point coordinates[], char choice);

int main()
{
	point TemperatureAndViscosity[14] = { {15, 1.14}, {16, 1.11}, {17, 1.08}, {18, 1.06}, {19, 1.03}, {20, 1.01}, {21, 0.983}, {22, 0.96}, {23, 0.938}, {24, 0.917}, {25, 0.896}, {26, 0.876}, {27, 0.857}, {28, 0.839} };
	point usefulData[3] = { 0 };
	//do a menu with 5 choices
	//choice 1 give the viscosity at 26.5 degrees
	//choice 2 give the temperature at which the viscosity is 0.9
	//choice 3 give the temperature at a viscosity entered by the user
	//choice 4 give the viscosity at a temperature entered by the user
	//choice 5 exit the program
	int choice = -1, i;
	float temperature = 26.5, viscosity = 0.9;
	do
	{
		printf("\n1) Compute the viscosity at 26.5 degrees\n2) Compute the temperature at which the viscosity is 0.9\n3) Compute the temperature at a custom viscosity\n4) Compute the viscosity at a custom temperature\n5) Exit the program\nEnter your choice : ");
		fflush(stdin);
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				i = 1;
				while (TemperatureAndViscosity[i].x < temperature && i < 13)
				{
					i++;
				}
				usefulData[1] = TemperatureAndViscosity[i - 1];
				usefulData[2] = TemperatureAndViscosity[i];
				usefulData[0].x = temperature;
				printf("The viscosity at %f degrees is %f\n", temperature, coordinateFinder(usefulData, 'y'));
				break;
			case 2:
				i = 13;
				while (TemperatureAndViscosity[i].y < viscosity && i > 1)
				{
					i--;
				}
				usefulData[1] = TemperatureAndViscosity[i + 1];
				usefulData[2] = TemperatureAndViscosity[i];
				usefulData[0].y = viscosity;
				printf("The temperature at which the viscosity is %f is %f degrees\n", viscosity, coordinateFinder(usefulData, 'x'));
				break;
			case 3:
				printf("Enter the viscosity : ");
				fflush(stdin);
				scanf("%f", &viscosity);
				i = 13;
				while (TemperatureAndViscosity[i].y < viscosity && i > 1)
				{
					i--;
				}
				usefulData[1] = TemperatureAndViscosity[i + 1];
				usefulData[2] = TemperatureAndViscosity[i];
				usefulData[0].y = viscosity;
				printf("The temperature at which the viscosity is %f is %f degrees\n", viscosity, coordinateFinder(usefulData, 'x'));
				break;
			case 4:
				printf("Enter the temperature : ");
				fflush(stdin);
				scanf("%f", &temperature);
				i = 1;
				while (TemperatureAndViscosity[i].x < temperature && i < 13)
				{
					i++;
				}
				usefulData[1] = TemperatureAndViscosity[i - 1];
				usefulData[2] = TemperatureAndViscosity[i];
				usefulData[0].x = temperature;
				printf("The viscosity at %f degrees is %f\n", temperature, coordinateFinder(usefulData, 'y'));
				break;
			case 5:
				printf("You chose to exit the program\n");
				break;
			default:
				printf("Enter a valid choice (1-5)\n");
				break;
		}
	}
	while (choice != 5);
	return 0;
}

float coordinateFinder(point coordinates[], char choice)
{
	return choice == 'x' ? (coordinates[0].x = (coordinates[2].x - coordinates[1].x) / (coordinates[2].y - coordinates[1].y) * (coordinates[0].y - coordinates[1].y) + coordinates[1].x) : (coordinates[0].y = (coordinates[2].y - coordinates[1].y) / (coordinates[2].x - coordinates[1].x) * (coordinates[0].x - coordinates[1].x) + coordinates[1].y);
}	