#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

//defines
#define MAX_POKEMON 1500

//structs
struct espece
{
	char nomEspece[50];
	char type[10];
	unsigned int bonbons;
	unsigned int pvMax;
	unsigned int pcMax;
};

struct indEspece
{
	char type[10];
	char nomEspece[50];
	long posI;
};

//prototypes
int encodeEspece(struct espece[], struct indEspece[], int*);
int rechercheEspece(struct espece[], struct indEspece[], int);
void insertionInd(struct espece[], struct indEspece[], int);
void afficheEspece(struct espece[], long);

//main
int main()
{
	struct espece especes[MAX_POKEMON];
	struct indEspece index[MAX_POKEMON];
	int nEspece = 0, choixMenu = -1, i;
	char arreteAffiche[] = "";
	srand(time(NULL));
	//create the menu loop
	do
	{
		printf("\nQue voulez-vous faire :\n1) Ajouter une espece\n2) Afficher les especes\n3) Quitter\n");
		scanf("%d", &choixMenu);
		switch (choixMenu)
		{
		case 1:
			while (nEspece < MAX_POKEMON && encodeEspece(especes, index, &nEspece) == 1);
			break;
		case 2:
			i = 0;
			strcpy(arreteAffiche, "");
			printf("\nEntrez fin entre deux especes pour arreter l'affichage\nN'entrez rien pour continuer\n");
			while (i < nEspece && strlen(arreteAffiche) == 0)
			{
				afficheEspece(especes, index[i].posI);
				i++;
				fflush(stdin);
				gets(arreteAffiche);
			}
			break;
		case 3:
			printf("\nVous avez choisi de quitter le programme\n");
			break;
		default:
			printf("Vous devez choisir une valeur comprise entre 1 et 3\n");
		}
	}
	while (choixMenu != 3);
	return 0;
}

int encodeEspece(struct espece especes[], struct indEspece index[], int* nEspece)
{
	int choixType = -1;
	const char* types[] = { "Acier", "Combat", "Dragon", "Eau", "Electrique", "Fee", "Feu", "Glace", "Insecte", "Normal", "Plante", "Poison", "Psy", "Roche", "Sol", "Spectre", "Tenebres", "Vol" };
	printf("\nCreation d'une nouvelle espece\n");
	//nom de l'espece et verification de l'unicite
	do
	{
		printf("Quel est le nom de l'espece ?\n");
		fflush(stdin);
		gets(especes[*nEspece].nomEspece);
	}
	while (rechercheEspece(especes, index, *nEspece) == 1);
	//sortie si le nom est vide
	if (strlen(especes[*nEspece].nomEspece) == 0)
	{
		return 0;
	}
	else
	{
		//menu pour choisir le type
		do
		{
			printf("Quel est le type du pokemon ?\n1) Acier\n2) Combat\n3) Dragon\n4) Eau\n5) Electrique\n6) Fee\n7) Feu\n8) Glace\n9) Insecte\n10) Normal\n11) Plante\n12) Poison\n13) Psy\n14) Roche\n15) Sol\n16) Spectre\n17) Tenebres\n18) Vol\n");
			scanf("%d", &choixType);
		}
		while (choixType < 1 || choixType > 18);
		//copie du type dans la structure
		strcpy(especes[*nEspece].type, types[choixType - 1]);
		//initialiser les bonbons à 0
		especes[*nEspece].bonbons = 0;
		//demander le nombre de PV Max
		do
		{
			printf("Quel est le nombre de PV Max ?\n");
			scanf("%d", &especes[*nEspece].pvMax);
		}
		while (especes[*nEspece].pvMax < 1 || especes[*nEspece].pvMax >= UINT_MAX / 210);
		//formule PC Max
		especes[*nEspece].pcMax = especes[*nEspece].pvMax * (200 + (rand() % 21 - 10)) / 10;
		//appel de la fonction d'insertion dans l'index
		insertionInd(especes, index, *nEspece);
		//incrementation de la valeur de nEspece
		(*nEspece)++;
		return 1;
	}
}

int rechercheEspece(struct espece especes[], struct indEspece index[], int nEspece)
{
	//recherche de especes[nEspece].nomEspece dans indEspeces
	//retourne 1 si l'espece est trouvee
	//retourne 0 si l'espece n'est pas trouvee
	int i = nEspece - 1;
	while (i >= 0 && strcmp(especes[nEspece].nomEspece, index[i].nomEspece) != 0)
	{
		i--;
	}
	return (i >= 0) ? 1 : 0;
}

void insertionInd(struct espece especes[], struct indEspece index[], int nEspece)
{
	//recherche sequentielle sur le type puis sur le nom
	//insertion dans l'index
	int i = nEspece - 1;
	while (i >= 0 && strcmp(especes[nEspece].type, index[i].type) < 0)
	{
		index[i + 1] = index[i];
		i--;
	}
	while (i >= 0 && strcmp(especes[nEspece].type, index[i].type) == 0 && strcmp(especes[nEspece].nomEspece, index[i].nomEspece) < 0)
	{
		index[i + 1] = index[i];
		i--;
	}
	strcpy(index[i + 1].type, especes[nEspece].type);
	strcpy(index[i + 1].nomEspece, especes[nEspece].nomEspece);
	index[i + 1].posI = nEspece;
}

void afficheEspece(struct espece especes[], long posI)
{
	//affichage de l'espece
	printf("Nom : %s\nType : %s\nNombre de bonbons : %u\nNombre de PV Max : %u\nNombre de PC Max : %u\n", especes[posI].nomEspece, especes[posI].type, especes[posI].bonbons, especes[posI].pvMax, especes[posI].pcMax);
}