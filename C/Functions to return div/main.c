#include <stdio.h>
#include <stdlib.h>

int intDivide(int, int);
float floatDivide(int, int);
void pointerFloatDivide(int, int, float *);

int main()
{
	int a, b, c;
	float d, e;
	printf("Entrez le premier nombre : ");
	scanf("%d", &a);
	printf("Entrez le deuxieme nombre : ");
	scanf("%d", &b);
	c = intDivide(a, b);
	d = floatDivide(a, b);
	pointerFloatDivide(a, b, &e);
	printf("Le resultat de la division entiere de %d par %d est %d\n", a, b, c);
	printf("Le resultat de la division flottante de %d par %d est %f\n", a, b, d);
	printf("Le resultat de la division flottante de %d par %d est %f\n", a, b, e);
	return 0;
}

int intDivide(int a, int b)
{
	return a / b;
}

float floatDivide(int a, int b)
{
	return a / (float)b;
}

void pointerFloatDivide(int a, int b, float *pE)
{
	*pE = a / (float)b;
}