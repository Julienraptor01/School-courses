#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[10], str2[10], str3[20], str4[22];
	printf("Enter the first string : ");
	gets(str1);
	printf("Enter the second string : ");
	gets(str2);
	strcpy(str3, str1);
	strcat(str3, " ");
	strcpy(&str3[strlen(str3)], str2);
	//we want to print the string in %c and then in %d char by char
	//we also need to print the existing \0
	for (int i = 0; i < strlen(str3) + 1; i++)
	{
		printf("%c %d ", str3[i], str3[i]);
		printf("\n");
	}
	printf("\n");
	strcpy(str4, str1);
	//i need to copy a space in between the two strings but keep it itself enclosed by \0
	//so i need to have str1 + \0 + space + \0 + str2 + \0
	str4[strlen(str4) + 1] = ' ';
	strcpy(&str4[strlen(str4) + 3], str2);
	for (int i = 0; i < strlen(str1) + 1; i++)
	{
		printf("%c %d ", str4[i], str4[i]);
		printf("\n");
	}
	for (int i = strlen(str1) + 1; i < strlen(str1) + 3; i++)
	{
		printf("%c %d ", str4[i], str4[i]);
		printf("\n");
	}
	for (int i = strlen(str1) + 3; i < strlen(str1) + 3 + strlen(str2) + 1; i++)
	{
		printf("%c %d ", str4[i], str4[i]);
		printf("\n");
	}
	return 0;
}
