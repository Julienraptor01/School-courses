#include <stdio.h>

#define lines 10
#define columns 3
#define defaultUsedLines 4
#define defaultDates 5,2,1976,1,8,1970,9,1,1970,3,2,1974

/*
int main()
{
	int calendar[lines][columns] = {defaultDates}, tmp[columns], numberOfLinesUsed = {defaultUsedLines};
	int i, j, k, l;
	//tell people to enter the number of lines they are going to use
	printf("Enter the number of lines you are going to use : ");
	scanf("%d", &numberOfLinesUsed);
	//tell them to enter dates in DD/MM/YYYY format
	//scan date in DD/MM/YYYY format
	for (j = 0; j < numberOfLinesUsed; j++)
	{

		printf("Enter date %d in DD/MM/YYYY format : ", j + 1);
		scanf("%d/%d/%d", &calendar[j][0], &calendar[j][1], &calendar[j][2]);
	}
	*/
	/*
	//sort the dates by day 1st
	for (j = 0; j < numberOfLinesUsed; j++)
	{
		//use a for loop to move the line in tmp
		for (i = 0; i < 3; i++)
		{
			tmp[i] = calendar[j][i];
		}
		i = j - 1;
		//use a while loop to move the line in calendar
		while (i >= 0 && calendar[i][0] > tmp[0])
		{
			for (l = 0; l < 3; l++)
			{
				calendar[i + 1][l] = calendar[i][l];
			}
			i--;
		}
		//use a for loop to move the line in calendar
		for (l = 0; l < 3; l++)
		{
			calendar[i + 1][l] = tmp[l];
		}
	}
	//sort the dates by month 2nd
	for (j = 0; j < numberOfLinesUsed; j++)
	{
		//use a for loop to move the line in tmp
		for (i = 0; i < 3; i++)
		{
			tmp[i] = calendar[j][i];
		}
		i = j - 1;
		//use a while loop to move the line in calendar
		while (i >= 0 && calendar[i][1] > tmp[1])
		{
			for (l = 0; l < 3; l++)
			{
				calendar[i + 1][l] = calendar[i][l];
			}
			i--;
		}
		//use a for loop to move the line in calendar
		for (l = 0; l < 3; l++)
		{
			calendar[i + 1][l] = tmp[l];
		}
	}
	//sort the dates by year 3rd
	for (j = 0; j < numberOfLinesUsed; j++)
	{
		//use a for loop to move the line in tmp
		for (i = 0; i < 3; i++)
		{
			tmp[i] = calendar[j][i];
		}
		i = j - 1;
		//use a while loop to move the line in calendar
		while (i >= 0 && calendar[i][2] > tmp[2])
		{
			for (l = 0; l < 3; l++)
			{
				calendar[i + 1][l] = calendar[i][l];
			}
			i--;
		}
		//use a for loop to move the line in calendar
		for (l = 0; l < 3; l++)
		{
			calendar[i + 1][l] = tmp[l];
		}
	}
	*/
	//rework the commented logic with a for loop
	/*for (k = 0; k < 3; k++)
	{
		for (j = 0; j < numberOfLinesUsed; j++)
		{
			//use a for loop to move the line in tmp
			for (i = 0; i < 3; i++)
			{
				tmp[i] = calendar[j][i];
			}
			i = j - 1;
			//use a while loop to move the line in calendar
			while (i >= 0 && calendar[i][k] > tmp[k])
			{
				for (l = 0; l < 3; l++)
				{
					calendar[i + 1][l] = calendar[i][l];
				}
				i--;
			}
			//use a for loop to move the line in calendar
			for (l = 0; l < 3; l++)
			{
				calendar[i + 1][l] = tmp[l];
			}
		}
	}
	//print the sorted dates
	printf("Sorted dates :\n");
	for (j = 0; j < numberOfLinesUsed; j++)
	{
		printf("%d/%d/%d\n", calendar[j][0], calendar[j][1], calendar[j][2]);
	}
	return 0;
}
*/
//rework the whole thing to use a function to sort
//use pointers to pass the array to the function
/*
void sort(int calendar[][3], int numberOfLinesUsed, int columnNumber);

int main()
{
	int calendar[lines][columns] = { defaultDates }, numberOfLinesUsed = { defaultUsedLines }, columnNumber;
	int i;
	//tell people to enter the number of lines they are going to use
	printf("Enter the number of lines you are going to use : ");
	scanf("%d", &numberOfLinesUsed);
	//tell them to enter dates in DD/MM/YYYY format
	//scan date in DD/MM/YYYY format
	for (i = 0; i < numberOfLinesUsed; i++)
	{

		printf("Enter date %d in DD/MM/YYYY format : ", i + 1);
		scanf("%d/%d/%d", &calendar[i][0], &calendar[i][1], &calendar[i][2]);
	}
	//use a for loop with column number
	for (columnNumber = 0; columnNumber < 3; columnNumber++)
	{
		sort(&calendar[0], numberOfLinesUsed, columnNumber);
		//display the sorted dates and say by what they are sorted
		//use a switch statement to do so
		switch (columnNumber)
		{
		case 0:
			printf("Sorted by day :\n");
			break;
		case 1:
			printf("Sorted by month :\n");
			break;
		case 2:
			printf("Sorted by year :\n");
			break;
		}
		for (i = 0; i < numberOfLinesUsed; i++)
		{
			printf("%d/%d/%d\n", calendar[i][0], calendar[i][1], calendar[i][2]);
		}
	}
	//print the sorted dates
	printf("Final sorted dates :\n");
	for (i = 0; i < numberOfLinesUsed; i++)
	{
		printf("%d/%d/%d\n", calendar[i][0], calendar[i][1], calendar[i][2]);
	}
	return 0;
}

void sort(int calendar[][3], int numberOfLinesUsed, int columnNumber)
{
	int i, j, k, tmp[3];
	//sort the dates
	for (j = 0; j < numberOfLinesUsed; j++)
	{
		//use a for loop to move the line in tmp
		for (i = 0; i < 3; i++)
		{
			tmp[i] = calendar[j][i];
		}
		i = j - 1;
		//use a while loop to move the line in calendar
		while (i >= 0 && calendar[i][columnNumber] > tmp[columnNumber])
		{
			for (k = 0; k < 3; k++)
			{
				calendar[i + 1][k] = calendar[i][k];
			}
			i--;
		}
		//use a for loop to move the line in calendar
		for (k = 0; k < 3; k++)
		{
			calendar[i + 1][k] = tmp[k];
		}
	}
}
*/
//same thing but now use a function to display and a function to scan and order them by scan then display then sort

void read(int [][3], int);

void display(int [][3], int, int);

void sort(int [][3], int, int);

int main()
{
	int calendar[lines][columns] = { defaultDates }, numberOfLinesUsed = { defaultUsedLines }, columnNumber;
	//tell people to enter the number of lines they are going to use
	printf("Enter the number of lines you are going to use : ");
	scanf("%d", &numberOfLinesUsed);
	//tell them to enter dates in DD/MM/YYYY format
	//scan date in DD/MM/YYYY format
	read(&calendar[0], numberOfLinesUsed);
	//use a for loop with column number
	for (columnNumber = 0; columnNumber < 3; columnNumber++)
	{
		sort(&calendar[0], numberOfLinesUsed, columnNumber);
		//display the sorted dates and say by what they are sorted
		//use a switch statement to do so
		display(&calendar[0], numberOfLinesUsed, columnNumber);
	}
	//print the sorted dates
	printf("Final sorted dates :\n");
	display(&calendar[0], numberOfLinesUsed, columnNumber);
	return 0;
}

void read(int calendar[][3], int numberOfLinesUsed)
{
	int i;
	for (i = 0; i < numberOfLinesUsed; i++)
	{
		printf("Enter date %d in DD/MM/YYYY format : ", i + 1);
		scanf("%d/%d/%d", &calendar[i][0], &calendar[i][1], &calendar[i][2]);
	}
}

void display(int calendar[][3], int numberOfLinesUsed, int columnNumber)
{
	int i;
	//use a switch statement to do so
	switch (columnNumber)
	{
	case 0:
		printf("Sorted by day :\n");
		break;
	case 1:
		printf("Sorted by month :\n");
		break;
	case 2:
		printf("Sorted by year :\n");
		break;
	}
	for (i = 0; i < numberOfLinesUsed; i++)
	{
		//printf("%2d/%2d/%4d\n", calendar[i][0], calendar[i][1], calendar[i][2]);
		//same thing but instead of filling with space, fill with 0
		printf("%02d/%02d/%04d\n", calendar[i][0], calendar[i][1], calendar[i][2]);
	}
}

void sort(int calendar[][3], int numberOfLinesUsed, int columnNumber)
{
	int i, j, k, tmp[3];
	//sort the dates
	for (j = 0; j < numberOfLinesUsed; j++)
	{
		//use a for loop to move the line in tmp
		for (i = 0; i < 3; i++)
		{
			tmp[i] = calendar[j][i];
		}
		i = j - 1;
		//use a while loop to move the line in calendar
		while (i >= 0 && calendar[i][columnNumber] > tmp[columnNumber])
		{
			for (k = 0; k < 3; k++)
			{
				calendar[i + 1][k] = calendar[i][k];
			}
			i--;
		}
		//use a for loop to move the line in calendar
		for (k = 0; k < 3; k++)
		{
			calendar[i + 1][k] = tmp[k];
		}
	}
}