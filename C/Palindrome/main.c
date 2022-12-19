#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testPalindrome(char *);

int main()
{
	char v[20];
	printf("Entrez une chaine de caractere : ");
	fflush(stdin);
	gets(v);
	if (testPalindrome(v))
		printf("La chaine est un palindrome\n");
	return 0;
}

int testPalindrome(char *v)
{
	int i = 0;
	while (i < strlen(v) / 2 && *(v + i) == *(v + strlen(v) - 1 - i))
		i++;
	return (i == strlen(v) / 2);
}