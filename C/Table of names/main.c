#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nameInTable(char *, char *, char *, int, int);

int main()
{
	char table[10][40], firstName[20], lastName[20];
	int numberOfPeople, sizeOfCell = 40, personNumber;
	do
	{
		printf("Enter the number of people (max 10) : ");
		fflush(stdin);
		scanf("%d", &numberOfPeople);
	}
	while (numberOfPeople < 1 || numberOfPeople > 10);
	printf("\n");
	for (personNumber = 0; personNumber < numberOfPeople; personNumber++)
	{
		printf("Enter the last name of the person %d : ", personNumber + 1);
		fflush(stdin);
		gets(lastName);
		printf("Enter the first name of the person %d : ", personNumber + 1);
		fflush(stdin);
		gets(firstName);
		nameInTable(&table[0][0], lastName, firstName, personNumber, sizeOfCell);
		printf("\n");
	}
	for (personNumber = 0; personNumber < numberOfPeople; personNumber++)
	{
		puts(table[personNumber]);
	}
	return 0;
}

void nameInTable(char* pointerTable, char* lastName, char* firstName, int personNumber, int sizeOfCell)
{
	strcpy(pointerTable + personNumber * sizeOfCell, lastName);
	strcat(pointerTable + personNumber * sizeOfCell, " ");
	strcat(pointerTable + personNumber * sizeOfCell, firstName);
}