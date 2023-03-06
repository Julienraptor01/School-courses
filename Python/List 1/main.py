import random
import math

match input("Type the number of the exercise you want to run : "):
    case "1":
        print("La superficie du local", input("Numéro du local : "), "se trouvant dans l'immeuble", input("Nom de l'immeuble : "), "est de", float(input("Longueur du local : ")) * float(input("Largeur du local : ")), "m².")
    case "2":
        print("La tension est de", float(input("Intensité : ")) * float(input("Résistance : ")), "V.")
    case "3":
        minutes = random.randint(0, 1440)
        print(minutes, "minutes correspond à", minutes // 60, "heures et", minutes % 60, "minutes.")
    case "4":
        print("La surface du cercle est de", math.pi * float(input("Rayon : ")) ** 2, "m².")
    case "5":
        time = input("Temps (h:m) : ").split(":")
        print("La vitesse moyenne est de", float(input("Distance (km) : ")) / (float(time[0]) + float(time[1]) / 60), "km/h.")
    case "6":
        a, b, c = float(input("Côté a : ")), float(input("Côté b : ")), float(input("Côté c : "))
        print("Le triangle est rectangle :", a ** 2 + b ** 2 == c ** 2 or a ** 2 + c ** 2 == b ** 2 or b ** 2 + c ** 2 == a ** 2)
    case "7":
        a, b, c = float(input("Côté a : ")), float(input("Côté b : ")), float(input("Côté c : "))
        if a == b == c:
            print("Le triangle est équilatéral.")
        elif a == b or a == c or b == c:
            print("Le triangle est isocèle.")
        else:
            print("Le triangle est quelconque.")
