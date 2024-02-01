-- ATTENTION: CECI NE PEUT PAS ETRE TESTE DANS SQLDEVELOPER

-- Soit la commande de création de table suivante, exécutée correctement :

DROP TABLE artistes;

CREATE TABLE artistes(
	nr NUMBER CONSTRAINT cpnartiste PRIMARY KEY,
	nom VARCHAR2(20),
	prenom VARCHAR2(20),
	datenaiss DATE
);

-- Donner le résultat de la commande :

SELECT object_type,
	object_name
FROM user_objects
ORDER BY object_type;


-- OBJECT_TYPE	OBJECT_NAME
-- INDEX	CPNARTISTE
-- TABLE	ARTISTES