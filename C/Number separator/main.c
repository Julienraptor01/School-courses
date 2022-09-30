#include <stdio.h>
#include <stdlib.h>

int main()
{
	short number, m, c, d, u, mOffset, cOffset, dOffset, uOffset, mReverseOffset, cReverseOffset, dReverseOffset, uReverseOffset;
	printf("Entrez un nombre entre 0 et 9999\n");
	scanf("%hd", &number);
	m = number / 1000;
	c = (number % 1000) / 100;
	d = (number % 100) / 10;
	u = number % 10;
	printf("---------------------\n");
	printf("Il y a %hd millers, %hd centaines, %hd dizaines et %hd unites dans %hd\n", m, c, d, u, number);
	mReverseOffset = (10 - m) * 2;
	cReverseOffset = (10 - c) * 2;
	dReverseOffset = (10 - d) * 2;
	uReverseOffset = (10 - u) * 2;
	printf("---------------------\n");
	printf("  9 8 7 6 5 4 3 2 1 0\n");
	printf("m%*c\n", mReverseOffset, '+');
	printf("c%*c\n", cReverseOffset, '+');
	printf("d%*c\n", dReverseOffset, '+');
	printf("u%*c\n", uReverseOffset, '+');
	printf("---------------------\n");
	mOffset = (m + 1) * 2;
	cOffset = (c + 1) * 2;
	dOffset = (d + 1) * 2;
	uOffset = (u + 1) * 2;
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	printf("m%*c\n", mOffset, '+');
	printf("c%*c\n", cOffset, '+');
	printf("d%*c\n", dOffset, '+');
	printf("u%*c\n", uOffset, '+');
	return 0;
}
