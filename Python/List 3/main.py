import random

match input("Type the number of the exercise you want to run : "):
    case "1":
        # Valeurs est une liste comprenant 5 cellules. La dernière valeur de cette liste doit être un flottant entré au clavier. En commençant par la fin de la liste, avec une boucle, faire en sorte que chaque valeur corresponde à la racine carrée de la valeur immédiatement suivante (par exemple, si la valeur entrée est 1024, alors Valeurs = [1.54, 2.38, 5.66, 32, 1024]).
        values = [float(0)] * 5
        values[4] = float(input("Enter a float : "))
        for i in range(4, 0, -1):
            values[i - 1] = values[i] ** 0.5
        # print the list with a precision of 2 decimal places if the number has a decimal part
        print([format(i, ".2f") if i % 1 else int(i) for i in values])
    case "2":
        # Valeurs est une liste comprenant 10 cellules. La 1re valeur de cette liste doit avoir été entrée au clavier. Avec une boucle, faire en sorte que chaque valeur corresponde à la somme des valeurs qui la précèdent (par exemple, si la valeur entrée est 1, alors Valeurs = [1, 1, 2, 4, 8, 16, 32, 64, 128, 256]).
        values = [int(0)] * 10
        values[0] = int(input("Enter an integer : "))
        for i in range(1, 10):
            values[i] = sum(values[:i])
        print(values)
    case "3":
        # Stocker initialement dans une liste 5 valeurs ordonnées par ordre croissant. Entrer au clavier une valeur comprise entre 0 et 10 et, avec une boucle, insérer cette valeur au bon endroit dans la liste en veillant à garder les valeurs ordonnées par ordre croissant (par exemple, Pour Valeurs = [-70, 3, 45, 86, 101], si la valeur entrée est 9, alors Valeurs = [-70, 3, 9, 45, 86, 101]).
        values = [-70, 3, 45, 86, 101]
        value = int(input("Enter an integer between 0 and 10 : "))
        for i in range(len(values)):
            if value < values[i]:
                values.insert(i, value)
                break
        print(values)
    case "4":
        # Avec une boucle, entrer 10 flottants. À chaque entrée d’une valeur au clavier, celle-ci doit être insérée au bon endroit dans une liste de sorte à garder constamment les valeurs ordonnées par ordre décroissant. Il ne peut y avoir dans cette liste qu’une seule occurrence de chaque valeur. Par exemple, si la valeur -85 a été entrée à 3 reprises, elle ne figurera qu’une seule fois dans la liste.
        values = []
        for i in range(10):
            value = float(input("Enter a float : "))
            if value not in values:
                for j in range(len(values)):
                    if value > values[j]:
                        values.insert(j, value)
                        break
                else:
                    values.append(value)
        print(values)
    case "5":
        # Avec une boucle, placer dans une liste 5 valeurs entières générées aléatoirement entre 0 et 7. (Pour générer des nombres aléatoires, un exemple est donné dans la page 8 des notes de cours). Ensuite, entrer au clavier une valeur et, avec une boucle, supprimer toutes les occurrences de cette valeur dans la liste (par exemple, pour Valeurs = [3, 7, 0, 1, 3] et la valeur 3 entrée au clavier, on aura Valeurs = [7, 0, 1]).
        values = [random.randint(0, 7) for i in range(5)]
        value = int(input("Enter an integer between 0 and 7 : "))
        while value in values:
            values.remove(value)
        print(values)
    case "6":
        # Dans une liste de valeurs entières, avec une boucle, séparer chaque valeur de la suivante avec la valeur 0 (par exemple, pour Valeurs = [3, 17, 10, -8], on aura Valeurs = [3, 0, 17, 0, 10, 0, -8]).
        values = [3, 17, 10, -8]
        for i in range(len(values) - 1, 0, -1):
            values.insert(i, 0)
        print(values)
