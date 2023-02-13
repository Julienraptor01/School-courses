#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct date
{
	short jour; // [00..31]
	short mois; // [00.12]
	short annee; // [1800..]
} date;

typedef struct dresseur
{
	char pseudo[50]; // IDENTIFIANT NOT NULL
	unsigned int poussiereEtoile; // >=0
	unsigned long xpTotale; // >=0
	date dateInscription; // NOT NULL, <= date du jour
} dresseur;

typedef struct pokemon
{
	long idPokemon; // IDENTIFIANT NOT NULL autoincrement autorise
	char nom[50]; // NOT NULL, par defaut le nom de l'espece
	char genre; // {X,M,F}
	unsigned int PV; // NOT NULL, >=0
	unsigned int PC; // NOT NULL, >0, ne varie pas
	char lieuCapture[50]; // {a-zA-Z_-. '}
	long dateCapture; // <= timestamp actuel
	char nomEspece[50]; // FK NOT NULL, existe dans espece
	char pseudo[50]; // FK NOT NULL, existe dans dresseur
} pokemon;

typedef struct espece
{
	char nomEspece[50]; // IDENTIFIANT NOT NULL autoincrement autorise
	char type[10]; // NOT NULL, appartient a la liste des types autorises
	unsigned int bonbons; // >=0
	unsigned int pvMax; // NOT NULL, >0
	unsigned int pcMax; // NOT NULL, >0, ne varie pas
} espece;

int main()
{
// L'heure et la date de maintenant
	time_t t0 = time(0); // sous la forme d'un timestamp
	struct tm* tm0 = localtime(&t0); // sous la forme d'une représentation calendaire à l'heure locale
	printf("time_t renvoie %ld\n\n",t0);
// Pour afficher la structure tm sous la forme d'une chaîne lisible
	printf("%s",asctime(tm0));

	return 0;
}
