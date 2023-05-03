from dkjr import *
#from cle import *


class Jeu:
    def __init__(self, presentation):
        self.presentation = presentation

        self.dkjr = DKJr(self.presentation)
#        self.cle = Cle(self.presentation)
        self.nbEchecs = 0  # nombre de vies perdues
        self.score = 0  # le score
        # ... attributs à ajouter ...

    # ----------------------------------------------------------------------------
    # méthode contenant la boucle principale du jeu

    def demarrer(self):
        self.presentation.afficherScore(self.score)

        while self.nbEchecs < 3:
            while True:
                # lire l'événement au clavier lorsque DK Jr est prêt à bouger

                if self.dkjr.delai <= 0:
                    evenement = self.presentation.lireEvenement()

                if evenement in [pygame.K_RIGHT, pygame.K_LEFT, pygame.K_UP, pygame.K_DOWN]:
                    # changer l'état/la position de DK Jr selon l'événement du joueur

                    self.dkjr.changerEtat(evenement)

                # ... suite à implémenter ...
#                if self.cle.delai <= 0:
#                    self.cle.changerEtat(

                # attendre 100 millisecondes (délai de référence)

                time.sleep(0.1)

        # La partie est terminée. Attendre le clic sur la croix dans la fenêtre
        # pour fermer l'application

        self.presentation.attendreFermetureFenetre()
