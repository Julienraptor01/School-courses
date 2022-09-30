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
	i = -36;
	j = 25;
	_asm
	{
		mov eax, j
		mov ebx, j
		mov ecx, i
		imul eax, ecx
		imul ecx, 0x12
		sub j, eax
		add j, ebx
		add j, ecx
	}
	printf("\n10.\ni = %d\nj = %d\n", i, j);
	i = -36;
	j = 25;
	_asm
	{
		mov eax, j
		mov ebx, j
		mov ecx, i
		imul eax, 18
		mov j, eax
		imul ebx, ecx
		imul ebx, 178
		add j, ecx
		sub j, ebx
	}
	printf("\n11.\ni = %d\nj = %d\n", i, j);
	i = -36;
	j = 25;
	_asm
	{
		mov eax, j
		mov ebx, i
		mov ecx, i
		imul ebx, 5
		imul ecx, eax
		neg i
		add i, 0x12
		add i, ebx
		sub i, ecx
		sub i, 8
	}
	printf("\n12.\ni = %d\nj = %d\n", i, j);
	i = -36;
	j = 25;
	_asm
	{
		mov eax, j
		mov ebx, j
		mov ecx, i
		mov edx, i
		imul eax, 0x1ab
		imul ecx, 35
		imul edx, edx
		add i, eax
		sub i, ecx
		sub i, ebx
		sub i, 8
		sub i, 0x22
		sub i, edx
		sub i, 5
	}
	printf("\n13.\ni = %d\nj = %d\n", i, j);
	return 0;
}