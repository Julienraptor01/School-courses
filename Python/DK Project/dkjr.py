from presentation import *


class DKJr:
    LIBRE_BAS = 1
    SAUT_BAS = 2
    LIANE_BAS = 3
    DOUBLE_LIANE_BAS = 4
    LIBRE_HAUT = 5
    SAUT_HAUT = 6
    LIANE_HAUT = 7

    # ---------------------------------------------------

    def __init__(self, presentation):
        self.presentation = presentation
        self.delai = 0
        self.position = 1
        self.etat = DKJr.LIBRE_BAS
        self.presentation.afficherDKJr(11, self.position * 2 + 7, 1)

    # ---------------------------------------------------

    def changerEtat(self, direction):
        self.delai -= 1

        if self.delai <= 0:
            self.presentation.jouerSon(0)

            if self.etat == DKJr.LIBRE_BAS:
                if direction == pygame.K_RIGHT:
                    if self.position < 7:
                        self.presentation.effacerCarre(11, self.position * 2 + 7, 2, 2)
                        self.position += 1
                        self.presentation.afficherDKJr(11, self.position * 2 + 7,
                                                       ((self.position - 1) % 4) + 1)
                elif direction == pygame.K_LEFT:
                    if self.position > 1:
                        self.presentation.effacerCarre(11, self.position * 2 + 7, 2, 2)
                        self.position -= 1
                        self.presentation.afficherDKJr(11, self.position * 2 + 7,
                                                       ((self.position - 1) % 4) + 1)
                elif direction == pygame.K_UP:
                    if self.position in [2, 3, 4, 6]:
                        self.presentation.effacerCarre(11, self.position * 2 + 7, 2, 2)
                        self.presentation.afficherDKJr(10, self.position * 2 + 7, 8)
                        self.etat = DKJr.SAUT_BAS
                        self.delai = 15
                        return
                    elif self.position in [1, 5]:
                        self.presentation.effacerCarre(11, self.position * 2 + 7, 2, 2)
                        self.presentation.afficherDKJr(10, self.position * 2 + 7, 7)
                        self.etat = DKJr.LIANE_BAS
                    elif self.position == 7:
                        self.presentation.effacerCarre(11, self.position * 2 + 7, 2, 2)
                        self.presentation.afficherDKJr(10, self.position * 2 + 7, 5)
                        self.etat = DKJr.DOUBLE_LIANE_BAS

            elif self.etat == DKJr.SAUT_BAS:
                self.presentation.effacerCarre(10, self.position * 2 + 7, 2, 2)
                self.presentation.afficherDKJr(11, self.position * 2 + 7,
                                               ((self.position - 1) % 4) + 1)
                self.etat = DKJr.LIBRE_BAS

            elif self.etat == DKJr.LIANE_BAS:
                if direction == pygame.K_DOWN:
                    self.presentation.effacerCarre(10, self.position * 2 + 7, 2, 2)
                    self.presentation.afficherDKJr(11, self.position * 2 + 7,
                                                   ((self.position - 1) % 4) + 1)
                    self.etat = DKJr.LIBRE_BAS

            elif self.etat == DKJr.DOUBLE_LIANE_BAS:
                if direction == pygame.K_DOWN:
                    self.presentation.effacerCarre(10, self.position * 2 + 7, 2, 2)
                    self.presentation.afficherDKJr(11, self.position * 2 + 7,
                                                   ((self.position - 1) % 4) + 1)
                    self.etat = DKJr.LIBRE_BAS
                elif direction == pygame.K_UP:
                    self.presentation.effacerCarre(10, self.position * 2 + 7, 2, 2)
                    self.presentation.afficherDKJr(7, self.position * 2 + 7, 6)
                    self.etat = DKJr.LIBRE_HAUT

            elif self.etat == DKJr.LIBRE_HAUT:
                if direction == pygame.K_RIGHT:
                    if self.position < 6:
                        self.presentation.effacerCarre(7, self.position * 2 + 7, 2, 2)
                        self.position += 1
                        self.presentation.afficherDKJr(7, self.position * 2 + 7,
                                                       ((-self.position + 7) - 1) % 4 + 1)
                    elif self.position == 6:
                        self.presentation.effacerCarre(7, self.position * 2 + 7, 2, 2)
                        self.position += 1
                        self.presentation.afficherDKJr(7, self.position * 2 + 7, 6)
                elif direction == pygame.K_LEFT:
                    if self.position > 3:
                        self.presentation.effacerCarre(7, self.position * 2 + 7, 2, 2)
                        self.position -= 1
                        self.presentation.afficherDKJr(7, self.position * 2 + 7,
                                                       ((-self.position + 7) - 1) % 4 + 1)
                    elif self.position == 3:
                        # TODO : did he got the fucking key ?
                        print("à implémenter...")
                elif direction == pygame.K_UP:
                    if self.position in [3, 4]:
                        self.presentation.effacerCarre(7, self.position * 2 + 7, 2, 2)
                        self.presentation.afficherDKJr(6, self.position * 2 + 7, 8)
                        self.etat = DKJr.SAUT_HAUT
                        self.delai = 15
                        return
                    elif self.position == 6:
                        self.presentation.effacerCarre(7, self.position * 2 + 7, 2, 2)
                        self.presentation.afficherDKJr(6, self.position * 2 + 7, 7)
                        self.etat = DKJr.LIANE_HAUT
                elif direction == pygame.K_DOWN:
                    if self.position == 7:
                        self.presentation.effacerCarre(7, self.position * 2 + 7, 2, 2)
                        self.presentation.afficherDKJr(10, self.position * 2 + 7, 5)
                        self.etat = DKJr.DOUBLE_LIANE_BAS

            elif self.etat == DKJr.SAUT_HAUT:
                self.presentation.effacerCarre(6, self.position * 2 + 7, 2, 2)
                self.presentation.afficherDKJr(7, self.position * 2 + 7,
                                               ((-self.position + 7) - 1) % 4 + 1)
                self.etat = DKJr.LIBRE_HAUT

            elif self.etat == DKJr.LIANE_HAUT:
                if direction == pygame.K_DOWN:
                    self.presentation.effacerCarre(6, self.position * 2 + 7, 2, 2)
                    self.presentation.afficherDKJr(7, self.position * 2 + 7,
                                                   ((-self.position + 7) - 1) % 4 + 1)
                    self.etat = DKJr.LIBRE_HAUT

            self.delai = 0
