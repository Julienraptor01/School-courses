#include <stdio.h>
#include <stdlib.h>

int main()
{
	int length, section;
	float resistance;
	printf("Entrez la longueur du cable en metres\n");
	scanf("%d", &length);
	printf("Entrez la section du cable en millimetres carres\n");
	scanf("%d", &section);
	resistance = length * 1.6e-8 / section;
	printf("La resistance du cable est de %.2e Ohms\n", resistance);
	return 0;
}
