#include <stdio.h>

int main()
{
	int i = -36, j = 25;
	_asm
	{
		mov i, 143
	}
	printf("\n1.\ni = %d\nj = %d\n", i, j);
	i = -36;
	j = 25;
	_asm
	{
		mov eax, j
		mov i, eax
	}
	printf("\n2.\ni = %d\nj = %d\n", i, j);
	i = -36;
	j = 25;
	_asm
	{
		mov eax, j
		add i, eax
	}
	printf("\n3.\ni = %d\nj = %d\n", i, j);
	i = -36;
	j = 25;
	_asm
	{
		mov eax, j
		add i, eax
		sub i, 8
	}
	printf("\n4.\ni = %d\nj = %d\n", i, j);
	i = -36;
	j = 25;
	_asm
	{
		mov eax, j
		sub i, eax
		add i, 8
	}
	printf("\n5.\ni = %d\nj = %d\n", i, j);
	i = -36;
	j = 25;
	_asm
	{
		mov eax, j
		imul eax, 8
		add i, eax
	}
	printf("\n6.\ni = %d\nj = %d\n", i, j);
	i = -36;
	j = 25;
	_asm
	{
		mov eax, j
		mov ebx, i
		imul ebx, eax
		mov i, ebx
		add i, 8
	}
	printf("\n7.\ni = %d\nj = %d\n", i, j);
	i = -36;
	j = 25;
	_asm
	{
		mov eax, j
		mov ebx, i
		imul ebx, eax
		mov i, ebx
		//the 2 following lines purpose is to do 2-i
		neg i
		add i, 2
		add i, 8
	}
	printf("\n8.\ni = %d\nj = %d\n", i, j);
	i = -36;
	j = 25;
	_asm
	{
		mov eax, j
		mov ebx, i
		mov ecx, i
		imul eax, 0x12
		imul ebx, 5
		mov i, ebx
		add i, eax
		add i, ecx
		add i, 9
	}
	printf("\n9.\ni = %d\nj = %d\n", i, j);
	return 0;
}