class Cle:
    def __init__(self, presentation):
        self.presentation = presentation
        self.delai = 7
        self.augmente = True
        self.etat = 1
        self.presentation.afficher_cle(1)

    def changer_etat(self):
        if self.delai > 0:
            self.delai -= 1
        else:
            if self.etat == 1:
                self.etat = 2
                self.augmente = True
                self.presentation.effacer_carre(3, 12, 2, 1)
            elif self.etat == 2:
                if self.augmente:
                    self.etat = 3
                else:
                    self.etat = 1
                self.presentation.effacer_carre(3, 13, 2, 1)
            elif self.etat == 3:
                if self.augmente:
                    self.etat = 4
                else:
                    self.etat = 2
                self.presentation.effacer_carre(3, 13, 2, 2)
            elif self.etat == 4:
                self.etat = 3
                self.augmente = False
            self.presentation.effacer_carre(3, 13, 2, 2)
            self.presentation.afficher_cle(self.etat)
            self.delai = 7

    def effacer_cle(self):
        self.presentation.effacer_carre(3, 12, 2, 1)
        self.delai = 0
