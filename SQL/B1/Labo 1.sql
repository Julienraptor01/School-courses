/*
Afficher toutes les caractéristiques des films, classés par année de production décroissante puis par ordre alphabétique croissant de titre.
the table is CS_FILMS
*/

SELECT * FROM CS_FILMS ORDER BY ANNEE DESC, TITRE ASC;

/*
Donner la liste des nationalités des intervenants.
*/

SELECT DISTINCT NATIONALITE FROM CS_INTERVENANTS;

/*
Donner les titres des films de plus de 120 minutes, triés par ordre croissant de durée.
*/

SELECT TITRE, DUREE FROM CS_FILMS WHERE DUREE > 120 ORDER BY DUREE ASC;

/*
Donner le nom, l’adresse et le numéro de téléphone des salles de Lille, triées par adresse puis par nom de manière décroissante.
*/

SELECT * FROM CS_SALLES WHERE LOWER(VILLESALLE) = 'lille' ORDER BY ADRESSESALLE ASC, NOMSALLE DESC;

/*
Donner la liste des adhérents dont la cotisation n’est pas en ordre de payement, triée par ordre décroissant de code postal puis alphabétique sur le nom.
*/

SELECT * FROM CS_ADHERENTS WHERE ORDRECOTISATION IS NULL ORDER BY CODE_POSTAL DESC, NOMADHE ASC;

/*
Donner la liste des films dont le titre contient la chaîne de caractères "la", sans respect de la casse.
*/

SELECT * FROM CS_FILMS WHERE LOWER(TITRE) LIKE '%la%';

/*
Donner la liste des films dont le titre contient l’article défini "la", sans respect de la casse.
*/

SELECT * FROM CS_FILMS WHERE LOWER(TITRE) LIKE 'la %' OR LOWER(TITRE) LIKE '% la %';

/*
Donner la liste des intervenants dont la nationalité n’est ni allemande, ni italienne, ni britannique (DE, IT, GB), et dont le nom contient la lettre "e" (sans respect de la casse).
*/

SELECT * FROM CS_INTERVENANTS WHERE NATIONALITE NOT IN ('DE', 'IT', 'GB') AND LOWER(NOM) LIKE '%e%';