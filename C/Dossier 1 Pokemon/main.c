#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

//activate fun
#define FUN 2

#if FUN > 0
#include <Windows.h>
//add missing defines in GCC
#ifndef ENABLE_VIRTUAL_TERMINAL_INPUT
#define ENABLE_VIRTUAL_TERMINAL_INPUT 0x0200
#endif
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#ifndef DISABLE_NEWLINE_AUTO_RETURN
#define DISABLE_NEWLINE_AUTO_RETURN 0x0008
#endif
#ifndef ENABLE_LVB_GRID_WORLDWIDE
#define ENABLE_LVB_GRID_WORLDWIDE 0x0010
#endif
#define TEXT_RGB(r, g, b) "\x1b[38;2;"#r";"#g";"#b"m"
#endif

#if FUN == 1
#define FG_DARK_BLUE FOREGROUND_BLUE
#define FG_DARK_GREEN FOREGROUND_GREEN
#define FG_DARK_CYAN FG_DARK_BLUE | FG_DARK_GREEN
#define FG_DARK_RED FOREGROUND_RED
#define FG_DARK_MAGENTA FG_DARK_BLUE | FG_DARK_RED
#define FG_DARK_YELLOW FG_DARK_GREEN | FG_DARK_RED
#define FG_GREY FG_DARK_BLUE | FG_DARK_GREEN | FG_DARK_RED
#define FG_LIGHT_BLUE FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define FG_LIGHT_GREEN FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define FG_LIGHT_CYAN FG_LIGHT_BLUE | FG_LIGHT_GREEN
#define FG_LIGHT_RED FOREGROUND_RED | FOREGROUND_INTENSITY
#define FG_LIGHT_MAGENTA FG_LIGHT_BLUE | FG_LIGHT_RED
#define FG_LIGHT_YELLOW FG_LIGHT_GREEN | FG_LIGHT_RED
#define FG_WHITE FG_LIGHT_BLUE | FG_LIGHT_GREEN | FG_LIGHT_RED
#define BG_DARK_BLUE BACKGROUND_BLUE
#define BG_DARK_GREEN BACKGROUND_GREEN
#define BG_DARK_CYAN BG_DARK_BLUE | BG_DARK_GREEN
#define BG_DARK_RED BACKGROUND_RED
#define BG_DARK_MAGENTA BG_DARK_BLUE | BG_DARK_RED
#define BG_DARK_YELLOW BG_DARK_GREEN | BG_DARK_RED
#define BG_GREY BG_DARK_BLUE | BG_DARK_GREEN | BG_DARK_RED
#define BG_LIGHT_BLUE BACKGROUND_BLUE | BACKGROUND_INTENSITY
#define BG_LIGHT_GREEN BACKGROUND_GREEN | BACKGROUND_INTENSITY
#define BG_LIGHT_CYAN BG_LIGHT_BLUE | BG_LIGHT_GREEN
#define BG_LIGHT_RED BACKGROUND_RED | BACKGROUND_INTENSITY
#define BG_LIGHT_MAGENTA BG_LIGHT_BLUE | BG_LIGHT_RED
#define BG_LIGHT_YELLOW BG_LIGHT_GREEN | BG_LIGHT_RED
#define BG_WHITE BG_LIGHT_BLUE | BG_LIGHT_GREEN | BG_LIGHT_RED
#elif FUN == 2
#endif

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
#if FUN > 0
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
#if FUN == 1
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, FG_DARK_YELLOW);
	printf("   ...                                                                      \n   ..'...'..                                                                \n    ....:kkdc,.                                                             \n     ...:kOOOOko:'.                                              .,:c'...   \n       .:kOOO0OOOkd:.                                       .':ldkOOx,..    \n        .d0OOOO0OOOOko,.                               ..;cokOOOOOOOo'..    \n         ,xOOOOOOOOOOOOx:.                         .':ldkOOOOOO0OO0Oc..     \n          .lk0OOOOOOOOO0Od:...',,;;;;;;;,,,,''..':oxkOOOOOOOOOOOOOOo'       \n            ;dk0OOOOOOOOOOOkkOOOOOOO00OOOOOOOOkkOOOOOOOOOOOOOOOOOOl.        \n             .:xO0OOOOOOOOO0OOOOOOOOOOOOOOOOOOO0OOOOOOOOOOOO0OOOx;.         \n               .ldldOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkkOOOOOx:.           \n                 .lkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxddoc,.             \n                .:kOOOOOOxddkOOOOOOOOOOOOOOOOOOOkddkOOOOOkd,                \n                :kOOOOOOoco;;oOOOOOOOOOOOOOOOOOoll;;dOOOOOOd,               \n               ,xOOOOO0k;:d;.:kOOOOOOOOOOOOOO0k::d;.;k0OO0OOd'              \n              .dOOOOOOOkl,'.,lOOOOO0OOOOOOOOOOOl,..'cOOO0OOOOl.             \n              cO0OOOOOOOOkddxOOO0OdlllokOOOOOOOOxooxkOOOOOOOOx,             \n             'd0OkxxxkOOOOOOOOOO0kocc:lxOOOOOOOO0OOOOOkxxxkOOOc             \n             :Okolcccldk00OOOOOOOOO0OOO0OOOOOOOOOOOOkocclccok0d'            \n            .lOxlcclccokOOOOOOOOOkxxxxxdddxO0OOOOOOOdccclcccdOO:            \n            .lOkxoooodkOOOOOOOOOkoodxxddxolxOOOOOOOOkdllllldkOOo.           \n             :OOOOkkOOO0OOOOOOOOkloxxxxdxdoxOOOOOOOOOOkkkkkOOOOk;           \n             .oOOOOOOOOOO0OOOOOOOxooodoododkOOOOOOOOOOOOOOOOOOOOl.          \n              .oO0OOOOOOOOOOOO0OO0OkdddxxkOOOOOOOOOOOOOOOOOOOOOOd'          \n               .lOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOk;          \n                'dOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO0Ol.         \n                'x0OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOd.         \n                .collllolllllooooooooooooooooooooooooooooooolllloc.         \n");
	SetConsoleTextAttribute(hConsole, saved_attributes);
#elif FUN == 2
	DWORD dwMode;
	GetConsoleMode(hConsole, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hConsole, dwMode);
	printf(TEXT_RGB(131, 163, 227)"Hello world !\nOui, c'est une couleur custom : R131 G163 B227\n\x1b[0m");
#endif
	//welcome the user
	printf("Bienvenue dans le programme de gestion des especes de Pokemon\n");
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
			printf("\nEntrez n'importe quel caractere entre deux especes pour arreter l'affichage\nN'entrez rien pour continuer\n");
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
	printf("\nCreation d'une nouvelle espece\nN'entrez rien pour revenir au menu principal\n");
	//nom de l'espece et verification de l'unicite
	do
	{
		printf("Quel est le nom de l'espece ?\n");
		fflush(stdin);
		gets(especes[*nEspece].nomEspece);
		if (rechercheEspece(especes, index, *nEspece) == 1)
		{
			printf("Le pokemon est deja present\n");
		}
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
			scanf("%u", &especes[*nEspece].pvMax);
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
