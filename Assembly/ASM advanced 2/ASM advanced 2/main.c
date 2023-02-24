#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define EXERCISE 4

int main()
{
#if EXERCISE == 1
	double resistance, current;
	const char askResistance[] = "Enter the resistance : ";
	const char askCurrent[] = "Enter the current : ";
	const char tellVoltage[] = "The voltage is : %lf";
	const char format[] = "%lf";
	_asm
	{
		// Ask for resistance
		lea eax, askResistance
		push eax
		call dword ptr printf
		add esp, 4

		// Read resistance
		lea eax, resistance
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Ask for current
		lea eax, askCurrent
		push eax
		call dword ptr printf
		add esp, 4

		// Read current
		lea eax, current
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Calculate voltage
		movsd xmm0, resistance
		movsd xmm1, current
		mulsd xmm0, xmm1

		// Tell voltage
		sub esp, 8
		movsd qword ptr[esp], xmm0
		lea eax, tellVoltage
		push eax
		call dword ptr printf
		add esp, 12
	}
#elif EXERCISE == 2
	double radius;
	const char askRadius[] = "Enter the radius : ";
	const char tellPerimeter[] = "The perimeter is : %lf";
	const char format[] = "%lf";
	const double cd2 = 2, cdM_PI = M_PI;
	_asm
	{
		// Ask for radius
		lea eax, askRadius
		push eax
		call dword ptr printf
		add esp, 4

		// Read radius
		lea eax, radius
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Calculate perimeter
		movsd xmm0, radius
		mulsd xmm0, cd2
		mulsd xmm0, cdM_PI

		// Tell perimeter
		sub esp, 8
		movsd qword ptr[esp], xmm0
		lea eax, tellPerimeter
		push eax
		call dword ptr printf
		add esp, 12
	}
#elif EXERCISE == 3
	int operation;
	double a, b;
	const char askA[] = "Enter the first number : ";
	const char askB[] = "Enter the second number : ";
	const char askOperation[] = "Enter the operation (1 = +, 2 = -, 3 = *, 4 = /) : ";
	const char tellResult[] = "The result is : %lf";
	const char formatDouble[] = "%lf";
	const char formatInteger[] = "%d";
	_asm
	{
		// Ask for a
		lea eax, askA
		push eax
		call dword ptr printf
		add esp, 4

		// Read a
		lea eax, a
		push eax
		lea eax, formatDouble
		push eax
		call dword ptr scanf
		add esp, 8

		// Ask for b
		lea eax, askB
		push eax
		call dword ptr printf
		add esp, 4

		// Read b
		lea eax, b
		push eax
		lea eax, formatDouble
		push eax
		call dword ptr scanf
		add esp, 8

		// Ask for operation
		lea eax, askOperation
		push eax
		call dword ptr printf
		add esp, 4

		// Read operation
		lea eax, operation
		push eax
		lea eax, formatInteger
		push eax
		call dword ptr scanf
		add esp, 8

		// Prepare a and b
		movsd xmm0, a
		movsd xmm1, b

		// Choose operation
		chooseOperation:
		cmp operation, 1
		je addOperation
		cmp operation, 2
		je subOperation
		cmp operation, 3
		je mulOperation
		cmp operation, 4
		je divOperation
		jmp chooseOperation

		// Add
		addOperation:
		addsd xmm0, xmm1
		jmp result

		// Subtract
		subOperation:
		subsd xmm0, xmm1
		jmp result

		// Multiply
		mulOperation:
		mulsd xmm0, xmm1
		jmp result

		// Divide
		divOperation:
		divsd xmm0, xmm1

		// Tell result
		result:
		sub esp, 8
		movsd qword ptr[esp], xmm0
		lea eax, tellResult
		push eax
		call dword ptr printf
		add esp, 12
	}
#elif EXERCISE == 4
	double a, b, c, d;
	const char askA[] = "Enter the first side length : ";
	const char askB[] = "Enter the second side length : ";
	const char askC[] = "Enter the third side length : ";
	const char askD[] = "Enter the fourth side length : ";
	const char tellDiamond[] = "The shape is a diamond";
	const char tellParallelogram[] = "The shape is a parallelogram";
	const char tellOther[] = "The shape is neither a diamond nor a parallelogram";
	const char format[] = "%lf";
	_asm
	{
		// Ask for a
		lea eax, askA
		push eax
		call dword ptr printf
		add esp, 4

		// Read a
		lea eax, a
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Ask for b
		lea eax, askB
		push eax
		call dword ptr printf
		add esp, 4

		// Read b
		lea eax, b
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Ask for c
		lea eax, askC
		push eax
		call dword ptr printf
		add esp, 4

		// Read c
		lea eax, c
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Ask for d
		lea eax, askD
		push eax
		call dword ptr printf
		add esp, 4

		// Read d
		lea eax, d
		push eax
		lea eax, format
		push eax
		call dword ptr scanf
		add esp, 8

		// Prepare a, b, c and d
		movsd xmm0, a
		movsd xmm1, b
		movsd xmm2, c
		movsd xmm3, d

		// Compare a and b
		comisd xmm0, xmm1
		jne notDiamond

		// Compare a and c
		comisd xmm0, xmm2
		jne other

		// Compare a and d
		comisd xmm0, xmm3
		jne other

		// Tell diamond
		lea eax, tellDiamond
		push eax
		call dword ptr printf
		add esp, 4
		jmp end

		// Compare a and c
		notDiamond:
		comisd xmm0, xmm2
		jne other

		// Compare b and d
		comisd xmm1, xmm3
		jne other

		// Tell parallelogram
		lea eax, tellParallelogram
		push eax
		call dword ptr printf
		add esp, 4
		jmp end

		// Tell other
		other:
		lea eax, tellOther
		push eax
		call dword ptr printf
		add esp, 4

		// End
		end:
	}
#endif
	return 0;
}