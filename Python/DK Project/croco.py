class Croco:
    def __init__(self, presentation):
        self.presentation = presentation
        self.delai = 7
        self.position = 2
        self.augmente = True
        self.presentation.afficher_croco(11, 2)

    def changer_etat(self):
        if self.delai > 0:
            self.delai -= 1
        else:
            if self.position != 8:
                if self.augmente:
                    self.presentation.effacer_carre(8, self.position * 2 + 7, 1, 1)
                else:
                    self.presentation.effacer_carre(12, self.position * 2 + 8, 1, 1)
            else:
                self.presentation.effacer_carre(9, 23, 1, 1)
            if self.augmente:
                self.position += 1
            else:
                self.position -= 1
            if self.position == 0:
                return 1
            elif self.position == 8:
                self.augmente = False
                self.presentation.afficher_croco(23, 3)
            else:
                if self.augmente:
                    self.presentation.afficher_croco(self.position * 2 + 7, ((self.position - 1) % 2) + 1)
                else:
                    self.presentation.afficher_croco(self.position * 2 + 8, ((self.position - 1) % 2) + 4)
            self.delai = 7
            return 0
