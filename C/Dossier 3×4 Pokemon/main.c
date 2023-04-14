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
//taille maximum du nom d'un pseudo
#define MAX_TAILLE_PSEUDO 50

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
	struct indEspece* psvt; //psvt = Pointeur SuiVanT
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

//utilisation d'une structure de stockage pour faciliter la gestion des données au sein des menus et éviter de passer trop de paramètres
struct stockage
{
	char* nomFichierEspece;
	struct indEspece* teteIndex;
	long nEspece;
	char* nomFichierDresseur;
	int nbDresseurs;
};

//prototypes de fonctions liées aux menus
int menuPrincipal(struct stockage*);
int menuEspece(char[], struct indEspece**, long*);
int menuDresseur(char[], int*);

//prototypes de fonctions liées à la partie espèces
int encodeEspece(char[], struct indEspece**, long);
int rechercheNomEspece(char[], struct indEspece*);
void insertionInd(struct espece, struct indEspece**, long);
void suppressionInd(char[], struct indEspece**);
void afficheEspece(struct espece);
int rechercheTypeEspece(long[], struct indEspece*, long*);

//prototypes de fonctions liées à la partie dresseur
int encodeDresseur(char[], int);
int rechercheDresseur(char[], char[]);
void afficheDresseur(char[], int);
void modificationPseudoDresseur(char[], char[]);

//variable globale
const char* types[] = { "Acier", "Combat", "Dragon", "Eau", "Electrik", "Fee", "Feu", "Glace", "Insecte", "Normal", "Plante", "Poison", "Psy", "Roche", "Sol", "Spectre", "Tenebres", "Vol" };

int main()
{
	struct stockage stockage =
	{
		.nomFichierEspece = "especes.dat",
		.teteIndex = NULL,
		.nEspece = 0,
		.nomFichierDresseur = "dresseurs.dat",
		.nbDresseurs = 0
	};
	struct espece espece;
	FILE* fEspeces = fopen(stockage.nomFichierEspece, "rb");
	//si le fichier existe, on récupère le nombre d'espèces
	if (fEspeces != NULL)
	{
		//création index et initialisation du nombre d'espèces si nécessaire
		while (fread(&espece, sizeof(struct espece), 1, fEspeces) == 1)
		{
			insertionInd(espece, &stockage.teteIndex, stockage.nEspece);
			stockage.nEspece++;
		}
	}
	//sinon on le crée et vu qu'on vient de le créer, il est vide donc la valeur initialisée est correcte
	else
	{
		fEspeces = fopen(stockage.nomFichierEspece, "wb");
	}
	fclose(fEspeces);
	FILE* fDresseurs = fopen(stockage.nomFichierDresseur, "rb");
	//si le fichier existe, on récupère le nombre de dresseurs
	if (fDresseurs != NULL)
	{
		fseek(fDresseurs, 0, SEEK_END);
		stockage.nbDresseurs = ftell(fDresseurs) / sizeof(struct dresseur);
	}
	//sinon on le crée et vu qu'on vient de le créer, il est vide donc la valeur initialisée est correcte
	else
	{
		fDresseurs = fopen(stockage.nomFichierDresseur, "wb");
	}
	fclose(fDresseurs);
	srand(time(NULL));
	printf("Bienvenue dans le programme de gestion Pokemon !\n");
	while (menuPrincipal(&stockage));
	return 0;
}

/************************************************************************************************/
/* INPUT : un pointeur sur une structure stockage (toutes les infos nécessaires au sous-menus	*/
/* Process : affiche le menu principal et appelle les fonctions liées aux sous-menus			*/
/* OUTPUT : un entier (0 si l'utilisateur a choisi de quitter le programme, 1 sinon)			*/
/************************************************************************************************/
int menuPrincipal(struct stockage* stockage)
{
	int choixMenu = -1;
	printf("\nQue voulez-vous faire :\n1) Gerer les especes\n2) Gerer les dresseurs\n3) Quitter le programme\n");
	fflush(stdin);
	scanf("%d", &choixMenu);
	switch (choixMenu)
	{
	case 1:
		printf("Bienvenue dans le menu de gestion des especes\n");
		while (menuEspece(stockage->nomFichierEspece, &stockage->teteIndex, &stockage->nEspece));
		break;
	case 2:
		printf("Bienvenue dans le menu de gestion des dresseurs\n");
		while (menuDresseur(stockage->nomFichierDresseur, &stockage->nbDresseurs));
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
/* INPUT : un vecteur d'espèces (la liste des espèces), un vecteur d'index (l'index des espèces), un pointeur sur un entier (le nombre d'espèces)	*/
/* Process : affiche le menu des espèces et appelle les fonctions liées aux sous-menus																*/
/* OUTPUT : un entier (0 si l'utilisateur a choisi de quitter le programme, 1 sinon)																*/
/****************************************************************************************************************************************************/
int menuEspece(char nomFichierEspece[], struct indEspece** teteIndex, long* nEspece)
{
	long position[MAX_POKEMON], nEspeceType = 0;
	int choixMenu = -1, i;
	char arreteAffiche[] = "";
	struct espece espece;
	struct indEspece* actuel;
	printf("\nQue voulez-vous faire :\n1) Ajouter une espece\n2) Afficher les especes\n3) Rechercher les pokemons d'un meme type\n4) Retour au menu principal\n");
	fflush(stdin);
	scanf("%d", &choixMenu);
	switch (choixMenu)
	{
	//ajout d'une espèce
	case 1:
		while (*nEspece < MAX_POKEMON && encodeEspece(nomFichierEspece, teteIndex, *nEspece) == 1)
		{
			//incrementation de la valeur de nEspece
			(*nEspece)++;
		}
		break;
	//affichage des espèces
	case 2:
		actuel = *teteIndex;
		strcpy(arreteAffiche, "");
		printf("\nEntrez n'importe quel caractere entre deux especes pour arreter l'affichage\nN'entrez rien pour continuer\n");
		FILE* fEspeces = fopen(nomFichierEspece, "rb");
		while (actuel != NULL && strlen(arreteAffiche) == 0)
		{
			fseek(fEspeces, sizeof(struct espece) * actuel->posI, SEEK_SET);
			fread(&espece, sizeof(struct espece), 1, fEspeces);
			afficheEspece(espece);
			actuel = actuel->psvt;
			fflush(stdin);
			gets(arreteAffiche);
		}
		fclose(fEspeces);
		break;
	case 3:
		if (rechercheTypeEspece(position, *teteIndex, &nEspeceType) == 1)
		{
			i = 0;
			strcpy(arreteAffiche, "");
			printf("\nEntrez n'importe quel caractere entre deux especes pour arreter l'affichage\nN'entrez rien pour continuer\n");
			fEspeces = fopen(nomFichierEspece, "rb");
			while (i < nEspeceType && strlen(arreteAffiche) == 0)
			{
				fseek(fEspeces, sizeof(struct espece) * position[i], SEEK_SET);
				fread(&espece, sizeof(struct espece), 1, fEspeces);
				afficheEspece(espece);
				i++;
				fflush(stdin);
				gets(arreteAffiche);
			}
			fclose(fEspeces);
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
/* INPUT : un vecteur de caractères (le nom du fichier contenant les dresseurs), un pointeur sur un entier (le nombre de dresseurs) */
/* Process : affiche le menu des dresseurs et appelle les fonctions liées aux sous-menus											*/
/* OUTPUT : un entier (0 si l'utilisateur a choisi de quitter le programme, 1 sinon)												*/
/************************************************************************************************************************************/
int menuDresseur(char nomFichierDresseur[], int *nDresseurs)
{
	int choixMenu = -1, encode = 0, i, position = -2;
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
		while ((encode = encodeDresseur(nomFichierDresseur, *nDresseurs)) >= -1)
		{
			//si le pseudo n'est pas deja utilise -> incrémentation du nombre de dresseurs
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
			afficheDresseur(nomFichierDresseur, i);
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
			switch (position = rechercheDresseur(pseudo, nomFichierDresseur))
			{
			case -1:
				printf("Le dresseur n'a pas ete trouve\n");
				break;
			default:
				afficheDresseur(nomFichierDresseur, position);
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
			modificationPseudoDresseur(pseudo, nomFichierDresseur);
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
/* INPUT : un tableau de structures de type espece (les espèces), un tableau de structures de type indEspece (l'index), un pointeur sur un entier (le nombre d'espèces)	*/
/* Process : récupère les informations sur une nouvelle espèce, vérifie l'unicité de l'espèce, l'ajoute à la liste et appelle l'ajout à l'index							*/
/* OUTPUT : un entier (1 si une nouvelle espèce a été ajoutée, 0 sinon)																									*/
/************************************************************************************************************************************************************************/
int encodeEspece(char nomFichierEspece[], struct indEspece **teteIndex, long nEspece)
{
	struct espece espece = { 0 };
	int choixType = -1, especeExiste = -1;
	printf("\nCreation d'une nouvelle espece\nN'entrez rien pour revenir au menu de gestion des especes\n");
	//nom de l'espece
	do
	{
		printf("Quel est le nom de l'espece ?\n");
		fflush(stdin);
		gets(espece.nomEspece);
		//sortie si le nom est vide
		if (strlen(espece.nomEspece) == 0)
		{
			return 0;
		}
		//vérification de l'unicité de l'espèce
		else if ((especeExiste = rechercheNomEspece(espece.nomEspece, *teteIndex)) == 1)
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
	strcpy(espece.type, types[choixType - 1]);
	//initialiser les bonbons à 0
	espece.bonbons = 0;
	//demander le nombre de PV Max
	do
	{
		printf("Quel est le nombre de PV Max ?\n");
		fflush(stdin);
		scanf("%u", &espece.pvMax);
	}
	//le nombre de PV Max doit être compris entre 1 et UINT_MAX/210 (pour éviter un dépassement de capacité lors du calcul du nombre de PC Max)
	while (espece.pvMax < 1 || espece.pvMax >= UINT_MAX / 210);
	//calcul du nombre de PC Max avec une multiplication par un nombre aléatoire entre 19 et 21
	espece.pcMax = espece.pvMax * (200 + (rand() % 21 - 10)) / 10;
	FILE* fEspeces = fopen(nomFichierEspece, "ab");
	fwrite(&espece, sizeof(struct espece), 1, fEspeces);
	fclose(fEspeces);
	//appel de la fonction d'insertion dans l'index
	insertionInd(espece, teteIndex, nEspece);
	return 1;
}

/********************************************************************************************************************************************************/
/* INPUT : un tableau de structures de type espece (les espèces), un tableau de structures de type indEspece (l'index), un entier (le nombre d'espèces)	*/
/* Process : recherche séquentielle sur le nom de l'espèce dans l'index																					*/
/* OUTPUT : un entier (1 si l'espèce est trouvée, 0 sinon)																								*/
/********************************************************************************************************************************************************/
int rechercheNomEspece(char nomEspece[], struct indEspece* teteIndex)
{
	struct indEspece* actuel = teteIndex;
	while (actuel != NULL && strcmp(nomEspece, actuel->nomEspece) != 0)
	{
		actuel = actuel->psvt;
	}
	return (actuel != NULL) ? 1 : 0;
}

/********************************************************************************************************************************************************/
/* INPUT : un tableau de structures de type espece (les espèces), un tableau de structures de type indEspece (l'index), un entier (le nombre d'espèces)	*/
/* Process : recherche séquentielle sur le type puis sur le nom pour trouver la position d'insertion et insertion dans l'index							*/
/* OUTPUT : rien																																		*/
/********************************************************************************************************************************************************/
void insertionInd(struct espece espece, struct indEspece** teteIndex, long nEspece)
{
	struct indEspece* nouvelElement = (struct indEspece*)malloc(sizeof(struct indEspece));
	strcpy(nouvelElement->type, espece.type);
	strcpy(nouvelElement->nomEspece, espece.nomEspece);
	nouvelElement->posI = nEspece;
	if (*teteIndex == NULL)
	{
		nouvelElement->psvt = NULL;
		*teteIndex = nouvelElement;
	}
	else
	{
		struct indEspece* actuel = *teteIndex;
		struct indEspece* precedent = NULL;
		while (actuel != NULL && strcmp(espece.type, actuel->type) > 0)
		{
			precedent = actuel;
			actuel = actuel->psvt;
		}
		while (actuel != NULL && strcmp(espece.type, actuel->type) == 0 && strcmp(espece.nomEspece, actuel->nomEspece) > 0)
		{
			precedent = actuel;
			actuel = actuel->psvt;
		}
		nouvelElement->psvt = actuel;
		if (precedent == NULL)
		{
			*teteIndex = nouvelElement;
		}
		else
		{
			precedent->psvt = nouvelElement;
		}
	}
}

void suppressionInd(char nomEspece[], struct indEspece** teteIndex)
{
	struct indEspece* actuel = *teteIndex;
	struct indEspece* precedent = NULL;
	while (actuel != NULL && strcmp(nomEspece, actuel->nomEspece) > 0)
	{
		precedent = actuel;
		actuel = actuel->psvt;
	}
	if (precedent == NULL)
	{
		*teteIndex = actuel->psvt;
	}
	else
	{
		precedent->psvt = actuel->psvt;
	}
	free(actuel);
}

/****************************************************/
/* INPUT : une structure de type espece (l'espèce)	*/
/* Process : affichage d'une espèce					*/
/* OUTPUT : rien									*/
/****************************************************/
void afficheEspece(struct espece espece)
{
	printf("Nom : %s\nType : %s\nNombre de bonbons : %u\nNombre de PV Max : %u\nNombre de PC Max : %u\n", espece.nomEspece, espece.type, espece.bonbons, espece.pvMax, espece.pcMax);
}

/********************************************************************************************************************************************************************************************************************************/
/* INPUT : un vecteur de long (les positions des espèces d'un même type), un tableau de structures de type indEspece (l'index), un entier (le nombre d'espèces), un pointeur sur un long (le nombre d'espèces d'un même type)	*/
/* Process : recherche séquentielle sur le type d'une espèce dans l'index pour trouver toutes les espèces d'un même type et ajouter leur position respective dans un vecteur pour les afficher dans l'ordre alphabétique		*/
/* OUTPUT : un entier (1 si le type est trouvé, 0 sinon)																																										*/
/********************************************************************************************************************************************************************************************************************************/
int rechercheTypeEspece(long position[], struct indEspece *index, long* nEspeceType)
// TODO : rework to remove the nEspece parameter
{
	int choixType = -1;
	//menu de choix du type
	do
	{
		printf("\nQuel est le type recherche ?\n1) Acier\n2) Combat\n3) Dragon\n4) Eau\n5) Electrik\n6) Fee\n7) Feu\n8) Glace\n9) Insecte\n10) Normal\n11) Plante\n12) Poison\n13) Psy\n14) Roche\n15) Sol\n16) Spectre\n17) Tenebres\n18) Vol\n");
		scanf("%d", &choixType);
	}
	while (choixType < 1 || choixType > 18);
	//recherche du type dans l'index
	struct indEspece* actuel = index;
	while (actuel != NULL && strcmp(actuel->type, types[choixType - 1]) != 0)
	{
		actuel = actuel->psvt;
	}
	//si le type n'est pas trouvé, on retourne 0
	if (actuel == NULL)
	{
		return 0;
	}
	//sinon on ajoute les positions des espèces du même type dans le vecteur position
	*nEspeceType = 0;
	do
	{
		position[*nEspeceType] = actuel->posI;
		actuel = actuel->psvt;
		(*nEspeceType)++;
	}
	while (actuel != NULL && strcmp(actuel->type, types[choixType - 1]) == 0);
	return 1;
}


/************************************************************************************************************************************************************************/
/* INPUT : un vecteur de caractères (le nom du fichier), un entier (la position où aller encoder le dresseur)															*/
/* Process : demande le pseudo du dresseur, vérifie qu'il n'est pas déjà utilisé, génère un nombre aléatoire de poussières d'étoile, encode le dresseur dans le fichier	*/
/* OUTPUT : un entier (soit -2 si le pseudo est vide, soit la position du dresseur si le pseudo est déjà utilisé, soit -1 si l'encodage a réussi) 						*/
/************************************************************************************************************************************************************************/
int encodeDresseur(char nomFichierDresseur[], int position)
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
	//sinon on vérifie que le pseudo n'est pas déjà utilisé
	else if ((positionTrouve = rechercheDresseur(dress.pseudo, nomFichierDresseur)) >= 0)
	{
		return positionTrouve;
	}
	//on rempli le champ poussiereEtoile avec un nombre aléatoire entre 20k et 40k
	dress.poussiereEtoile = rand() % 20001 + 20000;
	//on set le champ xpTotale à 0
	dress.xpTotale = 0;
	time_t rawDate = time(NULL);
	struct tm* date = localtime(&rawDate);
	//on met le champ dateInscritption à la date du jour
	dress.dateInscription.jour = date->tm_mday;
	dress.dateInscription.mois = date->tm_mon + 1;
	dress.dateInscription.annee = date->tm_year + 1900;
	//ecriture du dresseur dans le fichier
	FILE* fDresseurs = fopen(nomFichierDresseur, "r+b");
	fseek(fDresseurs, position * sizeof(struct dresseur), SEEK_SET);
	fwrite(&dress, sizeof(struct dresseur), 1, fDresseurs);
	fclose(fDresseurs);
	return -1;
}

/************************************************************************************************************/
/* INPUT : un vecteur de caractères (le pseudo du dresseur), un vecteur de caractères (le nom du fichier)	*/
/* Process : recherche séquentielle sur le pseudo du dresseur dans le fichier pour trouver sa position		*/
/* OUTPUT : un entier (la position du dresseur si il est trouvé, -1 sinon)									*/
/************************************************************************************************************/
int rechercheDresseur(char pseudo[], char nomFichierDresseur[])
{
	struct dresseur dress = { 0 };
	int position = 0;
	FILE* fDresseurs = fopen(nomFichierDresseur, "rb");
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
/* INPUT : un vecteur de caractères (le nom du fichier), un entier (la position du dresseur à afficher)	*/
/* Process : lit le dresseur à la position donnée dans le fichier et l'affiche							*/
/* OUTPUT : rien																						*/
/********************************************************************************************************/
void afficheDresseur(char nomFichierDresseur[], int position)
{
	struct dresseur dress = { 0 };
	FILE* fDresseurs = fopen(nomFichierDresseur, "rb");
	fseek(fDresseurs, position * sizeof(struct dresseur), SEEK_SET);
	fread(&dress, sizeof(struct dresseur), 1, fDresseurs);
	fclose(fDresseurs);
	//affichage du dresseur
	printf("Pseudo : %s\nPoussiere d'etoile : %u\nXP totale : %lu\nDate d'inscription : %hd/%hd/%hd\n", dress.pseudo, dress.poussiereEtoile, dress.xpTotale, dress.dateInscription.jour, dress.dateInscription.mois, dress.dateInscription.annee);
	//dans les consignes du TP, il est demandé d'afficher la date au format Jour Mois valeurJour Heure:Minute:Seconde Année (ex : Tue May 26 21:30:00 2015), mais c'est impossible ici vu que la structure date imposée ne contient pas de champ pour les heures, minutes et secondes
}

/********************************************************************************************************************************************************************************************************************************/
/* INPUT : un vecteur de caractères (le pseudo du dresseur à modifier), un vecteur de caractères (le nom du fichier)																											*/
/* Process : apelle la recherche, et si le dresseur est trouvé, appelle la fonction encodeDresseur pour le modifier, puis en fonction du retour de cette fonction, affiche un message pour indiquer l'état de la modification	*/
/* OUTPUT : rien																																																				*/
/********************************************************************************************************************************************************************************************************************************/
void modificationPseudoDresseur(char pseudo[], char nomFichierDresseur[])
{
	int positionRemplacement, positionTrouve = -3;
	//recherche du dresseur
	if ((positionRemplacement = rechercheDresseur(pseudo, nomFichierDresseur)) == -1)
	{
		printf("Ce dresseur n'existe pas\n");
	}
	else
	{
		//verification du résultat de la modification et information de l'utilisateur
		switch (positionTrouve = encodeDresseur(nomFichierDresseur, positionRemplacement))
		{
		case -2:
			printf("Vous avez annule la modification\n");
			break;
		case -1:
			printf("Modification effectuee\n");
			break;
		default:
			//si le pseudo est déjà utilisé, on vérifie si c'est le même que celui qu'on veut modifier pour afficher un message adapté
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
