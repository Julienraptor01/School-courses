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