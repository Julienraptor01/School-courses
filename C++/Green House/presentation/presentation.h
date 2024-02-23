#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <SDL/SDL.h>

// différents états de Stanley

#define HAUT		0
#define ECHELLE	1
#define BAS		2

// action de Stanley quand appui sur la touche espace

#define SPRAY		1

// indique une absence : absence d'un événement, absence de la guêpe, absence d'échec, etc.

#define AUCUN		-1

// indique la présence d’un ami, d’un ennemi ou de Stanley dans son état normal 

#define NORMAL	0

// état d'un ami quand il a été mangé/piqué par un ennemi (ex: fleur mangée par chenille)

#define TOUCHE	2

// types d'amis à protéger

#define FLEUR_HG	0
#define FLEUR_HD	1
#define FLEUR_BG	2
#define FLEUR_BD	3
#define CHAT		4

// orientations à l’écran

#define GAUCHE	0
#define DROITE	1

// types d'ennemis

#define GUEPE		0
#define CHENILLE_G	1
#define CHENILLE_D	2
#define ARAIGNEE_G	3
#define ARAIGNEE_D	4

// prototype des fonctions

void ouvrirFenetreGraphique();
void restaurerImageInterne();
void actualiserFenetreGraphique();

void afficherStanley(int etat, int position, int action = NORMAL);
void afficherInsecticideG(int position);
void afficherInsecticideD(int position);
void afficherAmi(int typeAmi, int etat);
void afficherChenilleG(int position);
void afficherChenilleD(int position);
void afficherAraigneeG(int position);
void afficherAraigneeD(int position);
void afficherGuepe(int position);
void afficherEchecs(int nbEchecs);
void afficherScore(int score);

int lireEvenement();

#endif
