import time

from cle import Cle
from dkjr import DKJr
from dk import DK


class Jeu:
    def __init__(self, presentation):
        self.presentation = presentation
        self.cle = Cle(self.presentation)
        self.dkjr = DKJr(self.presentation)
        self.dk = DK(self.presentation)
        self.nbEchecs = 0
        self.score = 0

    def demarrer(self):

        while self.nbEchecs < 3:

            self.presentation.afficher_score(self.score)
            self.cle.changer_etat()

            self.dkjr.changer_etat(self.presentation.lire_evenement())

            if self.dkjr.etat == DKJr.LIBRE_HAUT and self.dkjr.position == 2:
                time.sleep(0.3)
                if self.cle.etat == 1:
                    # clear the key
                    self.cle.effacer_cle()
                    # draw the monkey with the key
                    self.dkjr.attrapage_cle(True)
                    # play good sound (10x)
                    for i in range(10):
                        self.presentation.jouer_son(2)
                        time.sleep(0.01)
                    # add points
                    self.score += 10
                    # wait a bit
                    time.sleep(0.3)
                    # remove a part of the cage
                    self.dk.changer_etat()
                    # if cage fully open
                    if self.dk.etat == 0:
                        # give him a smile
                        self.dk.yay()
                        # play good sound
                        self.presentation.jouer_son(3)
                        # add 10 bonus points
                        self.score += 10
                    # start good falling animation
                    self.dkjr.chute_apres_cle(True)
                    # wait a bit
                    time.sleep(0.3)
                    # reset the monkey
                    self.dkjr.reinitialiser_etat(True)
                    # if cage fully open
                    if self.dk.etat == 0:
                        # encage him back
                        self.dk.reinitialiser_etat()
                else:
                    # start bad falling animation
                    self.dkjr.attrapage_cle(False)
                    # wait a bit
                    time.sleep(0.3)
                    # place the monkey in the bush
                    self.dkjr.chute_apres_cle(False)
                    # play bad sound
                    self.presentation.jouer_son(1)
                    # add a failure to the counter
                    self.nbEchecs += 1
                    # wait a bit
                    time.sleep(0.3)
                    # draw the fail symbol
                    self.presentation.afficher_echec(self.nbEchecs - 1)
                    # if the counter isn't 3, reset the monkey
                    if self.nbEchecs < 3:
                        self.dkjr.reinitialiser_etat(False)

            time.sleep(0.1)

        # TODO : add special score sounds like 13, 42, 69, 666, 999, 1000, 1337, 9001, 10000
        # play 9999 - score times the bad sound
        for i in range(9999 - self.score):
            self.presentation.jouer_son(1)
            time.sleep(0.00001)

        self.presentation.attendre_fermeture_fenetre()
