from presentation import *


class Cle:
    def __init__(self, presentation):
        self.presentation = presentation
        self.delai = 0
        self.etat = 2

    def changer_etat(self):
        if self.delai > 0:
            self.delai -= 1
