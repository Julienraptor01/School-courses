import time

from cle import Cle
from corbeau import Corbeau
from croco import Croco
from dkjr import DKJr
from dk import DK
from ennemis import Ennemis


class Jeu:
    def __init__(self, presentation):
        self.presentation = presentation
        self.cle = Cle(self.presentation)
        self.dkjr = DKJr(self.presentation)
        self.dk = DK(self.presentation)
        self.ennemis = Ennemis()
        self.listeCorbeaux = []
        self.listeCrocos = []
        self.nbEchecs = 0
        self.score = 0
        self.nb200 = 0

    def demarrer(self):
        self.presentation.afficher_score(self.score)

        while self.nbEchecs < 3:

            self.cle.changer_etat()

            self.bouger_ennemis()

            if self.effectuer_collision() and self.nbEchecs == 3:
                break

            self.dkjr.changer_etat(self.presentation.lire_evenement())

            if self.effectuer_collision():
                pass

            elif self.dkjr.etat == DKJr.LIBRE_HAUT and self.dkjr.position == 2:
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
                    # add 10 points
                    self.manipulation_score(10)
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
                        # add 10 points
                        self.manipulation_score(10)
                    # start good falling animation
                    self.dkjr.chute_apres_cle(True)
                    # wait a bit
                    time.sleep(0.3)
                    # clear the ennemies
                    self.nettoyer_ennemis()
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
                    # draw the fail symbol
                    self.presentation.afficher_echec(self.nbEchecs)
                    # add a failure to the counter
                    self.nbEchecs += 1
                    # wait a bit
                    time.sleep(0.3)
                    # if the counter isn't 3, reset the monkey
                    if self.nbEchecs < 3:
                        # clear the ennemies
                        self.nettoyer_ennemis()
                        # reset the monkey
                        self.dkjr.reinitialiser_etat(False)

            time.sleep(0.1)

        self.jouer_fin()

        self.presentation.attendre_fermeture_fenetre()

    def nettoyer_ennemis(self):
        for corbeau in self.listeCorbeaux:
            if corbeau.position in [0, 1, 2]:
                corbeau.effacer_corbeau()
                self.listeCorbeaux.remove(corbeau)
        for croco in self.listeCrocos:
            if croco.position in [1, 2, 3]:
                croco.effacer_croco()
                self.listeCrocos.remove(croco)

    def bouger_ennemis(self):
        if (ennemi := self.ennemis.changer_etat()) == self.ennemis.CORBEAU:
            self.listeCorbeaux.append(Corbeau(self.presentation))
            print(self.ennemis.CORBEAU)
        elif ennemi == self.ennemis.CROCO:
            self.listeCrocos.append(Croco(self.presentation))
            print(self.ennemis.CROCO)
        else:
            print(self.ennemis.RIEN, end='')
        for corbeau in self.listeCorbeaux:
            if corbeau.changer_etat() == 1:
                self.listeCorbeaux.remove(corbeau)
        for croco in self.listeCrocos:
            if croco.changer_etat() == 1:
                self.listeCrocos.remove(croco)

    def jouer_fin(self):
        # TODO : add special score sounds like 13, 42, 69, 666, 999, 1000, 1337, 9001, 10000
        # play 9999 - score times the bad sound
        for i in range(9999 - self.score):
            self.presentation.jouer_son(1)
            time.sleep(0.00001)

    def tester_collisions(self):
        if self.dkjr.etat == DKJr.LIBRE_BAS:
            for croco in self.listeCrocos:
                if croco.position == self.dkjr.position and croco.augmente is False:
                    croco.effacer_croco()
                    self.listeCrocos.remove(croco)
                    return True
        elif self.dkjr.etat == DKJr.LIANE_BAS or self.dkjr.etat == DKJr.SAUT_BAS or self.dkjr.etat == DKJr.DOUBLE_LIANE_BAS:
            for corbeau in self.listeCorbeaux:
                if corbeau.position == self.dkjr.position:
                    corbeau.effacer_corbeau()
                    self.listeCorbeaux.remove(corbeau)
                    return True
        elif self.dkjr.etat == DKJr.LIBRE_HAUT and self.dkjr.position != 2:
            for croco in self.listeCrocos:
                if croco.position == self.dkjr.position and croco.augmente is True:
                    croco.effacer_croco()
                    self.listeCrocos.remove(croco)
                    return True
        return False

    def effectuer_collision(self):
        if self.tester_collisions():
            self.presentation.jouer_son(1)
            for i in range(3):
                self.dkjr.effacer_dkjr()
                time.sleep(0.05)
                self.dkjr.afficher_dkjr()
                time.sleep(0.05)
            self.presentation.afficher_echec(self.nbEchecs)
            self.nbEchecs += 1
            return True
        return False

    def manipulation_score(self, valeur):
        self.score += valeur
        self.presentation.afficher_score(self.score)
        if int(self.score / 200) - self.nb200 > 0:
            self.nb200 += 1
            for i in range(10):
                self.presentation.jouer_son(3)
                time.sleep(0.01)
            if self.ennemis.incrementDifficulte > 2:
                self.ennemis.incrementDifficulte = 2
            if self.nbEchecs > 0:
                self.nbEchecs -= 1
                self.effacer_echec(self.nbEchecs)

    def effacer_echec(self, num):
        self.presentation.effacer_carre(7, 27 + num, 1, 1)