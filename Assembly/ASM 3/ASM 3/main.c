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
	i = -3, s = 4, b = -2, ui = 8, us = 4, ub = 5;
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
	i = -3, s = 4, b = -2, ui = 8, us = 4, ub = 5;
	_asm
	{
		movzx eax, b
		movsx ebx, us
		add eax, ebx
		mov ebx, i
		neg ebx
		sub ebx, 3
		add ebx, eax
		mov us, bx
	}
	printf("\n4.\ni = %d | s = %hd | b = %hhd\ni1 = %u | s1 = %hu | b1 = %hhu\n", i, s, b, ui, us, ub);
	i = -3, s = 4, b = -2, ui = 8, us = 4, ub = 5;
	_asm
	{
		mov eax, i
		mov ebx, 6
		imul eax, ebx
		movzx ebx, us
		sub eax, ebx
		mov ebx, 0xff
		movsx ecx, s
		add ebx, ecx
		movzx ecx, ub
		add ebx, ecx
		mov ecx, 3
		add eax, ecx
		sub eax, ebx
		mov us, ax
	}
	printf("\n5.\ni = %d | s = %hd | b = %hhd\ni1 = %u | s1 = %hu | b1 = %hhu\n", i, s, b, ui, us, ub);
	i = -3, s = 4, b = -2, ui = 8, us = 4, ub = 5;
	_asm
	{
		mov eax, 3
		movsx ebx, b
		and eax, ebx
		mov ebx, ui
		sub ebx, eax
		movsx eax, s
		sub ebx, eax
		mov i, ebx
	}
	printf("\n6.\ni = %d | s = %hd | b = %hhd\ni1 = %u | s1 = %hu | b1 = %hhu\n", i, s, b, ui, us, ub);
	i = -3, s = 4, b = -2, ui = 8, us = 4, ub = 5;
	_asm
	{
		movzx eax, b
		movsx ebx, us
		mov ecx, i
		neg ecx
		mov edx, 3
		sub ecx, edx
		add ecx, eax
		xor ecx, ebx
		mov s, cx
	}
	printf("\n7.\ni = %d | s = %hd | b = %hhd\ni1 = %u | s1 = %hu | b1 = %hhu\n", i, s, b, ui, us, ub);
	i = -3, s = 4, b = -2, ui = 8, us = 4, ub = 5;
	_asm
	{
		mov eax, i
		mov ebx, 6
		imul eax, ebx
		movzx ebx, us
		or eax, ebx
		neg eax
		movsx ebx, b
		not ebx
		mov ecx, 3
		add eax, ebx
		add eax, ecx
		mov s, ax
	}
	printf("\n8.\ni = %d | s = %hd | b = %hhd\ni1 = %u | s1 = %hu | b1 = %hhu\n", i, s, b, ui, us, ub);
	i = -3, s = 4, b = -2, ui = 8, us = 4, ub = 5;
	_asm
	{
		movsx eax, ub
		movsx ebx, us
		imul eax, ebx
		mov ebx, i
		imul eax, ebx
		mov ecx, 8
		sub ebx, ecx
		or eax, ebx
		mov b, al
	}
	printf("\n9.\ni = %d | s = %hd | b = %hhd\ni1 = %u | s1 = %hu | b1 = %hhu\n", i, s, b, ui, us, ub);
	i = -3, s = 4, b = -2, ui = 8, us = 4, ub = 5;
	_asm
	{
		mov eax, ui
		neg eax
		movzx ebx, ub
		not ebx
		movzx ecx, b
		mov edi, 2
		cdq
		idiv edi
		mov edx, 255
		sub edx, ebx
		xor eax, edx
		or eax, ecx
		mov i, eax
	}
	printf("\n10.\ni = %d | s = %hd | b = %hhd\ni1 = %u | s1 = %hu | b1 = %hhu\n", i, s, b, ui, us, ub);
	return 0;
}