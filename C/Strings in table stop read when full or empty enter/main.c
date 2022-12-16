#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read(char *, int, int);

int main()
{
	char table[5][20], numberOfLines = 5, sizeOfLines = 20;
	//print the returned value of read function
	printf("Number of lines read : %d", read(&table[0][0], numberOfLines, sizeOfLines));
	return 0;
}

int read(char *table, int numberOfLines, int sizeOfLines)
{
    int counter = 0;
    while (counter < numberOfLines)
    {
        printf("Enter a string : ");
        fflush(stdin);
        gets(table + counter * sizeOfLines);
        if (strlen(table + counter * sizeOfLines) == 0)
        {
            return counter;
        }
        counter++;
    }
    return counter;
}
