//this is the 1st assignment
/*
#include <stdio.h>

int main()
{
	int i = -36, j = 25;
	_asm
	{
		mov i, 143
	}
	printf("\n1.\ni = %d\nj = %d\n", i, j);
	i = -36, j = 25;
	_asm
	{
		mov eax, j
		mov i, eax
	}
	printf("\n2.\ni = %d\nj = %d\n", i, j);
	i = -36, j = 25;
	_asm
	{
		mov eax, j
		add i, eax
	}
	printf("\n3.\ni = %d\nj = %d\n", i, j);
	i = -36, j = 25;
	_asm
	{
		mov eax, j
		add i, eax
		sub i, 8
	}
	printf("\n4.\ni = %d\nj = %d\n", i, j);
	i = -36, j = 25;
	_asm
	{
		mov eax, j
		sub i, eax
		add i, 8
	}
	printf("\n5.\ni = %d\nj = %d\n", i, j);
	i = -36, j = 25;
	_asm
	{
		mov eax, j
		imul eax, 8
		add i, eax
	}
	printf("\n6.\ni = %d\nj = %d\n", i, j);
	i = -36, j = 25;
	_asm
	{
		mov eax, j
		mov ebx, i
		imul ebx, eax
		mov i, ebx
		add i, 8
	}
	printf("\n7.\ni = %d\nj = %d\n", i, j);
	i = -36, j = 25;
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
	i = -36, j = 25;
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
	i = -36, j = 25;
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
	i = -36, j = 25;
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
	i = -36, j = 25;
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
	i = -36, j = 25;
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
*/

//this is the 2nd assignment
/*
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
		\/\*
		movsx eax, b
		movsx ebx, s
		mov ecx, i
		mov edx, i
		add eax, ebx
		neg ecx
		imul ecx, eax
		imul ecx, edx
		mov i, ecx
		\*\/
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
*/

//this is the 3rd assignment
/*
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
*/

//this is the 4th assignment
/*
#include <stdio.h>

int main()
{
	char b = 40;
	int i = 20;
	int j = -125;
	float f = 2.7;
	const float cf281 = 2.81, cf35 = 3.5;
	const float cfneg = -1;
	_asm
	{
		movss xmm0, f
		cvttss2si eax, xmm0
		mov b, al
	}
	printf("\n1.\nb = %hhd | i = %d | j = %d | f = %f\n", b, i, j, f);
	b = 40, i = 20, j = -125, f = 2.7;
	_asm
	{
		movss xmm0, cf281
		cvttss2si eax, xmm0
		mov ebx, i
		add eax, ebx
		cvtsi2ss xmm0, eax
		movss f, xmm0
	}
	printf("\n2.\nb = %hhd | i = %d | j = %d | f = %f\n", b, i, j, f);
	b = 40, i = 20, j = -125, f = 2.7;
	_asm
	{
		movss xmm0, f
		cvttss2si eax, xmm0
		not eax
		mov ebx, j
		add ebx, eax
		mov i, ebx
	}
	printf("\n3.\nb = %hhd | i = %d | j = %d | f = %f\n", b, i, j, f);
	b = 40, i = 20, j = -125, f = 2.7;
	_asm
	{
		movss xmm0, f
		movss xmm1, cfneg
		mulss xmm0, xmm1
		mov eax, j
		mov ebx, 2
		cdq
		idiv ebx
		movss xmm1, cf35
		cvtsi2ss xmm2, ebx
		divss xmm1, xmm2
		cvtsi2ss xmm2, eax
		addss xmm2, xmm0
		addss xmm2, xmm1
		cvttss2si eax, xmm2
		mov b, al
	}
	printf("\n4.\nb = %hhd | i = %d | j = %d | f = %f\n", b, i, j, f);
	b = 40, i = 20, j = -125, f = 2.7;
	_asm
	{
		mov eax, j
		mov ebx, 0xfff
		xor eax, ebx
		not eax
		movss xmm0, f
		cvttss2si ebx, xmm0
		neg ebx
		add eax, ebx
		movss xmm0, cf35
		cvtsi2ss xmm1, eax
		addss xmm1, xmm0
		cvttss2si eax, xmm1
		mov j, eax
	}
	printf("\n5.\nb = %hhd | i = %d | j = %d | f = %f\n", b, i, j, f);
	b = 40, i = 20, j = -125, f = 2.7;
	_asm
	{
		mov eax, i
		cvtsi2ss xmm0, eax
		mov ebx, j
		cvtsi2ss xmm1, ebx
		mulss xmm0, xmm1
		cvttss2si eax, xmm0
		mov i, eax
	}
	printf("\n6.\nb = %hhd | i = %d | j = %d | f = %f\n", b, i, j, f);
	b = 40, i = 20, j = -125, f = 2.7;
	_asm
	{
		mov eax, i
		mov ebx, 2
		imul ebx
		mov ebx, 5
		movsx ecx, b
		imul ebx, ecx
		movss xmm0, f
		cvtsi2ss xmm1, eax
		addss xmm1, xmm0
		cvtsi2ss xmm0, ebx
		subss xmm1, xmm0
		cvttss2si eax, xmm1
		mov i, eax
	}
	printf("\n7.\nb = %hhd | i = %d | j = %d | f = %f\n", b, i, j, f);
	b = 40, i = 20, j = -125, f = 2.7;
	_asm
	{
		movss xmm0, f
		mov eax, 100
		cvtsi2ss xmm1, eax
		mulss xmm0, xmm1
		movsx eax, b
		mov ebx, 20
		sub eax, ebx
		mov ebx, 0xf0
		or eax, ebx
		cvtsi2ss xmm1, eax
		divss xmm0, xmm1
		movss f, xmm0
	}
	printf("\n8.\nb = %hhd | i = %d | j = %d | f = %f\n", b, i, j, f);
	b = 40, i = 20, j = -125, f = 2.7;
	_asm
	{
		movss xmm0, f
		cvttss2si eax, xmm0
		mov ebx, 100
		imul ebx
		movsx ebx, b
		not ebx
		mov ecx, 20
		sub ebx, ecx
		cdq
		idiv ebx
		cvtsi2ss xmm0, eax
		movss f, xmm0
	}
	printf("\n9.\nb = %hhd | i = %d | j = %d | f = %f\n", b, i, j, f);
	b = 40, i = 20, j = -125, f = 2.7;
	_asm
	{
		mov eax, i
		mov ebx, 0x0f
		and eax, ebx
		mov ebx, 0x1f00
		or eax, ebx
		movsx ebx, b
		imul ebx
		movss xmm0, f
		cvtsi2ss xmm1, eax
		subss xmm1, xmm0
		movss f, xmm1
	}
	printf("\n10.\nb = %hhd | i = %d | j = %d | f = %f\n", b, i, j, f);
	b = 40, i = 20, j = -125, f = 2.7;
	_asm
	{
		mov eax, i
		neg eax
		movsx ebx, b
		neg ebx
		movss xmm0, f
		cvtsi2ss xmm1, ebx
		mulss xmm1, xmm0
		movss xmm0, cf281
		cvtsi2ss xmm2, eax
		addss xmm2, xmm0
		subss xmm2, xmm1
		movss xmm0, cf35
		addss xmm2, xmm0
		mov eax, 2
		cvtsi2ss xmm0, eax
		divss xmm2, xmm0
		movss f, xmm2
	}
	printf("\n11.\nb = %hhd | i = %d | j = %d | f = %f\n", b, i, j, f);
	b = 40, i = 20, j = -125, f = 2.7;
	_asm
	{
		movsx ebx, b
		mov eax, 3
		sub ebx, eax
		movsx eax, b
		mov ecx, 2
		cdq
		idiv ecx
		mov ecx, i
		movss xmm0, f
		cvtsi2ss xmm1, eax
		divss xmm1, xmm0
		cvtsi2ss xmm0, ecx
		addss xmm0, xmm1
		cvtsi2ss xmm1, ebx
		addss xmm0, xmm1
		movss f, xmm0
	}
	printf("\n12.\nb = %hhd | i = %d | j = %d | f = %f\n", b, i, j, f);
	b = 40, i = 20, j = -125, f = 2.7;
	_asm
	{
		mov eax, 0xf2
		mov ebx, i
		or eax, ebx
		movsx ebx, b
		mov ecx, 32
		sub ebx, ecx
		cdq
		idiv ebx
		movss xmm0, f
		mulss xmm0, cfneg
		cvtsi2ss xmm1, eax
		divss xmm1, xmm0
		movss xmm0, f
		addss xmm0, xmm1
		cvttss2si eax, xmm0
		mov j, eax
	}
	printf("\n13.\nb = %hhd | i = %d | j = %d | f = %f\n", b, i, j, f);
	return 0;
}
*/

//this is the 5th assignment
/*
#include <stdio.h>

int main()
{
	char b = 40;
	int i = 20;
	float f = 52.5;
	double d = 3.14;
	const float cf35 = 3.5, cf52 = 5.2, cf23 = 2.3, cf281 = 2.81, cf21 = 2.1, cf05 = 0.5, cf25 = 2.5;
	const float cfneg = -1;
	_asm
	{
		movsx eax, b
		movss xmm0, cf35
		cvtsi2ss xmm1, eax
		mulss xmm1, xmm0
		cvtss2sd xmm1, xmm1
		movsd xmm0, d
		addsd xmm0, xmm1
		movsd d, xmm0
	}
	printf("1.\nb = %hhd | i = %d | f = %f | d = %lf\n", b, i, f, d);
	b = 40, i = 20, f = 52.5, d = 3.14;
	_asm
	{
		mov eax, i
		movsd xmm0, d
		cvtsd2ss xmm1, xmm0
		cvtsi2ss xmm0, eax
		mulss xmm0, xmm1
		movss f, xmm0
	}
	printf("2.\nb = %hhd | i = %d | f = %f | d = %lf\n", b, i, f, d);
	b = 40, i = 20, f = 52.5, d = 3.14;
	_asm
	{
		mov eax, i
		cvtsi2ss xmm0, eax
		mov eax, 2
		cvtsi2ss xmm1, eax
		mulss xmm0, xmm1
		movss xmm1, cf52
		movsx eax, b
		cvtsi2ss xmm2, eax
		mulss xmm1, xmm2
		movss xmm2, f
		addss xmm0, xmm2
		subss xmm0, xmm1
		cvttss2si eax, xmm0
		mov i, eax
	}
	printf("3.\nb = %hhd | i = %d | f = %f | d = %lf\n", b, i, f, d);
	b = 40, i = 20, f = 52.5, d = 3.14;
	_asm
	{
		movsx ebx, b
		sub ebx, 36
		movss xmm0, f
		cvttss2si eax, xmm0
		cdq
		idiv ebx
		cvtsi2ss xmm0, eax
		movss f, xmm0
	}
	printf("4.\nb = %hhd | i = %d | f = %f | d = %lf\n", b, i, f, d);
	b = 40, i = 20, f = 52.5, d = 3.14;
	_asm
	{
		movsd xmm0, d
		cvtsd2ss xmm0, xmm0
		mov eax, 2
		cvtsi2ss xmm1, eax
		mulss xmm0, xmm1
		mov eax, 5
		movsx ebx, b
		imul eax, ebx
		movss xmm1, f
		addss xmm0, xmm1
		cvtsi2ss xmm1, eax
		subss xmm0, xmm1
		cvttss2si eax, xmm0
		mov i, eax
	}
	printf("5.\nb = %hhd | i = %d | f = %f | d = %lf\n", b, i, f, d);
	b = 40, i = 20, f = 52.5, d = 3.14;
	_asm
	{
		movsd xmm0, d
		cvttsd2si eax, xmm0
		imul eax, 1000
		movss xmm0, f
		mov ebx, 20
		cvtsi2ss xmm1, ebx
		subss xmm0, xmm1
		cvtsi2ss xmm1, eax
		divss xmm1, xmm0
		cvtss2sd xmm1, xmm1
		movsd d, xmm1
	}
	printf("6.\nb = %hhd | i = %d | f = %f | d = %lf\n", b, i, f, d);
	b = 40, i = 20, f = 52.5, d = 3.14;
	_asm
	{
		movsx eax, b
		cvtsi2sd xmm0, eax
		movsd xmm1, d
		cvttsd2si eax, xmm1
		mov ebx, i
		imul eax, ebx
		cvtsi2sd xmm1, eax
		addsd xmm0, xmm1
		movss xmm1, cfneg
		cvtss2sd xmm1, xmm1
		mulsd xmm0, xmm1
		movss xmm1, cf23
		cvtss2sd xmm1, xmm1
		divsd xmm0, xmm1
		movsd d, xmm0
	}
	printf("7.\nb = %hhd | i = %d | f = %f | d = %lf\n", b, i, f, d);
	b = 40, i = 20, f = 52.5, d = 3.14;
	_asm
	{
		movsd xmm0, d
		movss xmm1, cfneg
		cvtss2sd xmm1, xmm1
		mulsd xmm0, xmm1
		movsx eax, b
		neg eax
		movss xmm1, f
		cvtsi2ss xmm2, eax
		mulss xmm2, xmm1
		movss xmm1, cf281
		cvtss2sd xmm1, xmm1
		addsd xmm0, xmm1
		cvtss2sd xmm1, xmm2
		subsd xmm0, xmm1
		movss xmm1, cf35
		cvtss2sd xmm1, xmm1
		addsd xmm0, xmm1
		cvttsd2si eax, xmm0
		mov ebx, 3
		cdq
		idiv ebx
		mov i, eax
	}
	printf("8.\nb = %hhd | i = %d | f = %f | d = %lf\n", b, i, f, d);
	b = 40, i = 20, f = 52.5, d = 3.14;
	_asm
	{
		movsd xmm0, d
		cvttsd2si eax, xmm0
		mov ebx, i
		neg ebx
		cvtsi2sd xmm0, ebx
		movsx ebx, b
		movss xmm1, cf21
		cvtsi2ss xmm2, ebx
		addss xmm2, xmm1
		imul eax, 3
		movss xmm1, f
		cvtss2sd xmm1, xmm1
		divsd xmm0, xmm1
		cvtsi2sd xmm1, eax
		addsd xmm1, xmm0
		cvtss2sd xmm0, xmm2
		addsd xmm1, xmm0
		movsd d, xmm1
	}
	printf("9.\nb = %hhd | i = %d | f = %f | d = %lf\n", b, i, f, d);
	b = 40, i = 20, f = 52.5, d = 3.14;
	_asm
	{
		movss xmm0, cf05
		mov eax, i
		cvtsi2ss xmm1, eax
		mulss xmm0, xmm1
		movss xmm1, f
		addss xmm1, xmm0
		movsx eax, b
		cvtsi2ss xmm0, eax
		divss xmm1, xmm0
		movss xmm0, f
		addss xmm1, xmm0
		cvttss2si eax, xmm1
		mov b, al
	}
	printf("10.\nb = %hhd | i = %d | f = %f | d = %lf\n", b, i, f, d);
	b = 40, i = 20, f = 52.5, d = 3.14;
	_asm
	{
		movsd xmm0, d
		mov eax, 2
		cvtsi2sd xmm1, eax
		divsd xmm0, xmm1
		mov eax, i
		cvtsi2sd xmm1, eax
		mulsd xmm0, xmm1
		mov eax, 3
		cvtsi2sd xmm1, eax
		divsd xmm0, xmm1
		movsx eax, b
		movss xmm1, cf25
		cvtsi2ss xmm2, eax
		divss xmm2, xmm1
		cvtss2sd xmm2, xmm2
		addsd xmm0, xmm2
		cvtsd2ss xmm0, xmm0
		movss f, xmm0
	}
	printf("11.\nb = %hhd | i = %d | f = %f | d = %lf\n", b, i, f, d);
	b = 40, i = 20, f = 52.5, d = 3.14;
	_asm
	{
		movsd xmm0, d
		mov eax, 100
		cvtsi2sd xmm1, eax
		mulsd xmm0, xmm1
		movsx eax, b
		sub eax, 0xff
		and eax, 0xf0
		cvtsi2sd xmm1, eax
		divsd xmm0, xmm1
		cvtsd2ss xmm0, xmm0
		movss f, xmm0
	}
	printf("12.\nb = %hhd | i = %d | f = %f | d = %lf\n", b, i, f, d);
	return 0;
}
*/

//this is the 5th assignment
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	/*
	char   b = -15, *pb = &b;
	int    i = 0xff1, *pi = &i;
	float  f = 352.318, *pf = &f;
	double d = 975.24, *pd = &d;
	•*pd = abs(b); // d = 15.0
	• f = *pi * (float)sqrt(d); // f = 127444.867
	•*pd = log(f) / log(2); // d = 8.460734346... 
	• f = sqrt(d) + pow(b, 2) * exp(4); // f = 12315.8125
	•*pi = -((float)*pi / 2) * (f - 5.2 * sqrt(-*pb)); // i = -677810
	• f = pow(*pd, 3) / (*pb * 15 - sqrt(36)); // f = -4015342.00
	•*pi = ((int)floor(*pd) | 0xf00f) - 2 + fabs(b * f); // i = 67697
	• d = -sin(b * 3 + 5) + pow(*pi + *pd + f, 3); // d = 158213840345.31961
	• f = cos(-i) * 100 - exp(b / 5 + 6) + *pf * d; // f = 343474.781
	• d = ceil(*pd * 3 + -i) / (cos(2.9) * 6); // d = 198.25776939662740
	*/
	char b = -15, *pb = &b;
	int i = 0xff1, *pi = &i;
	float f = 352.318, *pf = &f;
	double d = 975.24, *pd = &d;
	_asm
	{
		mov eax, pb
		movsx eax, byte ptr[eax]
		push eax
		call dword ptr abs
		add esp, 4
		cvtsi2sd xmm0, eax
		mov eax, pd
		movsd qword ptr[eax], xmm0
	}
	printf("1.\nb = %hhd | i = %d | f = %f | d = %lf\n", b, i, f, d);
	b = -15, i = 0xff1, f = 352.318, d = 975.24;
	return 0;
}