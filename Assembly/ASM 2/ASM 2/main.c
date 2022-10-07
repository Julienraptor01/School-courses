#include <stdio.h>

int main()

{
	char b = 25;
	short s = 40;
	int i = -110;
	_asm
	{
		movsx eax, s
		mov i, eax
		neg i
		add i, 2
	}
	printf("\n1.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	b = 25, s = 40, i = -110;
	_asm
	{
		movsx eax, b
		movsx ebx, s
		add i, eax
		add i, ebx
	}
	printf("\n2.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	b = 25, s = 40, i = -110;
	_asm
	{
		movsx eax, b
		movsx ebx, s
		mov ecx, i
		imul eax, ecx
		imul ebx, ecx
		mov i, eax
		add i, ebx
	}
	printf("\n3.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	b = 25, s = 40, i = -110;
	_asm
	{
		/*
		movsx eax, b
		movsx ebx, s
		mov ecx, i
		mov edx, i
		add eax, ebx
		neg ecx
		imul ecx, eax
		imul ecx, edx
		mov i, ecx
		*/
		//alternative version which yield the same result but is faster and shorter (less instructions) than the above version (which is commented out)
		movsx eax, b
		movsx ebx, s
		mov ecx, i
		add eax, ebx
		neg eax
		imul eax, ecx
		imul eax, ecx
		mov i, eax
	}
	printf("\n4.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	b = 25, s = 40, i = -110;
	_asm
	{
		movsx eax, b
		movsx ebx, s
		add eax, i
		add ebx, i
		neg ebx
		imul eax, ebx
		mov i, eax
	}
	printf("\n5.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	b = 25, s = 40, i = -110;
	_asm
	{
		mov eax, i
		movsx ebx, s
		neg ebx
		cdq
		idiv ebx
		mov i, eax
	}
	printf("\n6.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	b = 25, s = 40, i = -110;
	_asm
	{
		mov eax, i
		movsx ebx, s
		mov ecx, 31
		sub eax, ebx
		cdq
		idiv ecx
		mov i, edx
	}
	printf("\n7.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	b = 25, s = 40, i = -110;
	_asm
	{
		mov eax, i
		movsx ebx, b
		imul eax, ebx
		imul ebx, 2
		neg ebx
		cdq
		idiv ebx
		mov i, eax
	}
	printf("\n8.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	b = 25, s = 40, i = -110;
	_asm
	{
		movsx eax, b
		movsx ebx, s
		mov ecx, i
		mov edi, 5
		mov esi, 2
		add eax, 0x12
		sub eax, i
		neg eax
		cdq
		idiv edi
		mov edi, eax
		imul ecx, ebx
		mov eax, ecx
		cdq
		idiv esi
		sub edi, eax
		mov i, edi
	}
	printf("\n9.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	b = 25, s = 40, i = -110;
	_asm
	{
		mov eax, i
		movsx ebx, s
		movsx ecx, b
		neg ebx
		imul ebx, 18
		cdq
		idiv ecx
		add ebx, i
		sub ebx, edx
		mov s, bx
	}
	printf("\n10.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	b = 25, s = 40, i = -110;
	_asm
	{
		movsx eax, s
		movsx ebx, b
		mov ecx, i
		mov edi, i
		mov esi, 3
		cdq
		idiv esi
		imul ecx, eax
		mov eax, 800
		neg edi
		cdq
		idiv edi
		add ecx, eax
		sub ecx, ebx
		mov s, cx
	}
	printf("\n11.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	b = 25, s = 40, i = -110;
	_asm
	{
		movsx eax, b
		mov ebx, 10
		mov ecx, 3
		cdq
		idiv ebx
		mov ebx, edx
		movsx eax, s
		cdq
		idiv ecx
		neg ebx
		imul ebx, 0xff
		add ebx, eax
		mov s, bx
	}
	printf("\n12.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	b = 25, s = 40, i = -110;
	_asm
	{
		movsx eax, s
		movsx ebx, s
		movsx ecx, b
		mov edi, 3
		cdq
		idiv edi
		imul ecx, eax
		imul ebx, 0xffe1
		neg ebx
		mov eax, ebx
		cdq
		idiv ecx
		mov i, eax
	}
	printf("\n13.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	b = 25, s = 40, i = -110;
	_asm
	{
		movsx eax, s
		movsx ebx, s
		movsx ecx, b
		mov edi, 3
		mov esi, 2
		cdq
		idiv edi
		sub edi, i
		neg eax
		imul ecx, eax
		add ecx, edi
		imul ebx, 0xffe1
		mov eax, ebx
		cdq
		idiv ecx
		cdq
		idiv esi
		mov i, eax
	}
	printf("\n14.\nb = %hhd\ns = %hd\ni = %d\n", b, s, i);
	return 0;
}