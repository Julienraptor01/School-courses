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

            self.cle.changer_etat()

            evenement = self.presentation.lire_evenement()
            self.dkjr.changer_etat(evenement)

            if self.dkjr.etat == DKJr.LIBRE_HAUT and self.dkjr.position == 2:
                time.sleep(0.3)
                if self.cle.etat == 1:
                    # clear the key
                    self.cle.effacer_cle()
                    # draw the monkey with the key
                    self.dkjr.attrapage_cle(True)
                    # remove a part of the cage
                    # add points
                    self.score += 10
                    # wait a bit
                    time.sleep(0.3)
                    # start good falling animation
                    self.dkjr.chute_apres_cle(True)
                    # wait a bit
                    time.sleep(0.3)
                    # reset the monkey
                    self.dkjr.reinitialiser_etat(True)
                else:
                    # start bad falling animation
                    self.dkjr.attrapage_cle(False)
                    # wait a bit
                    time.sleep(0.3)
                    # place the monkey in the bush
                    self.dkjr.chute_apres_cle(False)
                    # add a failure to the counter
                    self.nbEchecs += 1
                    # wait a bit
                    time.sleep(0.3)
                    # if the counter isn't 3, reset the monkey
                    if self.nbEchecs < 3:
                        self.dkjr.reinitialiser_etat(False)

            time.sleep(0.1)

        self.presentation.attendre_fermeture_fenetre()
