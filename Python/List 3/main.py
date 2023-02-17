match input("Type the number of the exercise you want to run : "):
    case "1":
        # Valeurs est une liste comprenant 5 cellules. La dernière valeur de cette liste doit être un flottant entré au clavier. En commençant par la fin de la liste, avec une boucle, faire en sorte que chaque valeur corresponde à la racine carrée de la valeur immédiatement suivante (par exemple, si la valeur entrée est 1024, alors Valeurs = [1.54, 2.38, 5.66, 32, 1024]).
        values = [float(0)] * 5
        values[4] = float(input("Enter a float : "))
        for i in range(4, 0, -1):
            values[i - 1] = values[i] ** 0.5
        # print the list with a precision of 2 decimal places if the number has a decimal part
        print([format(i, ".2f") if i % 1 else int(i) for i in values])
