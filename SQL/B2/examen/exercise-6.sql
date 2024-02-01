-- Dans la base de donnée Hopital:

-- Rechercher triés par ordre alphabétique sur le nom et le prénom, les patients nés entre 1980 et 2000 dont le nom commence par 'D' et le prénom par 'K'.
-- On affichera le nom, le prénom, la date de naissance ainsi que la localité.
-- Pour les patients dont on ne connaît pas la localité (code adresse non précisé), on affichera 'Domicile inconnu'.

-- Résoudre avec un opérateur ensembliste(50%) ainsi qu'au moyen de jointures(50%) (identifier clairement chacune des solutions)

-- 1) Avec un opérateur ensembliste

SELECT nom,
	prenom,
	datenaissance,
	localite
FROM patients
WHERE nom LIKE 'D%' AND prenom LIKE 'K%' AND datenaissance BETWEEN '1980-01-01' AND '2000-12-31'
UNION
SELECT nom,
	prenom,
	datenaissance,
	'Domicile inconnu' AS localite
FROM patients
WHERE nom LIKE 'D%' AND prenom LIKE 'K%' AND datenaissance BETWEEN '1980-01-01' AND '2000-12-31' AND codeadresse IS NULL
ORDER BY nom,
	prenom;

-- 2) Avec une jointure

SELECT nom,
	prenom,
	datenaissance,
	localite
FROM patients
	JOIN adresses ON patients.codeadresse = adresses.codeadresse
WHERE nom LIKE 'D%' AND prenom LIKE 'K%' AND date_naissance BETWEEN '1980-01-01' AND '2000-12-31'
UNION
SELECT nom,
	prenom,
	datenaissance,
	'Domicile inconnu' AS localite
FROM patient
WHERE nom LIKE 'D%' AND prenom LIKE 'K%' AND datenaissance BETWEEN '1980-01-01' AND '2000-12-31' AND codeadresse IS NULL
ORDER BY nom,
	prenom;