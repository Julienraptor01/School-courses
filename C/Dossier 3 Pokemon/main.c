/************************************************************************************/
/* Auteurs : BOLLY Julien, SECCO Johan												*/
/* Groupe : 2131																	*/
/* Application : Dossier 3 Pok�mon ; Encodage, recherche et affichage des esp�ces	*/
/* Date de la derni�re modification : 16/03/2023									*/
/************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

//defines
//nombre maximum d'esp�ces
#define MAX_POKEMON 1500
//taille maximum du nom d'une esp�ce
#define MAX_TAILLE_NOM 50
//taille maximum du type d'une esp�ce
#define MAX_TAILLE_TYPE 10
//nombre de types diff�rents
#define NOMBRE_TYPES 18
//taille maximum du nom d'un pseudo
#define MAX_TAILLE_PSEUDO 50
//d�commentez la ligne ci-dessous pour activer le mode DEBUG ce qui pr�-entre des esp�ces
//#define DEBUG

//structures de donn�es
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

struct date
{
	short jour;
	short mois;
	short annee;
};

struct dresseur
{
	char pseudo[MAX_TAILLE_PSEUDO];
	unsigned int poussiereEtoile;
	unsigned long xpTotale;
	struct date dateInscription;
};

//utilisation d'une structure de stockage pour faciliter la gestion des donn�es au sein des menus et �viter de passer trop de param�tres
struct stockage
{
	struct espece especes[MAX_POKEMON];
	struct indEspece index[MAX_POKEMON];
	long nEspece;
	char* nomFichier;
	int nbDresseurs;
};

//prototypes de fonctions li�es aux menus
int menuPrincipal(struct stockage*);
int menuEspece(struct espece[], struct indEspece[], long*);
int menuDresseur(char[], int*);

//prototypes de fonctions li�es � la partie esp�ces
int encodeEspece(struct espece[], struct indEspece[], long);
int rechercheNomEspece(struct espece[], struct indEspece[], long);
void insertionIndEspece(struct espece[], struct indEspece[], long);
void afficheEspece(struct espece);
int rechercheTypeEspece(long[], struct indEspece[], long, long*);

//prototypes de fonctions li�es � la partie dresseur
int encodeDresseur(char[], int);
int rechercheDresseur(char[], char[]);
void afficheDresseur(char[], int);
void modificationPseudoDresseur(char[], char[]);

//variable globale
const char* types[] = { "Acier", "Combat", "Dragon", "Eau", "Electrik", "Fee", "Feu", "Glace", "Insecte", "Normal", "Plante", "Poison", "Psy", "Roche", "Sol", "Spectre", "Tenebres", "Vol" };

int main()
{
#ifdef DEBUG
	//structures pr�d�finies pour le mode DEBUG
	struct stockage stockage =
	{
		.especes = {
			{"Roucarnage", "Normal", 0, 30, 630},
			{"Roucoups", "Normal", 0, 20, 400},
			{"Roucool", "Normal", 0, 10, 190},
			{"Piafabec", "Normal", 0, 12, 234},
			{"Rattatac", "Normal", 0, 25, 518},
			{"Rattata", "Normal", 0, 15, 290},
			{"Draco", "Dragon", 0, 100, 2100},
			{"Carapuce", "Eau", 0, 17, 354},
			{"Pikachu", "Electrik", 0, 17, 354},
			{"Salameche", "Feu", 0, 17, 354},
			{"Bulbizarre", "Plante", 0, 17, 354},
			{"Onix", "Acier", 0, 42, 878}
		},
		.index = {
			{"Acier", "Onix", 11},
			{"Dragon", "Draco", 6},
			{"Eau", "Carapuce", 7},
			{"Electrik", "Pikachu", 8},
			{"Feu", "Salameche", 9},
			{"Normal", "Piafabec", 3},
			{"Normal", "Rattata", 5},
			{"Normal", "Rattatac", 4},
			{"Normal", "Roucarnage", 0},
			{"Normal", "Roucool", 2},
			{"Normal", "Roucoups", 1},
			{"Plante", "Bulbizarre", 10}
		},
		.nEspece = 12,
		.nomFichier = "dresseurs.dat",
		.nbDresseurs = 0
	};
#else
	struct stockage stockage =
	{
		.especes = {},
		.index = {},
		.nEspece = 0,
		.nomFichier = "dresseurs.dat",
		.nbDresseurs = 0
	};
#endif
	FILE* fDresseurs = fopen(stockage.nomFichier, "rb");
	//si le fichier existe, on r�cup�re le nombre de dresseurs
	if (fDresseurs != NULL)
	{
		fseek(fDresseurs, 0, SEEK_END);
		stockage.nbDresseurs = ftell(fDresseurs) / sizeof(struct dresseur);
	}
	//sinon on le cr�e et vu qu'on vient de le cr�er, il est vide donc la valeur initialis�e est correcte
	else
	{
		fDresseurs = fopen(stockage.nomFichier, "w+b");
	}
	fclose(fDresseurs);
	srand(time(NULL));
	printf("Bienvenue dans le programme de gestion Pokemon !\n");
	while(menuPrincipal(&stockage));
	return 0;
}

/************************************************************************************************/
/* INPUT : un pointeur sur une structure stockage (toutes les infos n�cessaires au sous-menus	*/
/* Process : affiche le menu principal et appelle les fonctions li�es aux sous-menus			*/
/* OUTPUT : un entier (0 si l'utilisateur a choisi de quitter le programme, 1 sinon)			*/
/************************************************************************************************/
int menuPrincipal(struct stockage *stockage)
{
	int choixMenu = -1;
	printf("\nQue voulez-vous faire :\n1) Gerer les especes\n2) Gerer les dresseurs\n3) Quitter le programme\n");
	fflush(stdin);
	scanf("%d", &choixMenu);
	switch (choixMenu)
	{
	case 1:
		printf("Bienvenue dans le menu de gestion des especes\n");
		while (menuEspece(stockage->especes, stockage->index, &stockage->nEspece));
		break;
	case 2:
		printf("Bienvenue dans le menu de gestion des dresseurs\n");
		while (menuDresseur(stockage->nomFichier, &stockage->nbDresseurs));
		break;
	case 3:
		printf("Vous avez choisi de quitter le programme\n");
		break;
	default:
		printf("Vous devez choisir une valeur comprise entre 1 et 3\n");
	}
	return (choixMenu != 3) ? 1 : 0;
}

/****************************************************************************************************************************************************/
/* INPUT : un vecteur d'esp�ces (la liste des esp�ces), un vecteur d'index (l'index des esp�ces), un pointeur sur un entier (le nombre d'esp�ces)	*/
/* Process : affiche le menu des esp�ces et appelle les fonctions li�es aux sous-menus																*/
/* OUTPUT : un entier (0 si l'utilisateur a choisi de quitter le programme, 1 sinon)																*/
/****************************************************************************************************************************************************/
int menuEspece(struct espece especes[], struct indEspece index[], long *nEspece)
{
	long position[MAX_POKEMON], nEspeceType = 0;
	int choixMenu = -1, i;
	char arreteAffiche[] = "";
	//boucle de menu
	printf("\nQue voulez-vous faire :\n1) Ajouter une espece\n2) Afficher les especes\n3) Rechercher les pokemons d'un meme type\n4) Retour au menu principal\n");
	fflush(stdin);
	scanf("%d", &choixMenu);
	switch (choixMenu)
	{
	//ajout d'une esp�ce
	case 1:
		while (*nEspece < MAX_POKEMON && encodeEspece(especes, index, *nEspece) == 1)
		{
			//appel de la fonction d'insertion dans l'index
			insertionIndEspece(especes, index, *nEspece);
			//incrementation de la valeur de nEspece
			(*nEspece)++;
		}
		break;
	//affichage des esp�ces
	case 2:
		i = 0;
		strcpy(arreteAffiche, "");
		printf("\nEntrez n'importe quel caractere entre deux especes pour arreter l'affichage\nN'entrez rien pour continuer\n");
		while (i < *nEspece && strlen(arreteAffiche) == 0)
		{
			afficheEspece(especes[index[i].posI]);
			i++;
			fflush(stdin);
			gets(arreteAffiche);
		}
		break;
	case 3:
		if (rechercheTypeEspece(position, index, *nEspece, &nEspeceType) == 1)
		{
			i = 0;
			strcpy(arreteAffiche, "");
			printf("\nEntrez n'importe quel caractere entre deux especes pour arreter l'affichage\nN'entrez rien pour continuer\n");
			while (i < nEspeceType && strlen(arreteAffiche) == 0)
			{
				afficheEspece(especes[position[i]]);
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
	//quitter le menu
	case 4:
		printf("Vous avez choisi de retourner au menu principal\n");
		break;
	//cas d'erreur
	default:
		printf("Vous devez choisir une valeur comprise entre 1 et 4\n");
	}
	return (choixMenu != 4) ? 1 : 0;
}

/************************************************************************************************************************************/
/* INPUT : un vecteur de caract�res (le nom du fichier contenant les dresseurs), un pointeur sur un entier (le nombre de dresseurs) */
/* Process : affiche le menu des dresseurs et appelle les fonctions li�es aux sous-menus											*/
/* OUTPUT : un entier (0 si l'utilisateur a choisi de quitter le programme, 1 sinon)												*/
/************************************************************************************************************************************/
int menuDresseur(char nomFichier[], int *nDresseurs)
{
	int choixMenu = -1, encode = 0, i, position;
	char arreteAffiche[] = "", pseudo[MAX_TAILLE_PSEUDO];
	printf("\nQue voulez-vous faire :\n1) Inscrire un dresseur\n2) Afficher les dresseurs\n3) Rechercher un dresseur\n4) Modifier le pseudo d'un dresseur\n5) Retour au menu principal\n");
	fflush(stdin);
	scanf("%d", &choixMenu);
	switch (choixMenu)
	{
	//inscription d'un dresseur
	case 1:
		printf("\nCreation d'un nouveau dresseur\nN'entrez rien pour revenir au menu de gestion des dresseurs\n");
		//boucle de creation de dresseur
		while ((encode = encodeDresseur(nomFichier, *nDresseurs)) >= -1)
		{
			//si le pseudo n'est pas deja utilise -> incr�mentation du nombre de dresseurs
			if (encode == -1)
			{
				(*nDresseurs)++;
				printf("\nCreation d'un nouveau dresseur\nN'entrez rien pour revenir au menu de gestion des dresseurs\n");
			}
			//si le pseudo est deja utilise -> message pour l'utilisateur
			else
			{
				printf("\nCe pseudo est deja utilise\nEntrez-en un autre\n");
			}
		}
		break;
	//affichage des dresseurs
	case 2:
		i = 0;
		strcpy(arreteAffiche, "");
		printf("\nEntrez n'importe quel caractere entre deux dresseurs pour arreter l'affichage\nN'entrez rien pour continuer\n");
		while (i < *nDresseurs && strlen(arreteAffiche) == 0)
		{
			afficheDresseur(nomFichier, i);
			i++;
			fflush(stdin);
			gets(arreteAffiche);
		}
		break;
	//recherche et affichage d'un dresseur
	case 3:
		printf("Entrez le pseudo du dresseur que vous recherchez ou n'entrez rien pour revenir au menu de gestion des dresseurs\n");
		fflush(stdin);
		gets(pseudo);
		if (strlen(pseudo) == 0)
		{
			printf("Retour au menu de gestion des dresseurs\n");
		}
		else
		{
			switch (position = rechercheDresseur(pseudo, nomFichier))
			{
			case -1:
				printf("Le dresseur n'a pas ete trouve\n");
				break;
			default:
				afficheDresseur(nomFichier, position);
				break;
			}
		}
		break;
	//modification d'un dresseur
	case 4:
		printf("Entrez le pseudo du dresseur que vous souhaitez modifier ou n'entrez rien pour revenir au menu de gestion des dresseurs\n");
		fflush(stdin);
		gets(pseudo);
		if (strlen(pseudo) == 0)
		{
			printf("Retour au menu de gestion des dresseurs\n");
		}
		else
		{
			modificationPseudoDresseur(pseudo, nomFichier);
		}
		break;
	//quitter le menu
	case 5:
		printf("Vous avez choisi de retourner au menu principal\n");
		break;
	//cas d'erreur
	default:
		printf("Vous devez choisir une valeur comprise entre 1 et 5\n");
	}
	return (choixMenu != 5) ? 1 : 0;
}

/************************************************************************************************************************************************************************/
/* INPUT : un tableau de structures de type espece (les esp�ces), un tableau de structures de type indEspece (l'index), un pointeur sur un entier (le nombre d'esp�ces)	*/
/* Process : r�cup�re les informations sur une nouvelle esp�ce, v�rifie l'unicit� de l'esp�ce et l'ajoute � la liste													*/
/* OUTPUT : un entier (1 si une nouvelle esp�ce a �t� ajout�e, 0 sinon)																									*/
/************************************************************************************************************************************************************************/
int encodeEspece(struct espece especes[], struct indEspece index[], long nEspece)
{
	int choixType = -1, especeExiste = -1;
	printf("\nCreation d'une nouvelle espece\nN'entrez rien pour revenir au menu de gestion des especes\n");
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
		//v�rification de l'unicit� de l'esp�ce
		else if ((especeExiste = rechercheNomEspece(especes, index, nEspece)) == 1)
		{
			printf("Le pokemon est deja present\n");
		}
	}
	while (especeExiste == 1);
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
	//initialiser les bonbons � 0
	especes[nEspece].bonbons = 0;
	//demander le nombre de PV Max
	do
	{
		printf("Quel est le nombre de PV Max ?\n");
		fflush(stdin);
		scanf("%u", &especes[nEspece].pvMax);
	}
	//le nombre de PV Max doit �tre compris entre 1 et UINT_MAX/210 (pour �viter un d�passement de capacit� lors du calcul du nombre de PC Max)
	while (especes[nEspece].pvMax < 1 || especes[nEspece].pvMax >= UINT_MAX / 210);
	//calcul du nombre de PC Max avec une multiplication par un nombre al�atoire entre 19 et 21
	especes[nEspece].pcMax = especes[nEspece].pvMax * (200 + (rand() % 21 - 10)) / 10;
	return 1;
}

/********************************************************************************************************************************************************/
/* INPUT : un tableau de structures de type espece (les esp�ces), un tableau de structures de type indEspece (l'index), un entier (le nombre d'esp�ces)	*/
/* Process : recherche s�quentielle sur le nom de l'esp�ce dans l'index																					*/
/* OUTPUT : un entier (1 si l'esp�ce est trouv�e, 0 sinon)																								*/
/********************************************************************************************************************************************************/
int rechercheNomEspece(struct espece especes[], struct indEspece index[], long nEspece)
{
	long i = nEspece - 1;
	//on fait la recherche � partir de la fin de l'index et on remonte vers le d�but, mais on aurait pu aussi faire l'inverse
	//tel qu'on l'a fait, la valeur de i est la position de l'esp�ce dans l'index si elle est trouv�e, sinon i vaudra -1
	while (i >= 0 && strcmp(especes[nEspece].nomEspece, index[i].nomEspece) != 0)
	{
		i--;
	}
	return (i >= 0) ? 1 : 0;
	//on a utilis� l'op�rateur ternaire par soucis de lisibilit�, simplicit� et concision, m�me si on ne l'a pas vu en cours
}

/********************************************************************************************************************************************************/
/* INPUT : un tableau de structures de type espece (les esp�ces), un tableau de structures de type indEspece (l'index), un entier (le nombre d'esp�ces)	*/
/* Process : recherche s�quentielle sur le type puis sur le nom pour trouver la position d'insertion et insertion dans l'index							*/
/* OUTPUT : rien																																		*/
/********************************************************************************************************************************************************/
void insertionIndEspece(struct espece especes[], struct indEspece index[], long nEspece)
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
	//insertion de l'esp�ce dans l'index
	strcpy(index[i + 1].type, especes[nEspece].type);
	strcpy(index[i + 1].nomEspece, especes[nEspece].nomEspece);
	index[i + 1].posI = nEspece;
}

/****************************************************/
/* INPUT : une structure de type espece (l'esp�ce)	*/
/* Process : affichage d'une esp�ce					*/
/* OUTPUT : rien									*/
/****************************************************/
void afficheEspece(struct espece espece)
{
	printf("Nom : %s\nType : %s\nNombre de bonbons : %u\nNombre de PV Max : %u\nNombre de PC Max : %u\n", espece.nomEspece, espece.type, espece.bonbons, espece.pvMax, espece.pcMax);
}

/********************************************************************************************************************************************************************************************************************************/
/* INPUT : un vecteur de long (les positions des esp�ces d'un m�me type), un tableau de structures de type indEspece (l'index), un entier (le nombre d'esp�ces), un pointeur sur un long (le nombre d'esp�ces d'un m�me type)	*/
/* Process : recherche s�quentielle sur le type d'une esp�ce dans l'index pour trouver toutes les esp�ces d'un m�me type et ajouter leur position respective dans un vecteur pour les afficher dans l'ordre alphab�tique		*/
/* OUTPUT : un entier (1 si le type est trouv�, 0 sinon)																																										*/
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
	//si le type n'est pas trouv�, on retourne 0
	if (i == nEspece)
	{
		return 0;
	}
	//sinon on ajoute les positions des esp�ces du m�me type dans le vecteur position
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

/************************************************************************************************************************************************************************/
/* INPUT : un vecteur de caract�res (le nom du fichier), un entier (la position o� aller encoder le dresseur)															*/
/* Process : demande le pseudo du dresseur, v�rifie qu'il n'est pas d�j� utilis�, g�n�re un nombre al�atoire de poussi�res d'�toile, encode le dresseur dans le fichier	*/
/* OUTPUT : un entier (soit -2 si le pseudo est vide, soit la position du dresseur si le pseudo est d�j� utilis�, soit -1 si l'encodage a r�ussi) 						*/
/************************************************************************************************************************************************************************/
int encodeDresseur(char nomFichier[], int position)
{
	struct dresseur dress = { 0 };
	int positionTrouve;
	//on demande le pseudo du dresseur
	printf("\nPseudo : ");
	fflush(stdin);
	gets(dress.pseudo);
	//si le pseudo est vide, on retourne -2
	if (strlen(dress.pseudo) == 0)
	{
		return -2;
	}
	//sinon on v�rifie que le pseudo n'est pas d�j� utilis�
	else if ((positionTrouve = rechercheDresseur(dress.pseudo, nomFichier)) >= 0)
	{
		return positionTrouve;
	}
	//on rempli le champ poussiereEtoile avec un nombre al�atoire entre 20k et 40k
	dress.poussiereEtoile = rand() % 20001 + 20000;
	//on set le champ xpTotale � 0
	dress.xpTotale = 0;
	time_t rawDate = time(NULL);
	struct tm* date = localtime(&rawDate);
	//on met le champ dateInscritption � la date du jour
	dress.dateInscription.jour = date->tm_mday;
	dress.dateInscription.mois = date->tm_mon + 1;
	dress.dateInscription.annee = date->tm_year + 1900;
	//ecriture du dresseur dans le fichier
	FILE* fDresseurs = fopen(nomFichier, "r+b");
	fseek(fDresseurs, position * sizeof(struct dresseur), SEEK_SET);
	fwrite(&dress, sizeof(struct dresseur), 1, fDresseurs);
	fclose(fDresseurs);
	return -1;
}

/************************************************************************************************************/
/* INPUT : un vecteur de caract�res (le pseudo du dresseur), un vecteur de caract�res (le nom du fichier)	*/
/* Process : recherche s�quentielle sur le pseudo du dresseur dans le fichier pour trouver sa position		*/
/* OUTPUT : un entier (la position du dresseur si il est trouv�, -1 sinon)									*/
/************************************************************************************************************/
int rechercheDresseur(char pseudo[], char nomFichier[])
{
	struct dresseur dress = { 0 };
	int position = 0;
	FILE* fDresseurs = fopen(nomFichier, "rb");
	//boucle de recherche sur le pseudo
	while (fread(&dress, sizeof(struct dresseur), 1, fDresseurs) == 1)
	{
		if (strcmp(dress.pseudo, pseudo) == 0)
		{
			fclose(fDresseurs);
			return position;
		}
		position++;
	}
	fclose(fDresseurs);
	return -1;
}

/********************************************************************************************************/
/* INPUT : un vecteur de caract�res (le nom du fichier), un entier (la position du dresseur � afficher)	*/
/* Process : lit le dresseur � la position donn�e dans le fichier et l'affiche							*/
/* OUTPUT : rien																						*/
/********************************************************************************************************/
void afficheDresseur(char nomFichier[], int position)
{
	struct dresseur dress = { 0 };
	FILE* fDresseurs = fopen(nomFichier, "rb");
	fseek(fDresseurs, position * sizeof(struct dresseur), SEEK_SET);
	fread(&dress, sizeof(struct dresseur), 1, fDresseurs);
	fclose(fDresseurs);
	//affichage du dresseur
	printf("Pseudo : %s\nPoussiere d'etoile : %u\nXP totale : %lu\nDate d'inscription : %hd/%hd/%hd\n", dress.pseudo, dress.poussiereEtoile, dress.xpTotale, dress.dateInscription.jour, dress.dateInscription.mois, dress.dateInscription.annee);
	//dans les consignes du TP, il est demand� d'afficher la date au format Jour Mois valeurJour Heure:Minute:Seconde Ann�e (ex : Tue May 26 21:30:00 2015), mais c'est impossible ici vu que la structure date impos�e ne contient pas de champ pour les heures, minutes et secondes
}

/********************************************************************************************************************************************************************************************************************************/
/* INPUT : un vecteur de caract�res (le pseudo du dresseur � modifier), un vecteur de caract�res (le nom du fichier)																											*/
/* Process : apelle la recherche, et si le dresseur est trouv�, appelle la fonction encodeDresseur pour le modifier, puis en fonction du retour de cette fonction, affiche un message pour indiquer l'�tat de la modification	*/
/* OUTPUT : rien																																																				*/
/********************************************************************************************************************************************************************************************************************************/
void modificationPseudoDresseur(char pseudo[], char nomFichier[])
{
	int positionRemplacement, positionTrouve;
	//recherche du dresseur
	if ((positionRemplacement = rechercheDresseur(pseudo, nomFichier)) == -1)
	{
		printf("Ce dresseur n'existe pas\n");
	}
	else
	{
		//verification du r�sultat de la modification et information de l'utilisateur
		switch (positionTrouve = encodeDresseur(nomFichier, positionRemplacement))
		{
		case -2:
			printf("Vous avez annule la modification\n");
			break;
		case -1:
			printf("Modification effectuee\n");
			break;
		default:
			//si le pseudo est d�j� utilis�, on v�rifie si c'est le m�me que celui qu'on veut modifier pour afficher un message adapt�
			if (positionTrouve == positionRemplacement)
			{
				printf("Vous avez remplace par le meme pseudo\n");
			}
			else
			{
				printf("Ce pseudo est deja utilise\n");
			}
		}
	}
}
