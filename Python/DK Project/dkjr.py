import pygame


class DKJr:
    LIBRE_BAS = 1
    SAUT_BAS = 2
    LIANE_BAS = 3
    DOUBLE_LIANE_BAS = 4
    LIBRE_HAUT = 5
    SAUT_HAUT = 6
    LIANE_HAUT = 7

    def __init__(self, presentation):
        self.presentation = presentation
        self.delai = 0
        self.position = 1
        self.etat = DKJr.LIBRE_BAS
        self.presentation.afficher_dk_jr(11, 9, 1)

    def changer_etat(self, direction):
        if self.delai > 0:
            self.delai -= 1

        else:
            if direction in [pygame.K_RIGHT, pygame.K_LEFT, pygame.K_UP, pygame.K_DOWN] \
                    or self.etat in [DKJr.SAUT_HAUT, DKJr.SAUT_BAS]:
                self.presentation.jouer_son(0)

            if self.etat == DKJr.LIBRE_BAS:
                if direction == pygame.K_RIGHT:
                    if self.position < 7:
                        self.effacer_dkjr()
                        self.position += 1
                        self.afficher_dkjr()
                elif direction == pygame.K_LEFT:
                    if self.position > 1:
                        self.effacer_dkjr()
                        self.position -= 1
                        self.afficher_dkjr()
                elif direction == pygame.K_UP:
                    if self.position in [2, 3, 4, 6]:
                        self.effacer_dkjr()
                        self.etat = DKJr.SAUT_BAS
                        self.afficher_dkjr()
                        self.delai = 15
                        return
                    elif self.position in [1, 5]:
                        self.effacer_dkjr()
                        self.etat = DKJr.LIANE_BAS
                        self.afficher_dkjr()
                    elif self.position == 7:
                        self.effacer_dkjr()
                        self.etat = DKJr.DOUBLE_LIANE_BAS
                        self.afficher_dkjr()

            elif self.etat == DKJr.SAUT_BAS:
                self.effacer_dkjr()
                self.etat = DKJr.LIBRE_BAS
                self.afficher_dkjr()

            elif self.etat == DKJr.LIANE_BAS:
                if direction == pygame.K_DOWN:
                    self.effacer_dkjr()
                    self.etat = DKJr.LIBRE_BAS
                    self.afficher_dkjr()

            elif self.etat == DKJr.DOUBLE_LIANE_BAS:
                if direction == pygame.K_DOWN:
                    self.effacer_dkjr()
                    self.etat = DKJr.LIBRE_BAS
                    self.afficher_dkjr()
                elif direction == pygame.K_UP:
                    self.effacer_dkjr()
                    self.etat = DKJr.LIBRE_HAUT
                    self.afficher_dkjr()

            elif self.etat == DKJr.LIBRE_HAUT:
                if direction == pygame.K_RIGHT:
                    if self.position < 6:
                        self.effacer_dkjr()
                        self.position += 1
                        self.afficher_dkjr()
                    elif self.position == 6:
                        self.effacer_dkjr()
                        self.position += 1
                        self.afficher_dkjr()
                elif direction == pygame.K_LEFT:
                    if self.position > 3:
                        self.effacer_dkjr()
                        self.position -= 1
                        self.afficher_dkjr()
                    elif self.position == 3:
                        self.effacer_dkjr()
                        self.position -= 1
                        self.afficher_dkjr()
                elif direction == pygame.K_UP:
                    if self.position in [3, 4]:
                        self.effacer_dkjr()
                        self.etat = DKJr.SAUT_HAUT
                        self.afficher_dkjr()
                        self.delai = 15
                        return
                    elif self.position == 6:
                        self.effacer_dkjr()
                        self.etat = DKJr.LIANE_HAUT
                        self.afficher_dkjr()
                elif direction == pygame.K_DOWN:
                    if self.position == 7:
                        self.effacer_dkjr()
                        self.etat = DKJr.DOUBLE_LIANE_BAS
                        self.afficher_dkjr()

            elif self.etat == DKJr.SAUT_HAUT:
                self.effacer_dkjr()
                self.etat = DKJr.LIBRE_HAUT
                self.afficher_dkjr()

            elif self.etat == DKJr.LIANE_HAUT:
                if direction == pygame.K_DOWN:
                    self.effacer_dkjr()
                    self.etat = DKJr.LIBRE_HAUT
                    self.afficher_dkjr()

    def attrapage_cle(self, reussite):
        self.presentation.effacer_carre(5, 12, 3, 2)
        if reussite:
            self.presentation.afficher_dk_jr(3, 11, 10)
        else:
            self.presentation.afficher_dk_jr(6, 11, 12)

    def chute_apres_cle(self, reussite):
        if reussite:
            self.presentation.effacer_carre(3, 11, 3, 2)
            self.presentation.afficher_dk_jr(6, 10, 11)
        else:
            self.presentation.effacer_carre(6, 11, 2, 2)
            self.presentation.afficher_dk_jr(10, 7, 13)

    def reinitialiser_etat(self, reussite):
        if reussite:
            self.presentation.effacer_carre(6, 10, 2, 3)
        else:
            self.presentation.effacer_carre(11, 7, 2, 2)
        self.presentation.afficher_dk_jr(11, 9, 1)
        self.position = 1
        self.etat = DKJr.LIBRE_BAS

    def effacer_dkjr(self):
        if self.etat == DKJr.LIBRE_BAS:
            self.presentation.effacer_carre(11, self.position * 2 + 7, 2, 2)
        elif self.etat in [DKJr.SAUT_BAS, DKJr.LIANE_BAS, DKJr.DOUBLE_LIANE_BAS]:
            self.presentation.effacer_carre(10, self.position * 2 + 7, 2, 2)
        elif self.etat == DKJr.LIBRE_HAUT:
            self.presentation.effacer_carre(7, self.position * 2 + 7, 2, 2)
        elif self.etat == DKJr.SAUT_HAUT or self.etat == DKJr.LIANE_HAUT:
            self.presentation.effacer_carre(6, self.position * 2 + 7, 2, 2)

    def afficher_dkjr(self):
        if self.etat == DKJr.LIBRE_BAS:
            self.presentation.afficher_dk_jr(11, self.position * 2 + 7, ((self.position - 1) % 4) + 1)
        elif self.etat == DKJr.SAUT_BAS:
            self.presentation.afficher_dk_jr(10, self.position * 2 + 7, 8)
        elif self.etat == DKJr.LIANE_BAS:
            self.presentation.afficher_dk_jr(10, self.position * 2 + 7, 7)
        elif self.etat == DKJr.DOUBLE_LIANE_BAS:
            self.presentation.afficher_dk_jr(10, self.position * 2 + 7, 5)
        elif self.etat == DKJr.LIBRE_HAUT:
            if self.position in [3, 4, 5, 6]:
                self.presentation.afficher_dk_jr(7, self.position * 2 + 7, ((-self.position + 7) - 1) % 4 + 1)
            elif self.position == 7:
                self.presentation.afficher_dk_jr(7, self.position * 2 + 7, 6)
            else:
                self.presentation.afficher_dk_jr(7, 12, 9)
        elif self.etat == DKJr.SAUT_HAUT:
            self.presentation.afficher_dk_jr(6, self.position * 2 + 7, 8)
        elif self.etat == DKJr.LIANE_HAUT:
            self.presentation.afficher_dk_jr(6, self.position * 2 + 7, 7)
