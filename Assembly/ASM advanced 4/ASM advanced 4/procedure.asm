.MODEL FLAT, C

.DATA

	pi DQ 3.14159265358979323846
	two DQ 2.0

.CODE

; Convert Celsius to Fahrenheit
; C prototype is : int celsiusToFarhenheit(int celsius)

celsiusToFahrenheit proc
	
	celsius equ <dword ptr [esp+4]>

	mov eax, celsius
	imul eax, 9
	cdq
	mov ebx, 5
	idiv ebx
	add eax, 32

	ret

celsiusToFahrenheit endp

; Ohms law
; C prototype is : int ohmsLaw(int resistance, int current)

ohmsLaw proc

	resistance equ <dword ptr [esp+4]>
	current equ <dword ptr [esp+8]>

	mov eax, resistance
	imul eax, current

	ret

ohmsLaw endp

; Circle perimeter
; C prototype is : double circlePerimeter(double radius)

circlePerimeter proc

	localReturnVariable equ <qword ptr [esp+0]>
	radius equ <qword ptr [esp+12]>

	sub esp, 8

	movsd xmm0, radius
	mulsd xmm0, pi
	mulsd xmm0, two

	movsd localReturnVariable, xmm0
	fld localReturnVariable
	add esp, 8

ret

circlePerimeter endp

END