#include <stdio.h>

int main()

{
	char b = 40;
	int i = 20;
	int j = -125;
	float f = 2.7;
	const float cf281 = 2.81, cf35 = 3.5, cfneg = -1;
	_asm
	{
		movss xmm0, f
		cvttss2si eax, xmm0
		mov b, al
	}
	printf("\n1.\nb = %hhd | i = %d | j = %d | f = %g\n", b, i, j, f);
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
	printf("\n2.\nb = %hhd | i = %d | j = %d | f = %g\n", b, i, j, f);
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
	printf("\n3.\nb = %hhd | i = %d | j = %d | f = %g\n", b, i, j, f);
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
	printf("\n4.\nb = %hhd | i = %d | j = %d | f = %g\n", b, i, j, f);
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
	printf("\n5.\nb = %hhd | i = %d | j = %d | f = %g\n", b, i, j, f);
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
	printf("\n6.\nb = %hhd | i = %d | j = %d | f = %g\n", b, i, j, f);
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
	printf("\n7.\nb = %hhd | i = %d | j = %d | f = %g\n", b, i, j, f);
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
	printf("\n8.\nb = %hhd | i = %d | j = %d | f = %g\n", b, i, j, f);
	b = 40, i = 20, j = -125, f = 2.7;
	_asm
	{
		
	}
	printf("\n9.\nb = %hhd | i = %d | j = %d | f = %g\n", b, i, j, f);
	return 0;
}