#include <stdio.h>

#define EXERCISE 5

int main()
{
#if EXERCISE == 1
	int i = 0;
	double vector[3] = { 1.13, 2.42, 3.69 }, *pVector = vector;
	const char format[] = "%lf\n";
	_asm
	{
		// start the loop
		loop_start:
		cmp i, 3
		jnl loop_end

		// do the loop
		mov eax, pVector
		movsd xmm0, qword ptr[eax]
		sub esp, 8
		movsd qword ptr[esp], xmm0
		lea eax, format
		push eax
		call dword ptr printf
		add esp, 12

		// increment
		add pVector, 8
		inc i
		jmp loop_start

		// end the loop
		loop_end:
	}
#elif EXERCISE == 2
	int i = 0;
	int vector[3] = { 1, 2, 3 }, *pVector = vector;
	const char format[] = "%d\n";
	_asm
	{
		// start the loop
		loop_start:
		cmp i, 3
		jnl loop_end

		// do the loop
		mov eax, pVector
		mov eax, dword ptr[eax]
		push eax
		lea eax, format
		push eax
		call dword ptr printf
		add esp, 8

		// increment
		add pVector, 4
		inc i
		jmp loop_start

		// end the loop
		loop_end:
	}
#elif EXERCISE == 3
	// Copier dans un vecteur de doubles uniquement les valeurs négatives figurant dans un vecteur d’entiers(par exemple, si VecEntiers contient[-9, 4, 8, -2, -7, 5], alors on aura dans VecDoubles[-9, -2, -7]).
	int i = 0;
	int vectorInt[6] = { -9, 4, 8, -2, -7, 5 }, *pVectorInt = vectorInt;
	double vectorDouble[6] = {0}, * pVectorDouble = vectorDouble;
#define DEBUG_EX3 1
	_asm
	{
		// start the loop
		loop_start:
		cmp i, 6
		jnl loop_end

		// do the loop
		mov eax, pVectorInt
		mov eax, dword ptr[eax]
		cmp eax, 0
		jge loop_increment

		// copy
		mov eax, pVectorInt
		cvtsi2sd xmm0, dword ptr[eax]
		mov eax, pVectorDouble
		movsd qword ptr[eax], xmm0

		// increment only if the value is negative
		add pVectorDouble, 8

		// increment
		loop_increment:
		add pVectorInt, 4
		inc i
		jmp loop_start

		// end the loop
		loop_end:
	}
#if DEBUG_EX3 == 1
	for (i = 0; vectorDouble[i] < 0; i++)
	{
		printf("%lf\n", vectorDouble[i]);
	}
#endif
#elif EXERCISE == 4
	// Insérer une valeur saisie au clavier au bon endroit dans un vecteur d’entiers dont les valeurs sont déjà ordonnées par ordre croissant(par exemple, si VecEntiers contient[2, 8, 11, 15, 20] et que la valeur à insérer est 10, alors on aura dans VecEntiers[2, 8, 10, 11, 15, 20]).
	int i = 0;
	int vectorInt[6] = { 2, 8, 11, 15, 20 }, *pVectorInt = vectorInt;
	int value;
	const char askValue[] = "Enter a value to insert in the vector : ";
	const char format[] = "%d";
#define DEBUG_EX4 1
	_asm
	{
		// ask for the value
		lea eax, askValue
		push eax
		call dword ptr printf
		add esp, 4

		// get the value
		lea eax, value
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// TODO : insert the value in the vector
		// let's assume the vector is already sorted
		// we'll move the pointer of the vector at the end of the vector
		// once that's done, we'll move the pointer back until we find the right place to insert the value
		// but we'll aldo move the values of the vector to the right to make room for the new value
		// we'll start by moving the pointer to the end of the vector
		add pVectorInt, 16

		// start the loop
		loop_start:
		cmp i, 5
		jnl loop_end

		// do the loop
		mov eax, pVectorInt
		mov eax, dword ptr[eax]
		cmp eax, value
		jl loop_end

		// move the values to the right
		add pVectorInt, 4
		mov ebx, pVectorInt
		mov dword ptr[ebx], eax
		sub pVectorInt, 4

		// increment
		sub pVectorInt, 4
		inc i
		jmp loop_start

		// end the loop
		loop_end:

		// insert the value
		add pVectorInt, 4
		mov eax, pVectorInt
		mov ebx, value
		mov dword ptr[eax], ebx
	}
#if DEBUG_EX4 == 1
	for (i = 0; i < 6; i++)
	{
		printf("%d\n", vectorInt[i]);
	}
#endif
#elif EXERCISE == 5
	// Échanger 2 à 2 les valeurs dans un vecteur de doubles (par exemple, si VecDoubles contient [-9.78, 4, 8, -2, -7.1, 5, 2.6], alors on aura dans VecDoubles[4, -9.78, -2, 8, 5, -7.1, 2.6]).Cela doit fonctionner avec des vecteurs qui contiennent un nombre de valeurs pair ou impair.
	int i = 0;
	int nbValues = 7;
	double vectorDouble[] = { -9.78, 4, 8, -2, -7.1, 5, 2.6 }, *pVectorDouble = vectorDouble;
#define DEBUG_EX5 1
	_asm
	{
		// start the loop
		loop_start:
		mov eax, nbValues
		dec eax
		cmp i, eax
		jnl loop_end

		// do the loop
		mov eax, pVectorDouble
		movsd xmm0, qword ptr[eax]
		add pVectorDouble, 8
		mov eax, pVectorDouble
		movsd xmm1, qword ptr[eax]
		movsd qword ptr[eax], xmm0
		sub pVectorDouble, 8
		mov eax, pVectorDouble
		movsd qword ptr[eax], xmm1

		// increment
		add pVectorDouble, 16
		add i, 2
		jmp loop_start

		// end the loop
		loop_end:
	}
#if DEBUG_EX5 == 1
	for (i = 0; i < nbValues; i++)
	{
		printf("%lf\n", vectorDouble[i]);
	}
#endif
#endif
	return 0;
}