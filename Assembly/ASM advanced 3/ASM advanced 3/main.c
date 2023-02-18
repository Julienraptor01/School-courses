#include <stdio.h>

#define EXERCISE 4

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
#if DEBUG_EX3
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
_asm
{
	// ask for the value
	lea eax, askValue
	push eax
	call dword ptr printf
	add esp, 4

	// get the value
	lea eax, format
	push eax
	lea eax, value
	push eax
	call dword ptr scanf
	add esp, 8

	// TODO : insert the value in the vector
}
#endif
	return 0;
}