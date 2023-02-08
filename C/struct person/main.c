#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NEWLINE printf("\n")

struct fiche
{
	char nom[20];
	int age;
	char genre;
};

void lecture(struct fiche*, int);
void affichage(struct fiche*, int);
void afficheNomAgeSiHommePlusSoixanteAns(struct fiche*, int);
void retireCinqAnsSiFemmePlusQuaranteAns(struct fiche*, int);
void afficheNomAgeSiFemme(struct fiche*, int);

int main()
{
#ifdef DEBUG
	struct fiche v[10] = { {"Jean", 20, 'H'}, {"Marie", 30, 'F'}, {"Paul", 40, 'H'}, {"Pierre", 50, 'H'}, {"Jacques", 60, 'H'}, {"Sophie", 70, 'F'}, {"Julie", 80, 'F'}, {"Julien", 90, 'H'}, {"Juliette", 100, 'F'}, {"Julien", 110, 'H'} };
#else
	struct fiche v[10];
#endif
	int n;
#ifdef DEBUG
	n = 10;
#else
	do
	{
		printf("Donnez un nombre de fiches (max 10) : ");
		scanf("%d", &n);
	} while (n < 0 || n > 10);
	NEWLINE;
	lecture(v, n);
	NEWLINE;
#endif
	affichage(v, n);
	NEWLINE;
	afficheNomAgeSiHommePlusSoixanteAns(v, n);
	NEWLINE;
	retireCinqAnsSiFemmePlusQuaranteAns(v, n);
	afficheNomAgeSiFemme(v, n);
	return 0;
}

void lecture(struct fiche* pV, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("Donnez le nom de la personne %d : ", i + 1);
		fflush(stdin);
		gets((pV + i)->nom);
		printf("Donnez l'age de la personne %d : ", i + 1);
		fflush(stdin);
		scanf("%d", &(pV + i)->age);
		printf("Donnez le genre de la personne %d : ", i + 1);
		fflush(stdin);
		scanf("%c", &(pV + i)->genre);
		NEWLINE;
	}
}

void affichage(struct fiche* pV, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("Nom : %s\tAge : %d\tGenre : %c\n", (pV + i)->nom, (pV + i)->age, (pV + i)->genre);
	}
}

void afficheNomAgeSiHommePlusSoixanteAns(struct fiche* pV, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if ((pV + i)->age > 60 && (pV + i)->genre == 'H')
		{
			printf("Nom : %s\tAge : %d\n", (pV + i)->nom, (pV + i)->age);
		}
	}
}

void retireCinqAnsSiFemmePlusQuaranteAns(struct fiche* pV, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if ((pV + i)->age > 40 && (pV + i)->genre == 'F')
		{
			(pV + i)->age -= 5;
		}
	}
}

void afficheNomAgeSiFemme(struct fiche* pV, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if ((pV + i)->genre == 'F')
		{
			printf("Nom : %s\tAge : %d\n", (pV + i)->nom, (pV + i)->age);
		}
	}
}