match input("Type the number of the exercise you want to run : "):
    case "1":
        # Saisir un nombre entier positif et inverser dans la variable l’ordre des chiffres de ce nombre (par exemple, si la valeur de départ est 5342 dans la variable i, l'exécution du programme donnera la valeur 2435 dans la variable i).
        print("".join(reversed(str(int(input("Enter a positive integer : "))))))
    case "2":
        # Saisir un nombre entier positif et afficher la somme et la moyenne arithmétique de ses chiffres (par exemple, pour le nombre 2155, la somme des chiffres est 13 (2 + 1 + 5 + 5) et la moyenne est 3,25 (13/4)).
        number = str(int(input("Enter a positive integer : ")))
        print("Sum :", sum(int(i) for i in number), "Average :", sum(int(i) for i in number) / len(number))
    case "3":
        # Afficher une table de multiplication ainsi :
        '''
        1   2   3   4   5   6   7   8   9  10
        2   4   6   8  10  12  14  16  18  20
        3   6   9  12  15  18  21  24  27  30
        4   8  12  16  20  24  28  32  36  40
        5  10  15  20  25  30  35  40  45  50
        6  12  18  24  30  36  42  48  54  60
        7  14  21  28  35  42  49  56  63  70
        8  16  24  32  40  48  56  64  72  80
        9  18  27  36  45  54  63  72  81  90
        10 20  30  40  50  60  70  80  90 100
        '''
        # Pour afficher la table en alignant correctement les nombres en colonnes (4 caractères pour chaque colonne), utilisez la fonction format() décrite dans la section 1.2 des notes de cours.
        for i in range(1, 11):
            for j in range(1, 11):
                print(format(i * j, "4d"), end="")
            print()
    case "4":
        # Afficher un sapin en étoiles ainsi :
        '''
            **
           ****
          ******
         ********
        **********
            **
            **
            **
            **
        '''
        number = int(input("Enter the number of lines : "))
        for i in range(1, number + 1):
            print(" " * (number - i) + "*" * (2 * i))
        for i in range(1, number - 1):
            print(" " * (number - 1) + "*" * 2)
