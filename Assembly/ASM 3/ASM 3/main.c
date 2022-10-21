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
		movzx eax, ub
		movsx ebx, b
		movsx ecx, s
		add eax, ebx
		add eax, ecx
		neg eax
		mov i, eax
	}
	printf("\n1.\ni = %d | s = %hd | b = %hhd\ni1 = %u | s1 = %hu | b1 = %hhu\n", i, s, b, ui, us, ub);
	i = -3, s = 4, b = -2, ui = 8, us = 4, ub = 5;
	_asm
	{
		movzx ebx, ub
		neg ebx
		movzx ecx, ui
		add ebx, ecx
		not ebx
		movsx ecx, b
		not ecx
		mov eax, 0xf1
		imul eax, ecx
		or ebx, eax
		mov s, bx
	}
	printf("\n2.\ni = %d | s = %hd | b = %hhd\ni1 = %u | s1 = %hu | b1 = %hhu\n", i, s, b, ui, us, ub);
	i = -3, s = -1, b = -2, ui = 8, us = 4, ub = 5;
	_asm
	{
		movsx eax, ui
		movsx ebx, ub
		imul eax, ebx
		mov ebx, 2
		movsx ecx, b
		or ebx, ecx
		neg ebx
		cdq
		idiv ebx
		mov b, al
	}
	printf("\n3.\ni = %d | s = %hd | b = %hhd\ni1 = %u | s1 = %hu | b1 = %hhu\n", i, s, b, ui, us, ub);
	return 0;
}
