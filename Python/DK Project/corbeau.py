class Corbeau:
    def __init__(self, presentation):
        self.presentation = presentation
        self.delai = 7
        self.position = 0
        self.presentation.afficher_corbeau(8, 2)

    def changer_etat(self):
        if self.delai > 0:
            self.delai -= 1
        else:
            self.effacer_corbeau()
            self.position += 1
            if self.position == 8:
                return 1
            else:
                self.presentation.afficher_corbeau(self.position * 2 + 8, ((self.position - 1) % 2) + 1)
                self.delai = 7
        return 0

    def effacer_corbeau(self):
        self.presentation.effacer_carre(9, self.position * 2 + 8, 2, 1)
