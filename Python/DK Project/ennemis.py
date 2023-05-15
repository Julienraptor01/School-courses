from random import randint


class Ennemis:
    RIEN = 0
    CORBEAU = 1
    CROCO = 2

    def __init__(self):
        self.delaiDifficulte = 150
        self.incrementDifficulte = 0
        self.delaiEnnemis = 40

    def changer_etat(self):
        if self.delaiDifficulte > 0:
            self.delaiDifficulte -= 1
        else:
            self.delaiDifficulte = 150
            if self.incrementDifficulte < 5:
                self.incrementDifficulte += 1

        if self.delaiEnnemis > 0:
            self.delaiEnnemis -= 1
            return self.RIEN
        else:
            self.delaiEnnemis = 40 - self.incrementDifficulte * 4
            return randint(self.CORBEAU, self.CROCO)
