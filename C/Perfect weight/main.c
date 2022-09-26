#include <stdio.h>
#include <stdlib.h>

int main()
{
	int height;
	float maleWeight, femaleWeight;
	printf("Quelle est votre taille en cm ?\n");
	scanf("%d", &height);
	maleWeight = (height - 100) - (height - 150) / 4.0;
	femaleWeight = maleWeight * 92 / 100;
	printf("Votre poids ideal est %.1f kg si vous etes un homme et %.1f kg si vous etes une femme", maleWeight, femaleWeight);
	return 0;
}
