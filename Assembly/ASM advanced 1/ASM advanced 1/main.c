#include <stdio.h>

#define EXERCICE 4

int main()
{
#if EXERCICE == 1
	int celsius, fahrenheit;
	const char askInput[] = "Enter the temperature in Celsius : ";
	const char format[] = "%d";
	const char tellOutput[] = "The temperature in Fahrenheit is : %d";
	_asm
	{
		// Ask for input
		lea eax, askInput
		push eax
		call dword ptr printf
		add esp, 4

		// Get input
		lea eax, celsius
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Convert to Fahrenheit
		mov eax, celsius
		imul eax, 9
		cdq
		mov ebx, 5
		idiv ebx
		add eax, 32

		// Tell output
		push eax
		lea eax, tellOutput
		push eax
		call dword ptr printf
		add esp, 8
	}
#elif EXERCICE == 2
	int input;
	const char askInput[] = "Enter a number : ";
	const char format[] = "%d";
	const char tellOutputIfTwenty[] = "It's perfect !";
	const char tellOutputIfFifteen[] = "It's good !";
	const char tellOutputIfTen[] = "It's sufficient !";
	const char tellOutputIfFive[] = "It's insufficient !";
	const char tellOutputIfOther[] = "This Value is incorrect !";
	_asm
	{
		// Ask for input
		lea eax, askInput
		push eax
		call dword ptr printf
		add esp, 4

		// Get input
		lea eax, input
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Compare
		cmp input, 20
		je ifTwenty
		cmp input, 15
		je ifFifteen
		cmp input, 10
		je ifTen
		cmp input, 5
		je ifFive

		// Tell output if other
		lea eax, tellOutputIfOther
		push eax
		call dword ptr printf
		add esp, 4
		jmp end

		// Tell output if five
		ifFive:
		lea eax, tellOutputIfFive
		push eax
		call dword ptr printf
		add esp, 4
		jmp end

		// Tell output if ten
		ifTen:
		lea eax, tellOutputIfTen
		push eax
		call dword ptr printf
		add esp, 4
		jmp end

		// Tell output if fifteen
		ifFifteen:
		lea eax, tellOutputIfFifteen
		push eax
		call dword ptr printf
		add esp, 4
		jmp end

		// Tell output if twenty
		ifTwenty:
		lea eax, tellOutputIfTwenty
		push eax
		call dword ptr printf
		add esp, 4

		// End
		end:
	}
#elif EXERCICE == 3
	int side1, side2, side3;
	const char askSide1[] = "Enter the length of the first side : ";
	const char askSide2[] = "Enter the length of the second side : ";
	const char askSide3[] = "Enter the length of the third side : ";
	const char format[] = "%d";
	const char tellOutputIfEquilateral[] = "It's an equilateral triangle !";
	const char tellOutputOtherwise[] = "It's not an equilateral triangle !";
	_asm
	{
		// Ask for side 1
		lea eax, askSide1
		push eax
		call dword ptr printf
		add esp, 4

		// Get side 1
		lea eax, side1
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Ask for side 2
		lea eax, askSide2
		push eax
		call dword ptr printf
		add esp, 4

		// Get side 2
		lea eax, side2
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Ask for side 3
		lea eax, askSide3
		push eax
		call dword ptr printf
		add esp, 4

		// Get side 3
		lea eax, side3
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Compare
		mov eax, side1
		cmp side2, eax
		jne otherwise
		cmp side3, eax
		jne otherwise

		// Tell output if equilateral
		lea eax, tellOutputIfEquilateral
		push eax
		call dword ptr printf
		add esp, 4
		jmp end

		// Tell output otherwise
		otherwise:
		lea eax, tellOutputOtherwise
		push eax
		call dword ptr printf
		add esp, 4

		// End
		end:
	}
#elif EXERCICE == 4
	int side1, side2, side3;
	const char askSide1[] = "Enter the length of the first side : ";
	const char askSide2[] = "Enter the length of the second side : ";
	const char askSide3[] = "Enter the length of the third side : ";
	const char format[] = "%d";
	const char tellOutputIfRectangle[] = "It's rectangle !";
	const char tellOutputOtherwise[] = "It's not rectangle !";
	_asm
	{
		// Ask for side 1
		lea eax, askSide1
		push eax
		call dword ptr printf
		add esp, 4

		// Get side 1
		lea eax, side1
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Ask for side 2
		lea eax, askSide2
		push eax
		call dword ptr printf
		add esp, 4

		// Get side 2
		lea eax, side2
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Ask for side 3
		lea eax, askSide3
		push eax
		call dword ptr printf
		add esp, 4

		// Get side 3
		lea eax, side3
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// sorting sides to get 1 > 2 > 3
		mov eax, side2
		cmp side1, eax
		jl swap1st
		afterswap1st :
		mov eax, side3
		cmp side2, eax
		jl swap2nd
		afterswap2nd :
		mov eax, side2
		cmp side1, eax
		jl swap3rd
		afterswap3rd :

		// Do the pythagorean math to check if it's a rectangle
		mov eax, side3
		imul eax, eax
		mov ebx, side2
		imul ebx, ebx
		add eax, ebx
		mov ebx, side1
		imul ebx, ebx
		cmp eax, ebx
		jne otherwise

		// Tell output if rectangle
		lea eax, tellOutputIfRectangle
		push eax
		call dword ptr printf
		add esp, 4
		jmp end

		// Tell output otherwise
		otherwise :
		lea eax, tellOutputOtherwise
		push eax
		call dword ptr printf
		add esp, 4
		jmp end

		// Swap 1 and 2
		swap1st :
		mov eax, side1
		mov ebx, side2
		mov side1, ebx
		mov side2, eax
		jmp afterswap1st

		// Swap 2 and 3
		swap2nd :
		mov eax, side2
		mov ebx, side3
		mov side2, ebx
		mov side3, eax
		jmp afterswap2nd

		// Swap 1 and 2
		swap3rd :
		mov eax, side1
		mov ebx, side2
		mov side1, ebx
		mov side2, eax
		jmp afterswap3rd

		// End
		end :
	}
#endif
	return 0;
}