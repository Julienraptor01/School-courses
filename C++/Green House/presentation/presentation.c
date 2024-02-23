#include "presentation.h"

SDL_Surface *chargerImage(const char *nomImage, bool transparent = true);
void afficherImage(int ligne, int colonne, SDL_Surface *image);
void afficherChiffre(int ligne, int colonne, int chiffre);

SDL_Surface	*ecran,
		*imgFondEcran,
		*imgStanleyBasNormal0,
		*imgStanleyBasNormal1,
		*imgStanleyBasNormal2,
		*imgStanleyBasNormal3,
		*imgStanleyEchelle0,
		*imgStanleyEchelle1,
		*imgStanleyHautNormal0,
		*imgStanleyHautNormal1,
		*imgStanleyHautNormal2,
		*imgStanleyHautNormal3,
		*imgStanleyHautNormal4,
		*imgStanleyHautNormal5,
		*imgStanleyBasSpray0,
		*imgStanleyBasSpray2,
		*imgStanleyBasSpray3,
		*imgStanleyHautSpray0,
		*imgStanleyHautSpray1,
		*imgStanleyHautSpray3,
		*imgStanleyHautSpray4,
		*imgStanleyHautSpray5,
		*imgInsecticideHaut0,
		*imgInsecticideHaut1,
		*imgInsecticideHaut3,
		*imgInsecticideHaut4,
		*imgInsecticideHaut5,
		*imgInsecticideBas0,
		*imgInsecticideBas2,
		*imgInsecticideBas3,
		*imgInsecticideMvtG,
		*imgInsecticideMvtD,
		*imgEchec,
		*imgChat0,
		*imgChat1,
		*imgFleurHG0,
		*imgFleurHG1,
		*imgFleurHD0,
		*imgFleurHD1,
		*imgFleurBG0,
		*imgFleurBG1,
		*imgFleurBD0,
		*imgFleurBD1,
		*imgChenilleG0,
		*imgChenilleG1,
		*imgChenilleG2,
		*imgChenilleG3,
		*imgChenilleD0,
		*imgChenilleD1,
		*imgChenilleD2,
		*imgChenilleD3,
		*imgGuepe0,
		*imgGuepe1,
		*imgAraigneeG0,
		*imgAraigneeG1,
		*imgAraigneeD0,
		*imgAraigneeD1,
		*imgChiffre0,
		*imgChiffre1,
		*imgChiffre2,
		*imgChiffre3,
		*imgChiffre4,
		*imgChiffre5,
		*imgChiffre6,
		*imgChiffre7,
		*imgChiffre8,
		*imgChiffre9;
pthread_mutex_t mutexSDL;

// ------------------------------------------------------------------------
// charger les images et ouvrir la fenêtre graphique

void ouvrirFenetreGraphique()
{	
	SDL_Init(SDL_INIT_EVERYTHING);

	ecran = SDL_SetVideoMode(1016, 780, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

        imgFondEcran = chargerImage("./images/greenhouse.bmp", false);

        imgStanleyBasNormal0 = chargerImage("./images/stanley/bas_normal_0.bmp");
        imgStanleyBasNormal1 = chargerImage("./images/stanley/bas_normal_1.bmp");
        imgStanleyBasNormal2 = chargerImage("./images/stanley/bas_normal_2.bmp");
        imgStanleyBasNormal3 = chargerImage("./images/stanley/bas_normal_3.bmp");
        imgStanleyEchelle0 = chargerImage("./images/stanley/echelle_0.bmp");
        imgStanleyEchelle1 = chargerImage("./images/stanley/echelle_1.bmp");
        imgStanleyHautNormal0 = chargerImage("./images/stanley/haut_normal_0.bmp");
        imgStanleyHautNormal1 = chargerImage("./images/stanley/haut_normal_1.bmp");
        imgStanleyHautNormal2 = chargerImage("./images/stanley/haut_normal_2.bmp");
        imgStanleyHautNormal3 = chargerImage("./images/stanley/haut_normal_3.bmp");
        imgStanleyHautNormal4 = chargerImage("./images/stanley/haut_normal_4.bmp");
        imgStanleyHautNormal5 = chargerImage("./images/stanley/haut_normal_5.bmp");

        imgStanleyBasSpray0 = chargerImage("./images/stanley/bas_spray_0.bmp");
        imgStanleyBasSpray2 = chargerImage("./images/stanley/bas_spray_2.bmp");
        imgStanleyBasSpray3 = chargerImage("./images/stanley/bas_spray_3.bmp");
        imgStanleyHautSpray0 = chargerImage("./images/stanley/haut_spray_0.bmp");
        imgStanleyHautSpray1 = chargerImage("./images/stanley/haut_spray_1.bmp");
        imgStanleyHautSpray3 = chargerImage("./images/stanley/haut_spray_3.bmp");
        imgStanleyHautSpray4 = chargerImage("./images/stanley/haut_spray_4.bmp");
        imgStanleyHautSpray5 = chargerImage("./images/stanley/haut_spray_5.bmp");

        imgInsecticideHaut0 = chargerImage("./images/insecticide/haut_gauche_0.bmp");
        imgInsecticideHaut1 = chargerImage("./images/insecticide/haut_gauche_1.bmp");
        imgInsecticideHaut3 = chargerImage("./images/insecticide/haut_droite_3.bmp");
        imgInsecticideHaut4 = chargerImage("./images/insecticide/haut_droite_4.bmp");
        imgInsecticideHaut5 = chargerImage("./images/insecticide/haut_droite_5.bmp");

        imgInsecticideBas0 = chargerImage("./images/insecticide/bas_0.bmp");
        imgInsecticideBas2 = chargerImage("./images/insecticide/bas_2.bmp");
        imgInsecticideBas3 = chargerImage("./images/insecticide/bas_3.bmp");
        imgInsecticideMvtG = chargerImage("./images/insecticide/bas_gauche_mvt.bmp");
        imgInsecticideMvtD = chargerImage("./images/insecticide/bas_droite_mvt.bmp");

        imgEchec = chargerImage("./images/stanley/echec.bmp", false);

        imgChat0 = chargerImage("./images/amis/chat_0.bmp");
        imgChat1 = chargerImage("./images/amis/chat_1.bmp");

        imgFleurHG0 = chargerImage("./images/amis/haut_gauche_0.bmp");
        imgFleurHG1 = chargerImage("./images/amis/haut_gauche_1.bmp");
        imgFleurHD0 = chargerImage("./images/amis/haut_droite_0.bmp");
        imgFleurHD1 = chargerImage("./images/amis/haut_droite_1.bmp");
        imgFleurBG0 = chargerImage("./images/amis/bas_gauche_0.bmp");
        imgFleurBG1 = chargerImage("./images/amis/bas_gauche_1.bmp");
        imgFleurBD0 = chargerImage("./images/amis/bas_droite_0.bmp");
        imgFleurBD1 = chargerImage("./images/amis/bas_droite_1.bmp");

        imgChenilleG0 = chargerImage("./images/ennemis/chenille_gauche_0.bmp");
        imgChenilleG1 = chargerImage("./images/ennemis/chenille_gauche_1.bmp");
        imgChenilleG2 = chargerImage("./images/ennemis/chenille_gauche_2.bmp");
        imgChenilleG3 = chargerImage("./images/ennemis/chenille_gauche_3.bmp");
        imgChenilleD0 = chargerImage("./images/ennemis/chenille_droite_0.bmp");
        imgChenilleD1 = chargerImage("./images/ennemis/chenille_droite_1.bmp");
        imgChenilleD2 = chargerImage("./images/ennemis/chenille_droite_2.bmp");
        imgChenilleD3 = chargerImage("./images/ennemis/chenille_droite_3.bmp");

        imgGuepe0 = chargerImage("./images/ennemis/guepe_0.bmp");
        imgGuepe1 = chargerImage("./images/ennemis/guepe_1.bmp");

        imgAraigneeG0 = chargerImage("./images/ennemis/araignee_gauche_0.bmp");
        imgAraigneeG1 = chargerImage("./images/ennemis/araignee_gauche_1.bmp");
        imgAraigneeD0 = chargerImage("./images/ennemis/araignee_droite_0.bmp");
        imgAraigneeD1 = chargerImage("./images/ennemis/araignee_droite_1.bmp");

        imgChiffre0 = chargerImage("./images/chiffres/Zero.bmp");
        imgChiffre1 = chargerImage("./images/chiffres/Un.bmp");
        imgChiffre2 = chargerImage("./images/chiffres/Deux.bmp");
        imgChiffre3 = chargerImage("./images/chiffres/Trois.bmp");
        imgChiffre4 = chargerImage("./images/chiffres/Quatre.bmp");
        imgChiffre5 = chargerImage("./images/chiffres/Cinq.bmp");
        imgChiffre6 = chargerImage("./images/chiffres/Six.bmp");
        imgChiffre7 = chargerImage("./images/chiffres/Sept.bmp");
        imgChiffre8 = chargerImage("./images/chiffres/Huit.bmp");
        imgChiffre9 = chargerImage("./images/chiffres/Neuf.bmp"); 

        SDL_WM_SetCaption("Green House", NULL);
	
        SDL_BlitSurface(imgFondEcran, NULL, ecran, NULL);
        SDL_Flip(ecran);
	
        pthread_mutex_init(&mutexSDL, NULL);
}

// ------------------------------------------------------------------------
// afficher Stanley

void afficherStanley(int etat, int position, int action)
{
        if(action == NORMAL)
        {
            if(etat == HAUT)
            {            
                if(position == 0)
                    afficherImage(18, 149, imgStanleyHautNormal0);
                else if(position == 1)
                    afficherImage(128, 149, imgStanleyHautNormal1);
                else if(position == 2)
                    afficherImage(249, 189, imgStanleyHautNormal2);
                else if(position == 3)
                    afficherImage(360, 149, imgStanleyHautNormal3);
                else if(position == 4)
                    afficherImage(470, 149, imgStanleyHautNormal4);
                else if(position == 5)
                    afficherImage(585, 149, imgStanleyHautNormal5);
            }
            else if(etat == ECHELLE)
            {
                if(position == 0)
                    afficherImage(249, 348, imgStanleyEchelle0);
                else if(position == 1)
                    afficherImage(267, 490, imgStanleyEchelle1);
            }
            else if(etat == BAS)
            {
                if(position == 0)
                    afficherImage(138, 608, imgStanleyBasNormal0);
                else if(position == 1)
                    afficherImage(252, 608, imgStanleyBasNormal1);
                else if(position == 2)
                    afficherImage(373, 608, imgStanleyBasNormal2);
                else if(position == 3)
                    afficherImage(494, 608, imgStanleyBasNormal3);
            }
        }
        else if(action == SPRAY)
        {
            if(etat == HAUT)
            {
                if(position == 0)
                {
                    afficherImage(18, 149, imgStanleyHautSpray0);
                    afficherImage(57, 22, imgInsecticideHaut0);
                }
                else if(position == 1)
                {
                    afficherImage(128, 149, imgStanleyHautSpray1);
                    afficherImage(144, 22, imgInsecticideHaut1);
                }
                else if(position == 3)
                {
                    afficherImage(360, 149, imgStanleyHautSpray3);
                    afficherImage(352, 22, imgInsecticideHaut3);
                }
                else if(position == 4)
                {
                    afficherImage(470, 149, imgStanleyHautSpray4);
                    afficherImage(459, 22, imgInsecticideHaut4);
                }
                else if(position == 5)
                {
                    afficherImage(585, 149, imgStanleyHautSpray5);
                    afficherImage(560, 22, imgInsecticideHaut5);
                }
            }
            else if(etat == BAS)
            {
                if(position == 0)
                {
                    afficherImage(138, 608, imgStanleyBasSpray0);
                    afficherImage(70, 596, imgInsecticideBas0);
                }
                else if(position == 2)
                {
                    afficherImage(373, 608, imgStanleyBasSpray2);
                    afficherImage(392, 481, imgInsecticideBas2);
                }
                else if(position == 3)
                {
                    afficherImage(494, 608, imgStanleyBasSpray3);
                    afficherImage(595, 595, imgInsecticideBas3);
                }
            }
        }
}

// ------------------------------------------------------------------------
// afficher l'insecticide à gauche

void afficherInsecticideG(int position)
{
        if(position == 0)
            afficherImage(24, 413, imgInsecticideMvtG);
        else if(position == 1)
            afficherImage(36, 461, imgInsecticideMvtG);
        else if(position == 2)
            afficherImage(48, 509, imgInsecticideMvtG);
        else if(position == 3)
            afficherImage(60, 555, imgInsecticideMvtG);
}

// ------------------------------------------------------------------------
// afficher l'insecticide à droite

void afficherInsecticideD(int position)
{
        if(position == 1)
            afficherImage(610, 555, imgInsecticideMvtD);
        else if(position == 2)
            afficherImage(620, 509, imgInsecticideMvtD);
        else if(position == 3)
            afficherImage(632, 461, imgInsecticideMvtD);
        else if(position == 4)
            afficherImage(644, 413, imgInsecticideMvtD);
}

// ------------------------------------------------------------------------
// afficher une fleur ou le chat

void afficherAmi(int typeAmi, int etat)
{
        if(typeAmi == FLEUR_HG)
        {
            if(etat == NORMAL)
                afficherImage(5, 41, imgFleurHG0);
            else if(etat == TOUCHE)
                afficherImage(15, 85, imgFleurHG1);
        }
        else if(typeAmi == FLEUR_HD)
        {
            if(etat == NORMAL)
                afficherImage(665, 41, imgFleurHD0);
            else if(etat == TOUCHE)
                afficherImage(659, 85, imgFleurHD1);
        }
        else if(typeAmi == FLEUR_BG)
        {
            if(etat == NORMAL)
                afficherImage(64, 668, imgFleurBG0);
            else if(etat == TOUCHE)
                afficherImage(43, 693, imgFleurBG1);
        }
        else if(typeAmi == FLEUR_BD)
        {
            if(etat == NORMAL)
                afficherImage(616, 668, imgFleurBD0);
            else if(etat == TOUCHE)
                afficherImage(638, 693, imgFleurBD1);
        }
        else if(typeAmi == CHAT)
        {
            if(etat == NORMAL)
                afficherImage(495, 498, imgChat0);
            else if(etat == TOUCHE)
                afficherImage(495, 425, imgChat1);
        }
}

// ------------------------------------------------------------------------
// afficher une chenille à gauche

void afficherChenilleG(int position)
{
        if(position == 0)
            afficherImage(45, 46, imgChenilleG0);
        else if(position == 1)
            afficherImage(85, 48, imgChenilleG1);
        else if(position == 2)
            afficherImage(140, 48, imgChenilleG2);
        else if(position == 3)
            afficherImage(194, 40, imgChenilleG1);
        else if(position == 4)
            afficherImage(234, 16, imgChenilleG3);
}

// ------------------------------------------------------------------------
// afficher une chenille à droite

void afficherChenilleD(int position)
{
        if(position == 0)
            afficherImage(308, 16, imgChenilleD0);
        else if(position == 1)
            afficherImage(353, 40, imgChenilleD1);
        else if(position == 2)
            afficherImage(409, 48, imgChenilleD2);
        else if(position == 3)
            afficherImage(466, 48, imgChenilleD1);
        else if(position == 4)
            afficherImage(522, 48, imgChenilleD2);
        else if(position == 5)
            afficherImage(578, 48, imgChenilleD1);
        else if(position == 6)
            afficherImage(624, 45, imgChenilleD3);
}

// ------------------------------------------------------------------------
// afficher une araignee à gauche

void afficherAraigneeG(int position)
{ 
        if(position == 0)
            afficherImage(39, 412, imgAraigneeG0);
        else if(position == 1)
            afficherImage(51, 461, imgAraigneeG1);
        else if(position == 2)
            afficherImage(63, 510, imgAraigneeG0);
        else if(position == 3)
            afficherImage(75, 555, imgAraigneeG1);
        else if(position == 4)
            afficherImage(87, 608, imgAraigneeG0);
}

// ------------------------------------------------------------------------
// afficher une araignee à droite

void afficherAraigneeD(int position)
{
        if(position == 0)
            afficherImage(613, 608, imgAraigneeD0);
        else if(position == 1)
            afficherImage(624, 555, imgAraigneeD1);
        else if(position == 2)
            afficherImage(634, 510, imgAraigneeD0);
        else if(position == 3)
            afficherImage(645, 461, imgAraigneeD1);
        else if(position == 4)
            afficherImage(656, 412, imgAraigneeD0);
}

// ------------------------------------------------------------------------
// afficher la guêpe

void afficherGuepe(int position)
{
	if(position == 0)
	    afficherImage(410, 511, imgGuepe0);
	else if(position == 1)
	    afficherImage(468, 528, imgGuepe1);
}

// ------------------------------------------------------------------------
// afficher la tête de Stanley en cas d'échec
// nbEchecs = (nombre d'échecs) 1, 2 ou 3 

void afficherEchecs(int nbEchecs)
{
	for(int i = 0; i < nbEchecs; i++)
	    afficherImage(824 + (i * 36), 427, imgEchec);
}

// ------------------------------------------------------------------------
// afficher le score

void afficherScore(int score)
{
	afficherChiffre(797, 270, score / 1000);
	afficherChiffre(837, 270, (score /100) % 10);
	afficherChiffre(877, 270, (score / 10) % 10);
	afficherChiffre(917, 270, score % 10);
}

// ------------------------------------------------------------------------
// afficher les différents chiffres

void afficherChiffre(int ligne, int colonne, int chiffre)
{
	switch(chiffre)
	{
            case 0:
                afficherImage(ligne, colonne, imgChiffre0); break;
            case 1:
                afficherImage(ligne, colonne, imgChiffre1); break;
            case 2:
                afficherImage(ligne, colonne, imgChiffre2); break;
            case 3:
                afficherImage(ligne, colonne, imgChiffre3); break;
            case 4:
                afficherImage(ligne, colonne, imgChiffre4); break;
            case 5:
                afficherImage(ligne, colonne, imgChiffre5); break;
            case 6:
                afficherImage(ligne, colonne, imgChiffre6); break;
            case 7:
                afficherImage(ligne, colonne, imgChiffre7); break;
            case 8:
                afficherImage(ligne, colonne, imgChiffre8); break;
            case 9:
                afficherImage(ligne, colonne, imgChiffre9);
	}
}

// ------------------------------------------------------------------------
// charger une image avec fond transparent ou non

SDL_Surface *chargerImage(const char *nomImage, bool transparent)
{
	SDL_Surface *image;
	
	image = SDL_DisplayFormat(SDL_LoadBMP(nomImage));
	
	if(transparent == true)
		SDL_SetColorKey(image, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 255, 255, 255));
	else
		SDL_SetColorKey(image, SDL_RLEACCEL, 0);	
	
	return image;
}

// ------------------------------------------------------------------------
// afficher une image sur l'image de fond d'écran initiale

void afficherImage(int x, int y, SDL_Surface *image)
{
	SDL_Rect rect;
	
	pthread_mutex_lock(&mutexSDL);  
	      
	rect.x = x;
	rect.y = y;
	SDL_BlitSurface(image, NULL, ecran, &rect);
	
	pthread_mutex_unlock(&mutexSDL);  
}

// ------------------------------------------------------------------------
// mettre à jour l'image dans la fenêtre visible du jeu

void actualiserFenetreGraphique()
{
	SDL_Flip(ecran);
}


// ------------------------------------------------------------------------
// effacer tous les personnages  dans l'image interne du jeu (effacements   
// non visibles à l'écran)

void restaurerImageInterne()
{
	SDL_BlitSurface(imgFondEcran,  NULL, ecran, NULL);        
}

// ------------------------------------------------------------------------
// retourner la touche sur laquelle a appuyé le joueur ou  
// SDL_QUIT si clic sur la croix

int lireEvenement()
{
	SDL_Event event;
	int evt = AUCUN;
	struct timespec temps = { 0, 20000000 };

        while(evt == AUCUN)
        {
            pthread_mutex_lock(&mutexSDL); 
    
            while(SDL_PollEvent(&event))
            {   
                if(event.type == SDL_QUIT)  
                    evt = SDL_QUIT;
                else if(event.type == SDL_KEYDOWN)
                    evt = event.key.keysym.sym;
            }

            pthread_mutex_unlock(&mutexSDL);  

            nanosleep(&temps, NULL);  
        } 
  
        return evt;
}



