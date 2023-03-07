/************************************************************************************/
/* Auteurs : BOLLY Julien, SECCO Johan												*/
/* Groupe : 2131																	*/
/* Application : Dossier 2 Pokémon ; Encodage, recherche et affichage des espèces	*/
/* Date de la dernière modification : 01/03/2023									*/
/************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

//defines
//nombre maximum d'espèces
#define MAX_POKEMON 1500
//taille maximum du nom d'une espèce
#define MAX_TAILLE_NOM 50
//taille maximum du type d'une espèce
#define MAX_TAILLE_TYPE 10
//nombre de types différents
#define NOMBRE_TYPES 18
//décommentez la ligne ci-dessous pour activer le mode DEBUG ce qui pré-entre des espèces
//#define DEBUG

//structures de données
struct espece
{
	char nomEspece[MAX_TAILLE_NOM];
	char type[MAX_TAILLE_TYPE];
	unsigned int bonbons;
	unsigned int pvMax;
	unsigned int pcMax;
};

struct indEspece
{
	char type[MAX_TAILLE_TYPE];
	char nomEspece[MAX_TAILLE_NOM];
	long posI;
};

//prototypes de fonctions
int encodeEspece(struct espece[], struct indEspece[], long);
int rechercheEspece(struct espece[], struct indEspece[], long);
void insertionInd(struct espece[], struct indEspece[], long);
void afficheEspece(struct espece[], long);
int rechercheTypeEspece(long[], struct indEspece[], long, long*);

//variable globale
const char types[NOMBRE_TYPES][MAX_TAILLE_TYPE] = { "Acier", "Combat", "Dragon", "Eau", "Electrik", "Fee", "Feu", "Glace", "Insecte", "Normal", "Plante", "Poison", "Psy", "Roche", "Sol", "Spectre", "Tenebres", "Vol" };

int main()
{
#ifdef DEBUG
	printf("DEBUG MODE\n");
	//structures prédéfinies pour debug
	struct espece especes[MAX_POKEMON] = { { "Roucarnage", "Normal", 0, 30, 630 }, { "Roucoups", "Normal", 0, 20, 400 }, { "Roucool", "Normal", 0, 10, 190 }, { "Piafabec", "Normal", 0, 12, 234 }, { "Rattatac", "Normal", 0, 25, 518 }, { "Rattata", "Normal", 0, 15, 290 }, { "Draco", "Dragon", 0, 100, 2100 }, { "Carapuce", "Eau", 0, 17, 354 }, { "Pikachu", "Electrik", 0, 17, 354 }, { "Salameche", "Feu", 0, 17, 354 }, { "Bulbizarre", "Plante", 0, 17, 354 }, { "Onix", "Acier", 0, 42, 878 } };
	struct indEspece index[MAX_POKEMON] = { { "Acier", "Onix", 11 }, { "Dragon", "Draco", 6 }, { "Eau", "Carapuce", 7 }, { "Electrik", "Pikachu", 8 }, { "Feu", "Salameche", 9 }, { "Normal", "Piafabec", 3 }, { "Normal", "Rattata", 5 }, { "Normal", "Rattatac", 4 }, { "Normal", "Roucarnage", 0 }, { "Normal", "Roucool", 2 }, { "Normal", "Roucoups", 1 }, { "Plante", "Bulbizarre", 10 } };
	long nEspece = 12;
#else
	struct espece especes[MAX_POKEMON];
	struct indEspece index[MAX_POKEMON];
	long nEspece = 0;
#endif
	long position[MAX_POKEMON], nEspeceType = 0;
	int choixMenu = -1, i;
	char arreteAffiche[] = "";
	srand(time(NULL));
	//accueil de l'utilisateur
	printf("Bienvenue dans le programme de gestion des especes de Pokemon\n");
	//boucle de menu
	do
	{
		printf("\nQue voulez-vous faire :\n1) Ajouter une espece\n2) Afficher les especes\n3) Rechercher les pokemons d'un meme type\n4) Quitter\n");
		fflush(stdin);
		scanf("%d", &choixMenu);
		switch (choixMenu)
		{
		//ajout d'une espèce
		case 1:
			while (nEspece < MAX_POKEMON && encodeEspece(especes, index, nEspece) == 1)
			{
				//appel de la fonction d'insertion dans l'index
				insertionInd(especes, index, nEspece);
				//incrementation de la valeur de nEspece
				(nEspece)++;
			}
			break;
		//affichage des espèces
		case 2:
			i = 0;
			strcpy(arreteAffiche, "");
			printf("\nEntrez n'importe quel caractere entre deux especes pour arreter l'affichage\nN'entrez rien pour continuer\n");
			while (i < nEspece && strlen(arreteAffiche) == 0)
			{
				afficheEspece(especes, index[i].posI);
				i++;
				fflush(stdin);
				gets(arreteAffiche);
			}
			break;
		//quitter le programme
		case 3:
			if (rechercheTypeEspece(position, index, nEspece, &nEspeceType) == 1)
			{
				i = 0;
				strcpy(arreteAffiche, "");
				printf("\nEntrez n'importe quel caractere entre deux especes pour arreter l'affichage\nN'entrez rien pour continuer\n");
				while (i < nEspeceType && strlen(arreteAffiche) == 0)
				{
					afficheEspece(especes, position[i]);
					i++;
					fflush(stdin);
					gets(arreteAffiche);
				}
			}
			else
			{
				printf("Aucune espece de ce type n'a ete trouvee\n");
			}
			break;
		case 4:
			printf("\nVous avez choisi de quitter le programme\n");
			break;
		//cas d'erreur
		default:
			printf("Vous devez choisir une valeur comprise entre 1 et 4\n");
		}
	}
	while (choixMenu != 4);
	return 0;
}

/********************************************************************************************************************************************************************************/
/* INPUT : un tableau de structures de type espece (les espèces), un tableau de structures de type indEspece (l'index), un pointeur sur un entier (le nombre d'espèces)			*/
/* Process : récupère les informations sur une nouvelle espèce, vérifie l'unicité de l'espèce, l'ajoute à la liste, appelle l'ajout à l'index et incrémente le nombre d'espèces	*/
/* OUTPUT : un entier (1 si une nouvelle espèce a été ajoutée, 0 sinon)																											*/
/********************************************************************************************************************************************************************************/
int encodeEspece(struct espece especes[], struct indEspece index[], long nEspece)
{
	int choixType = -1;
	printf("\nCreation d'une nouvelle espece\nN'entrez rien pour revenir au menu principal\n");
	//nom de l'espece
	do
	{
		printf("Quel est le nom de l'espece ?\n");
		fflush(stdin);
		gets(especes[nEspece].nomEspece);
		//sortie si le nom est vide
		if (strlen(especes[nEspece].nomEspece) == 0)
		{
			return 0;
		}
		//vérification de l'unicité de l'espèce
		else if (rechercheEspece(especes, index, nEspece) == 1)
		{
			printf("Le pokemon est deja present\n");
		}
	}
	while (rechercheEspece(especes, index, nEspece) == 1);
	//menu pour choisir le type
	do
	{
		printf("Quel est le type du pokemon ?\n1) Acier\n2) Combat\n3) Dragon\n4) Eau\n5) Electrik\n6) Fee\n7) Feu\n8) Glace\n9) Insecte\n10) Normal\n11) Plante\n12) Poison\n13) Psy\n14) Roche\n15) Sol\n16) Spectre\n17) Tenebres\n18) Vol\n");
		fflush(stdin);
		scanf("%d", &choixType);
	}
	while (choixType < 1 || choixType > NOMBRE_TYPES);
	//copie du type dans la structure
	strcpy(especes[nEspece].type, types[choixType - 1]);
	//initialiser les bonbons à 0
	especes[nEspece].bonbons = 0;
	//demander le nombre de PV Max
	do
	{
		printf("Quel est le nombre de PV Max ?\n");
		fflush(stdin);
		scanf("%u", &especes[nEspece].pvMax);
	}
	//le nombre de PV Max doit être compris entre 1 et UINT_MAX/210 (pour éviter un dépassement de capacité lors du calcul du nombre de PC Max)
	while (especes[nEspece].pvMax < 1 || especes[nEspece].pvMax >= UINT_MAX / 210);
	//calcul du nombre de PC Max avec une multiplication par un nombre aléatoire entre 19 et 21
	especes[nEspece].pcMax = especes[nEspece].pvMax * (200 + (rand() % 21 - 10)) / 10;
	return 1;
}

/********************************************************************************************************************************************************/
/* INPUT : un tableau de structures de type espece (les espèces), un tableau de structures de type indEspece (l'index), un entier (le nombre d'espèces)	*/
/* Process : recherche séquentielle sur le nom de l'espèce dans l'index																					*/
/* OUTPUT : un entier (1 si l'espèce est trouvée, 0 sinon)																								*/
/********************************************************************************************************************************************************/
int rechercheEspece(struct espece especes[], struct indEspece index[], long nEspece)
{
	long i = nEspece - 1;
	//on fait la recherche à partir de la fin de l'index et on remonte vers le début, mais on aurait pu aussi faire l'inverse
	//tel qu'on l'a fait, la valeur de i est la position de l'espèce dans l'index si elle est trouvée, sinon i vaudra -1
	while (i >= 0 && strcmp(especes[nEspece].nomEspece, index[i].nomEspece) != 0)
	{
		i--;
	}
	return (i >= 0) ? 1 : 0;
	//on a utilisé l'opérateur ternaire pour remplacer le code ci-dessous par soucis de lisibilité, simplicité et concision, même si on ne l'a pas vu en cours
	/*
	if (i >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	*/
}

/********************************************************************************************************************************************************/
/* INPUT : un tableau de structures de type espece (les espèces), un tableau de structures de type indEspece (l'index), un entier (le nombre d'espèces)	*/
/* Process : recherche séquentielle sur le type puis sur le nom pour trouver la position d'insertion et insertion dans l'index							*/
/* OUTPUT : rien																																		*/
/********************************************************************************************************************************************************/
void insertionInd(struct espece especes[], struct indEspece index[], long nEspece)
{
	long i = nEspece - 1;
	//boucle de recherche sur le type
	while (i >= 0 && strcmp(especes[nEspece].type, index[i].type) < 0)
	{
		index[i + 1] = index[i];
		i--;
	}
	//boucle de recherche sur le nom
	while (i >= 0 && strcmp(especes[nEspece].type, index[i].type) == 0 && strcmp(especes[nEspece].nomEspece, index[i].nomEspece) < 0)
	{
		index[i + 1] = index[i];
		i--;
	}
	//insertion de l'espèce dans l'index
	strcpy(index[i + 1].type, especes[nEspece].type);
	strcpy(index[i + 1].nomEspece, especes[nEspece].nomEspece);
	index[i + 1].posI = nEspece;
}

/********************************************************************************************************************/
/* INPUT : un tableau de structures de type espece (les espèces), un long (la position de l'espèce dans le tableau)	*/
/* Process : affichage d'une espèce																					*/
/* OUTPUT : rien																									*/
/********************************************************************************************************************/
void afficheEspece(struct espece especes[], long posI)
{
	printf("Nom : %s\nType : %s\nNombre de bonbons : %u\nNombre de PV Max : %u\nNombre de PC Max : %u\n", especes[posI].nomEspece, especes[posI].type, especes[posI].bonbons, especes[posI].pvMax, especes[posI].pcMax);
}

/********************************************************************************************************************************************************************************************************************************/
/* INPUT : un vecteur de long (les positions des espèces d'un même type), un tableau de structures de type indEspece (l'index), un entier (le nombre d'espèces), un pointeur sur un long (le nombre d'espèces d'un même type)	*/
/* Process : recherche séquentielle sur le type d'une espèce dans l'index pour trouver toutes les espèces d'un même type et ajouter leur position respective dans un vecteur pour les afficher dans l'ordre alphabétique		*/
/* OUTPUT : un entier (1 si le type est trouvé, 0 sinon)																																										*/
/********************************************************************************************************************************************************************************************************************************/
int rechercheTypeEspece(long position[], struct indEspece index[], long nEspece, long* nEspeceType)
{
	long i = 0;
	int choixType = -1;
	//menu de choix du type
	do
	{
		printf("\nQuel est le type recherche ?\n1) Acier\n2) Combat\n3) Dragon\n4) Eau\n5) Electrik\n6) Fee\n7) Feu\n8) Glace\n9) Insecte\n10) Normal\n11) Plante\n12) Poison\n13) Psy\n14) Roche\n15) Sol\n16) Spectre\n17) Tenebres\n18) Vol\n");
		scanf("%d", &choixType);
	}
	while (choixType < 1 || choixType > 18);
	//recherche du type dans l'index
	while (i < nEspece && strcmp(index[i].type, types[choixType - 1]) != 0)
	{
		i++;
	}
	//si le type n'est pas trouvé, on retourne 0
	if (i == nEspece)
	{
		return 0;
	}
	//sinon on ajoute les positions des espèces du même type dans le vecteur position
	*nEspeceType = 0;
	do
	{
		position[*nEspeceType] = index[i].posI;
		i++;
		(*nEspeceType)++;
	}
	while (i < nEspece && strcmp(index[i].type, types[choixType - 1]) == 0);
	return 1;
}
