class DK:
    def __init__(self, presentation):
        self.presentation = presentation
        self.etat = 4
        for i in range(4):
            self.presentation.afficher_cage(i + 1)

    def changer_etat(self):
        self.etat -= 1
        if self.etat == 3:
            self.presentation.effacer_carre(4, 9, 2, 2)
        elif self.etat == 2:
            self.presentation.effacer_carre(2, 9, 2, 2)
        elif self.etat == 1:
            self.presentation.effacer_carre(2, 7, 2, 2)
        else:
            self.presentation.effacer_carre(4, 7, 2, 2)

    def yay(self):
        self.presentation.afficher_rire_dk()

    def reinitialiser_etat(self):
        self.presentation.effacer_carre(3, 8, 2, 2)
        self.etat = 4
        for i in range(4):
            self.presentation.afficher_cage(i + 1)
