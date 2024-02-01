-- Il y a ici 4 sous questions, chacune vaut un quart de la cote de la question.
-- Numérotez clairement vos réponses!
-- Attention, utilisez les données fournies dans le PDF au début de l'examen!

--     Donner les tuples de la relation X:
X = PROJECTION[ SELECTION(
JOINT_EXT RIGHT(PROJETS, DEPARTEMENTS / PROJETS.NUMDEP = DEPARTEMENTS.NUMDEP) /
PROJETS.NUMPRO EST INCONNU),
DEPARTEMENTS.NUMDEP]

--     Citez le nom des opérateurs utilisés dans la question 1.:

--     Opérateur(s) ensembliste(s): ______________________
--     Opérateur(s) relationnel(s)  : ______________________
--     Opérateur(s) additionnel(s) :_______________________

--     Quelle est la question à poser pour obtenir ce résultat?
--     Ecrire la requête SQL correspondant à l'expression algébrique ci-dessus (au point 1) .

-- 1)

-- 2)
-- Opérateur(s) ensembliste(s): RIGHT
-- Opérateur(s) relationnel(s)  : PROJECTION, SELECTION, JOINT_EXT
-- Opérateur(s) additionnel(s) : /

-- 3)
-- Quels sont les numéros des départements qui ont des projets dont le numéro est inconnu ?

-- 4)
SELECT DISTINCT DEPARTEMENTS.NUMDEP
FROM PROJETS, DEPARTEMENTS
WHERE PROJETS.NUMDEP = DEPARTEMENTS.NUMDEP AND PROJETS.NUMPRO IS NULL;
