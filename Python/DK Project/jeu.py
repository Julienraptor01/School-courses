import time

from cle import Cle
from dkjr import DKJr


class Jeu:
    def __init__(self, presentation):
        self.presentation = presentation

        self.dkjr = DKJr(self.presentation)
        self.cle = Cle(self.presentation)
        self.nbEchecs = 0
        self.score = 0

    def demarrer(self):
        self.presentation.afficher_score(self.score)

        while self.nbEchecs < 3:

            evenement = self.presentation.lire_evenement()

            self.dkjr.changer_etat(evenement)
            self.cle.changer_etat()

            time.sleep(0.1)

        self.presentation.attendre_fermeture_fenetre()
