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
            self.effacer_cle()
            if self.etat == 1:
                self.augmente = True
            elif self.etat == 4:
                self.augmente = False
            if self.augmente:
                self.etat += 1
            else:
                self.etat -= 1
            self.presentation.afficher_cle(self.etat)
            self.presentation.jouer_son(4)
            self.delai = 7

    def effacer_cle(self):
        if self.etat == 1:
            self.presentation.effacer_carre(3, 12, 2, 1)
        elif self.etat == 2:
            self.presentation.effacer_carre(3, 13, 2, 1)
        elif self.etat in [3, 4]:
            self.presentation.effacer_carre(3, 13, 2, 2)

    def reinitialiser_delai(self):
        self.delai = 0
