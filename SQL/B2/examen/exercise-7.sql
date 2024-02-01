-- A réaliser dans la base de données Hopital.

-- Le fabricant Pfizer crée un nouveau médicament dénommé « Vaccin COVID-19 ».

-- Son numéro est au format MXXX,où M est le caractère ‘M’, suivi du numéro maximum des médicaments présents dans la base +1, sur 3 caractères, par exemple : ‘M078’.


-- Celui-ci appartient au groupe «VACCINS-GAMMAGLOBULINES-SERUMS», est de type « Ampoule » et est indiqué en cas d' « Eradication du COVID-19 ».

-- Il est composé, entre-autres, des mêmes substances que le médicament « EFFERBALGINE», mais dans des quantités encore inconnues.


-- Insérez ces données à l’aide de deux commandes d’insertion uniquement, en utilisant le moins possible de données statiques,
-- afin que, par exemple, la requête fonctionne peu importe le nombre de médicaments déjà présents dans la base.


INSERT INTO medicament(
	nummedicament,
	nommedicament,
	typemedicament,
	groupemedicament,
	indicationmedicament
)VALUES(
	'M078',
	'Vaccin COVID-19',
	'Ampoule',
	'VACCINS-GAMMAGLOBULINES-SERUMS',
	'Eradication du COVID-19'
);