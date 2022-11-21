//base transpose with no pointers and 2 vectors
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size = 4;
	int vector[size][size], vectorTransposed[size][size];
	int i, j;
	int biggestNumber = 0, numberOfDigits = 0, k;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("Entrez la valeur du vecteur en (%d ; %d) : ", i, j);
			scanf("%d", &vector[i][j]);
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (vector[i][j] > biggestNumber)
			{
				biggestNumber = vector[i][j];
			}
		}
	}
	do
	{
		biggestNumber = biggestNumber / 10;
		numberOfDigits++;
	} while (biggestNumber > 0);
	printf("\nVoici le vecteur :\n");
	for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
	{
		printf("-");
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("|");
		for (j = 0; j < size; j++)
		{
			printf(" %*d |", numberOfDigits, vector[i][j]);
		}
		printf("\n");
		for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
		{
			printf("-");
		}
		printf("\n");
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			vectorTransposed[j][i] = vector[i][j];
		}
	}
	printf("\nVoici la transposee du vecteur :\n");
	for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
	{
		printf("-");
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("|");
		for (j = 0; j < size; j++)
		{
			printf(" %*d |", numberOfDigits, vectorTransposed[i][j]);
		}
		printf("\n");
		for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
		{
			printf("-");
		}
		printf("\n");
	}
	return 0;
}
*/

//base with 2 vectors but with pointers
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size = 4;
	int vector[size][size], vectorTransposed[size][size];
	//add the origins of the vectors into pointers
	const int *pVectorOrigin = &vector[0][0], *pVectorTransposedOrigin = &vectorTransposed[0][0];
	//add the pointers to the vectors
	int *pVector , *pVectorTransposed;
	int i, j;
	int biggestNumber = 0, numberOfDigits = 0, k;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			//use a vector based way
			pVector = pVectorOrigin + i * size + j;
			printf("Entrez la valeur du vecteur en (%d ; %d) : ", i, j);
			scanf("%d", pVector);
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			//use a vector based way
			pVector = pVectorOrigin + i * size + j;
			if (*pVector > biggestNumber)
			{
				biggestNumber = *pVector;
			}
		}
	}
	do
	{
		biggestNumber = biggestNumber / 10;
		numberOfDigits++;
	} while (biggestNumber > 0);
	printf("\nVoici le vecteur :\n");
	for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
	{
		printf("-");
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("|");
		for (j = 0; j < size; j++)
		{
			//use a vector based way
			pVector = pVectorOrigin + i * size + j;
			printf(" %*d |", numberOfDigits, *pVector);
		}
		printf("\n");
		for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
		{
			printf("-");
		}
		printf("\n");
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			//use a vector based way
			pVector = pVectorOrigin + i * size + j;
			pVectorTransposed = pVectorTransposedOrigin + j * size + i;
			*pVectorTransposed = *pVector;
		}
	}
	printf("\nVoici la transposee du vecteur :\n");
	for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
	{
		printf("-");
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("|");
		for (j = 0; j < size; j++)
		{
			//use a vector based way
			pVectorTransposed = pVectorTransposedOrigin + i * size + j;
			printf(" %*d |", numberOfDigits, *pVectorTransposed);
		}
		printf("\n");
		for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
		{
			printf("-");
		}
		printf("\n");
	}
	return 0;
}
*/

//base with no pointers but with 1 vector
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size = 4;
	int vector[size][size];
	int i, j;
	int biggestNumber = 0, numberOfDigits = 0, k;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("Entrez la valeur du vecteur en (%d ; %d) : ", i, j);
			scanf("%d", &vector[i][j]);
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (vector[i][j] > biggestNumber)
			{
				biggestNumber = vector[i][j];
			}
		}
	}
	do
	{
		biggestNumber = biggestNumber / 10;
		numberOfDigits++;
	} while (biggestNumber > 0);
	printf("\nVoici le vecteur :\n");
	for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
	{
		printf("-");
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("|");
		for (j = 0; j < size; j++)
		{
			printf(" %*d |", numberOfDigits, vector[i][j]);
		}
		printf("\n");
		for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
		{
			printf("-");
		}
		printf("\n");
	}
	//special case here, we only need to swap the upper part of the vector otherwise it will swap the vector twice
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			vector[i][j] = vector[i][j] + vector[j][i];
			vector[j][i] = vector[i][j] - vector[j][i];
			vector[i][j] = vector[i][j] - vector[j][i];
		}
	}
	printf("\nVoici la transposee du vecteur :\n");
	for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
	{
		printf("-");
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("|");
		for (j = 0; j < size; j++)
		{
			printf(" %*d |", numberOfDigits, vector[i][j]);
		}
		printf("\n");
		for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
		{
			printf("-");
		}
		printf("\n");
	}
	return 0;
}
*/

//base but with 1 vector and pointers
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size = 3;
	int vector[size][size];
	const int *pVectorOrigin = &vector[0][0];
	int *pVector;
	int i, j;
	int biggestNumber = 0, numberOfDigits = 0, k;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			//use a vector based way
			pVector = pVectorOrigin + i * size + j;
			printf("Entrez la valeur du vecteur en (%d ; %d) : ", i, j);
			scanf("%d", pVector);
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			//use a vector based way
			pVector = pVectorOrigin + i * size + j;
			if (*pVector > biggestNumber)
			{
				biggestNumber = *pVector;
			}
		}
	}
	do
	{
		biggestNumber = biggestNumber / 10;
		numberOfDigits++;
	} while (biggestNumber > 0);
	printf("\nVoici le vecteur :\n");
	for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
	{
		printf("-");
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("|");
		for (j = 0; j < size; j++)
		{
			//use a vector based way
			pVector = pVectorOrigin + i * size + j;
			printf(" %*d |", numberOfDigits, *pVector);
		}
		printf("\n");
		for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
		{
			printf("-");
		}
		printf("\n");
	}
	//special case here, we only need to swap the upper part of the vector otherwise it will swap the vector twice
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			//use a vector based way
			pVector = pVectorOrigin + i * size + j;
			*pVector = *pVector + *(pVectorOrigin + j * size + i);
			*(pVectorOrigin + j * size + i) = *pVector - *(pVectorOrigin + j * size + i);
			*pVector = *pVector - *(pVectorOrigin + j * size + i);
		}
	}
	printf("\nVoici la transposee du vecteur :\n");
	for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
	{
		printf("-");
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("|");
		for (j = 0; j < size; j++)
		{
			//use a vector based way
			pVector = pVectorOrigin + i * size + j;
			printf(" %*d |", numberOfDigits, *pVector);
		}
		printf("\n");
		for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
		{
			printf("-");
		}
		printf("\n");
	}
	return 0;
}
*/

//QoL update by adding and changing lots of things

#include <stdio.h>
#include <stdlib.h>

//create a boolean type
typedef enum { false, true } bool;

int main()
{
	char ouiOrNon[3];
	bool specialNaming;
	int size;
	//ask the user if he want a naming where lines and columns start with 1 when asking for the vector values
	do {
		printf("Voulez-vous que les numeros de lignes et de colonnes commencent a 1 ? (oui/non) : ");
		scanf("%s", &ouiOrNon);
		if (ouiOrNon[0] == 'o' && ouiOrNon[1] == 'u' && ouiOrNon[2] == 'i')
		{
			specialNaming = true;
		}
		else if (ouiOrNon[0] == 'n' && ouiOrNon[1] == 'o' && ouiOrNon[2] == 'n')
		{
			specialNaming = false;
		}
		else
		{
			printf("Veuillez repondre par oui ou par non.\n");
		}
		//flush the input here to prevent the program from reusing a previous input
		fflush(stdin);
	} while ((ouiOrNon[0] != 'o' && ouiOrNon[1] != 'u' && ouiOrNon[2] != 'i') && (ouiOrNon[0] != 'n' && ouiOrNon[1] != 'o' && ouiOrNon[2] != 'n'));
	//ask the size of the vector
	do
	{
		printf("Entrez la taille du vecteur : ");
		scanf("%d", &size);
	} while (size < 1);
	//now start the same program with small tweaks
	int vector[size][size];
	const int *pVectorOrigin = &vector[0][0];
	//no vector pointer, we are gonna do everything with offsets
	int i, j;
	//here, we aren't gonna init biggestNumber nor numberOfDigits, we are gonna set them to the 1st value of the vector and to 0 right before their respective loops
	int biggestNumber, numberOfDigits, k;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			//replace our vector pointer by an offset based way
			printf("Entrez la valeur du vecteur en (%d ; %d) : ", i + specialNaming, j + specialNaming);
			scanf("%d", pVectorOrigin + i * size + j);
		}
	}
	//set the biggestNumber to the 1st value of the vector
	biggestNumber = *pVectorOrigin;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			//replace our vector pointer by an offset based way
			if (*(pVectorOrigin + i * size + j) > biggestNumber)
			{
				biggestNumber = *(pVectorOrigin + i * size + j);
			}
		}
	}
	//set the numberOfDigits to 0
	numberOfDigits = 0;

	do
	{
		biggestNumber = biggestNumber / 10;
		numberOfDigits++;
	} while (biggestNumber > 0);
	printf("\nVoici le vecteur :\n");
	for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
	{
		printf("-");
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("|");
		for (j = 0; j < size; j++)
		{
			//replace our vector pointer by an offset based way
			printf(" %*d |", numberOfDigits, *(pVectorOrigin + i * size + j));
		}
		printf("\n");
		for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
		{
			printf("-");
		}
		printf("\n");
	}
	//prepare some trickery to write to a const pointer
	int **pToPVector = &pVectorOrigin;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			//replace our vector pointer by an offset based way
			/**(pVectorOrigin + i * size + j) = *(pVectorOrigin + i * size + j) + *(pVectorOrigin + j * size + i);
			*(pVectorOrigin + j * size + i) = *(pVectorOrigin + i * size + j) - *(pVectorOrigin + j * size + i);
			*(pVectorOrigin + i * size + j) = *(pVectorOrigin + i * size + j) - *(pVectorOrigin + j * size + i);*/
			//use the previously setup trickery because we can't write to a const pointer
			*(*pToPVector + i * size + j) = *(pVectorOrigin + i * size + j) + *(pVectorOrigin + j * size + i);
			*(*pToPVector + j * size + i) = *(pVectorOrigin + i * size + j) - *(pVectorOrigin + j * size + i);
			*(*pToPVector + i * size + j) = *(pVectorOrigin + i * size + j) - *(pVectorOrigin + j * size + i);
		}
	}
	printf("\nVoici la transposee du vecteur :\n");
	for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
	{
		printf("-");
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("|");
		for (j = 0; j < size; j++)
		{
			//replace our vector pointer by an offset based way
			printf(" %*d |", numberOfDigits, *(pVectorOrigin + i * size + j));
		}
		printf("\n");
		for (k = 0; k < (numberOfDigits + 3) * size + 1; k++)
		{
			printf("-");
		}
		printf("\n");
	}
	return 0;
}
