import time

from cle import Cle
from dkjr import DKJr


class Jeu:
    def __init__(self, presentation):
        self.presentation = presentation

        self.dkjr = DKJr(self.presentation)
        self.cle = Cle(self.presentation)
        self.nbEchecs = 0  # nombre de vies perdues
        self.score = 0  # le score
        # ... attributs à ajouter ...

    # ----------------------------------------------------------------------------
    # méthode contenant la boucle principale du jeu

    def demarrer(self):
        self.presentation.afficher_score(self.score)

        while self.nbEchecs < 3:
            # lire l'événement au clavier lorsque DK Jr est prêt à bouger

            evenement = self.presentation.lire_evenement()

            self.dkjr.changer_etat(evenement)
            self.cle.changer_etat()
            # attendre 100 millisecondes (délai de référence)

            time.sleep(0.1)

        # La partie est terminée. Attendre le clic sur la croix dans la fenêtre
        # pour fermer l'application

        self.presentation.attendre_fermeture_fenetre()
