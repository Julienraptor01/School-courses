import math

match input("Type the number of the exercise you want to run : "):
    case "1":
        # Écrire une fonction qui reçoit en paramètre une température en degrés Celsius et qui la convertit en degrés Fahrenheit. Les valeurs sont des entiers signés. La formule de conversion est F = C * 9 / 5 + 32
        def celsius_to_fahrenheit(celsius):
            return celsius * 9 / 5 + 32
        print("The temperature in Fahrenheit is", celsius_to_fahrenheit(int(input("Enter a temperature in Celsius : "))))
    case "2":
        # Écrire une fonction qui reçoit en paramètre les valeurs pour R et I et qui retourne la valeur pour U. Les valeurs sont des flottants. La loi d'Ohm est : la tension U (en volts) aux bornes d'une résistance R (en ohms) est proportionnelle à l'intensité du courant électrique I (en ampères) qui la traverse.
        def ohm_law(r, i):
            return r * i
        print("The voltage is", ohm_law(float(input("Enter the resistance (in ohms) : ")), float(input("Enter the current (in amperes) : "))), "volts")
    case "3":
        # Écrire une fonction qui reçoit en paramètre le rayon d’un cercle et qui retourne la surface de ce cercle. Les valeurs sont des flottants. La surface d’un cercle est égale au produit de 3.14 (nombre pi) par la longueur du rayon du cercle au carré (par exemple, si le rayon est 3 cm, la surface doit être 28.26 cm2).
        def circle_surface(radius):
            return math.pi * radius ** 2
        print("The surface of the circle is", circle_surface(float(input("Enter the radius of the circle (in cm) : "))), "cm2")
    case "4":
        # Écrire une fonction qui reçoit en paramètre la taille des côtés a, b et c et qui retourne un booléen indiquant si le triangle est rectangle ou non (True = triangle rectangle, False = triangle  non rectangle). (théorème de Pythagore). Les valeurs passées en paramètre sont des entiers.
        def is_right_triangle(a, b, c):
            return a ** 2 + b ** 2 == c ** 2 or a ** 2 + c ** 2 == b ** 2 or b ** 2 + c ** 2 == a ** 2
        print("The triangle is", {True: "a right triangle", False: "not a right triangle"}[is_right_triangle(int(input("Enter the length of the first side (in cm) : ")), int(input("Enter the length of the second side (in cm) : ")), int(input("Enter the length of the third side (in cm) : ")))])
    case "5":
        # Écrire une fonction qui reçoit en paramètre la taille pour les côtés a, b, c et d d'un quadrilatère et qui retourne soit 1 si ce quadrilatère est un losange (a = b = c = d), soit 2 si ce quadrilatère est un parallélogramme (a = c et b = d), ou 0 s’il ne s’agit ni d’un losange, ni d’un parallélogramme. Les valeurs passées en paramètre sont des flottants.
        def is_diamond_or_parallelogram(a, b, c, d):
            if a == b == c == d:
                return 1
            elif a == c and b == d:
                return 2
            else:
                return 0
        print("The quadrilateral is", {0: "neither a diamond nor a parallelogram", 1: "a diamond", 2: "a parallelogram"}[is_diamond_or_parallelogram(float(input("Enter the length of the first side (in cm) : ")), float(input("Enter the length of the second side (in cm) : ")), float(input("Enter the length of the third side (in cm) : ")), float(input("Enter the length of the fourth side (in cm) : ")))])
    case "6":
        # Écrire une fonction qui reçoit en paramètre une liste de valeurs entières dans laquelle uniquement la première valeur est pertinente et qui reçoit aussi le nombre de valeurs que devra contenir cette liste. Avec une boucle, faire en sorte que chaque valeur dans la liste corresponde à la somme des valeurs qui la précèdent. Retourner cette liste.
        def sum_of_previous_values(values, number_of_values):
            for i in range(1, number_of_values):
                values[i] = sum(values[:i])
            return values
        valuesList = [int(input("Enter the first value : "))] + [0] * (int(input("Enter the number of values : ")) - 1)
        print("The list of values is", sum_of_previous_values(valuesList, len(valuesList)))
    case "7":
        # Écrire une fonction qui reçoit en paramètre une liste de valeurs entières et qui retourne cette liste dans laquelle chaque valeur a été séparée de la suivante avec la valeur 0.
        '''
        def separate_values_with_zero(values):
            return [value for value in values for i in range(2)]
        print("The list of values is", separate_values_with_zero([int(input("Enter a value : ")) for i in range(int(input("Enter the number of values : ")))]))
        '''

