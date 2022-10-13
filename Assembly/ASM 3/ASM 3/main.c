#include <stdio.h>

int main()

{
	int i = -3;
	short s = 4;
	char b = -2;
	unsigned int ui = 8;
	unsigned short us = 4;
	unsigned char ub = 5;
	_asm
	{
		
	}
	printf("\n1.\ni = %d\ns = %hd\nb = %hhd\nui = %u\nus = %hu\nub = %hhu\n", i, s, b, ui, us, ub);
	return 0;
}
