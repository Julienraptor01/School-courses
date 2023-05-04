import pygame
import time


def attendre_fermeture_fenetre():
    while True:
        for evenement in pygame.event.get():
            if evenement.type == pygame.QUIT:
                pygame.quit()
                exit()
        time.sleep(0.2)


class Presentation:

    def __init__(self):
        pygame.init()

        self.imgFondEcran = pygame.image.load("images/autres/fondEcran.png")
        self.imgCle1 = pygame.image.load("images/autres/cle1.png")
        self.imgCle2 = pygame.image.load("images/autres/cle2.png")
        self.imgCle3 = pygame.image.load("images/autres/cle3.png")
        self.imgCle4 = pygame.image.load("images/autres/cle4.png")
        self.imgCorbeau1 = pygame.image.load("images/autres/corbeau1.png")
        self.imgCorbeau2 = pygame.image.load("images/autres/corbeau2.png")
        self.imgCroco1 = pygame.image.load("images/autres/croco1.png")
        self.imgCroco2 = pygame.image.load("images/autres/croco2.png")
        self.imgCroco3 = pygame.image.load("images/autres/croco3.png")
        self.imgCroco4 = pygame.image.load("images/autres/croco4.png")
        self.imgCroco5 = pygame.image.load("images/autres/croco5.png")

        self.imgDKJr1 = pygame.image.load("images/dkjr/dkjr1.png")
        self.imgDKJr2 = pygame.image.load("images/dkjr/dkjr2.png")
        self.imgDKJr3 = pygame.image.load("images/dkjr/dkjr3.png")
        self.imgDKJr4 = pygame.image.load("images/dkjr/dkjr4.png")
        self.imgDKJr5 = pygame.image.load("images/dkjr/dkjr5.png")
        self.imgDKJr6 = pygame.image.load("images/dkjr/dkjr6.png")
        self.imgDKJr7 = pygame.image.load("images/dkjr/dkjr7.png")
        self.imgDKJr8 = pygame.image.load("images/dkjr/dkjr8.png")
        self.imgDKJr9 = pygame.image.load("images/dkjr/dkjr9.png")
        self.imgDKJr10 = pygame.image.load("images/dkjr/dkjr10.png")
        self.imgDKJr11 = pygame.image.load("images/dkjr/dkjr11.png")
        self.imgDKJr12 = pygame.image.load("images/dkjr/dkjr12.png")
        self.imgDKJr13 = pygame.image.load("images/dkjr/dkjr13.png")
        self.imgDKJrEchec = pygame.image.load("images/dkjr/dkjrechec.png")

        self.imgCage1 = pygame.image.load("images/autres/cage1.png")
        self.imgCage2 = pygame.image.load("images/autres/cage2.png")
        self.imgCage3 = pygame.image.load("images/autres/cage3.png")
        self.imgCage4 = pygame.image.load("images/autres/cage4.png")

        self.imgRireDK = pygame.image.load("images/autres/rireDK.png")

        self.imgChiffre0 = pygame.image.load("images/chiffres/Zero.png")
        self.imgChiffre1 = pygame.image.load("images/chiffres/Un.png")
        self.imgChiffre2 = pygame.image.load("images/chiffres/Deux.png")
        self.imgChiffre3 = pygame.image.load("images/chiffres/Trois.png")
        self.imgChiffre4 = pygame.image.load("images/chiffres/Quatre.png")
        self.imgChiffre5 = pygame.image.load("images/chiffres/Cinq.png")
        self.imgChiffre6 = pygame.image.load("images/chiffres/Six.png")
        self.imgChiffre7 = pygame.image.load("images/chiffres/Sept.png")
        self.imgChiffre8 = pygame.image.load("images/chiffres/Huit.png")
        self.imgChiffre9 = pygame.image.load("images/chiffres/Neuf.png")

        self.sonDKJr = pygame.mixer.Sound("sons/dkjrMvt.mp3")
        self.sonDKJrEchec = pygame.mixer.Sound("sons/dkjrEchec.mp3")
        self.sonOuvrirCage = pygame.mixer.Sound("sons/dkjrOuvreCage.mp3")
        self.sonDKJrPoint = pygame.mixer.Sound("sons/dkjrPoint.mp3")
        self.sonTic = pygame.mixer.Sound("sons/cleTic.mp3")

        pygame.display.set_caption("Donkey Kong JR")
        pygame.display.set_icon(pygame.image.load("images/autres/iconeFenetre.png"))
        self.ecran = pygame.display.set_mode((1240, 640))
        self.ecran.blit(self.imgFondEcran, (0, 0))
        pygame.display.update()

    @staticmethod
    def lire_evenement():
        for evenement in pygame.event.get():
            if evenement.type == pygame.QUIT:
                pygame.quit()
                exit()
            elif evenement.type == pygame.KEYDOWN:
                return evenement.key
        return -1

    def afficher_cle(self, num):
        if num == 1:
            self.afficher_image(3, 12, self.imgCle1)
        elif num == 2:
            self.afficher_image(3, 13, self.imgCle2)
        elif num == 3:
            self.afficher_image(3, 13, self.imgCle3)
        elif num == 4:
            self.afficher_image(3, 13, self.imgCle4)

    def afficher_corbeau(self, colonne, num):
        if num == 1:
            self.afficher_image(10, colonne, self.imgCorbeau1)
        elif num == 2:
            self.afficher_image(9, colonne, self.imgCorbeau2)

    def afficher_croco(self, colonne, num):
        if num == 1:
            self.afficher_image(8, colonne, self.imgCroco1)
        elif num == 2:
            self.afficher_image(8, colonne, self.imgCroco2)
        elif num == 3:
            self.afficher_image(9, 23, self.imgCroco3)
        elif num == 4:
            self.afficher_image(12, colonne, self.imgCroco4)
        elif num == 5:
            self.afficher_image(12, colonne, self.imgCroco5)

    def afficher_dk_jr(self, ligne, colonne, num):
        if num == 1:
            self.afficher_image(ligne, colonne, self.imgDKJr1)
        elif num == 2:
            self.afficher_image(ligne, colonne, self.imgDKJr2)
        elif num == 3:
            self.afficher_image(ligne, colonne, self.imgDKJr3)
        elif num == 4:
            self.afficher_image(ligne, colonne, self.imgDKJr4)
        elif num == 5:
            self.afficher_image(10, 21, self.imgDKJr5)
        elif num == 6:
            self.afficher_image(7, 21, self.imgDKJr6)
        elif num == 7:
            self.afficher_image(ligne, colonne, self.imgDKJr7)
        elif num == 8:
            self.afficher_image(ligne, colonne, self.imgDKJr8)
        elif num == 9:
            self.afficher_image(5, 12, self.imgDKJr9)
        elif num == 10:
            self.afficher_image(3, 11, self.imgDKJr10)
        elif num == 11:
            self.afficher_image(6, 10, self.imgDKJr11)
        elif num == 12:
            self.afficher_image(6, 11, self.imgDKJr12)
        elif num == 13:
            self.afficher_image(11, 7, self.imgDKJr13)

    def afficher_cage(self, num):
        if num == 1:
            self.afficher_image(2, 7, self.imgCage1)
        elif num == 2:
            self.afficher_image(2, 9, self.imgCage2)
        elif num == 3:
            self.afficher_image(4, 7, self.imgCage3)
        elif num == 4:
            self.afficher_image(4, 9, self.imgCage4)

    def afficher_rire_dk(self):
        self.afficher_image(3, 8, self.imgRireDK)

    def afficher_echec(self, num):
        self.afficher_image(7, 27 + num, self.imgDKJrEchec)

    def afficher_score(self, score):
        self.afficher_chiffre(3, 26, int(score / 1000))
        self.afficher_chiffre(3, 27, int(score / 100) % 10)
        self.afficher_chiffre(3, 28, int(score / 10) % 10)
        self.afficher_chiffre(3, 29, score % 10)

    def afficher_chiffre(self, ligne, colonne, chiffre):
        if chiffre == 0:
            self.afficher_image(ligne, colonne, self.imgChiffre0)
        elif chiffre == 1:
            self.afficher_image(ligne, colonne, self.imgChiffre1)
        elif chiffre == 2:
            self.afficher_image(ligne, colonne, self.imgChiffre2)
        elif chiffre == 3:
            self.afficher_image(ligne, colonne, self.imgChiffre3)
        elif chiffre == 4:
            self.afficher_image(ligne, colonne, self.imgChiffre4)
        elif chiffre == 5:
            self.afficher_image(ligne, colonne, self.imgChiffre5)
        elif chiffre == 6:
            self.afficher_image(ligne, colonne, self.imgChiffre6)
        elif chiffre == 7:
            self.afficher_image(ligne, colonne, self.imgChiffre7)
        elif chiffre == 8:
            self.afficher_image(ligne, colonne, self.imgChiffre8)
        elif chiffre == 9:
            self.afficher_image(ligne, colonne, self.imgChiffre9)

    def afficher_image(self, ligne, colonne, image):
        rect = image.get_rect()
        rect.x = colonne * 40
        rect.y = ligne * 40
        self.ecran.blit(image, rect)
        pygame.display.update()

    def effacer_carre(self, ligne, colonne, nb_lignes=1, nb_colonnes=1):
        self.ecran.blit(self.imgFondEcran,
                        (colonne * 40, ligne * 40, nb_colonnes * 40, nb_lignes * 40),
                        (colonne * 40, ligne * 40, nb_colonnes * 40, nb_lignes * 40))
        pygame.display.update()

    def jouer_son(self, num):
        if num == 0:
            pygame.mixer.Sound.play(self.sonDKJr)
        elif num == 1:
            pygame.mixer.Sound.play(self.sonDKJrEchec)
        elif num == 2:
            pygame.mixer.Sound.play(self.sonDKJrPoint)
        elif num == 3:
            pygame.mixer.Sound.play(self.sonOuvrirCage)
        elif num == 4:
            pygame.mixer.Sound.play(self.sonTic)
