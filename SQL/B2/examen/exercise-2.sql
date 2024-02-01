-- 	PREMIERE PARTIE (75%)

-- 	Soient les tables Etudiants et Groupes ci-dessous :

-- 	Etudiants ($NrEtudiant(CHAR(10)), Nom (VARCHAR2(20)),Prenom (VARCHAR2(20), #NrGroupe (CHAR(4)),AnneeNaissance (CHAR(4)), DateInscription (DATE)))

-- 	Groupes ($NrGroupe (CHAR(4)), #Delegue (CHAR(10)))

-- 	Pour lesquelles:

-- 	Les clés primaires sont précédées du caractère $
-- 	Les clés étrangères sont précédées du caractère #

-- 	Réaliser, en un minimum de commandes, le script de création correspondant, en tenant compte des contraintes ci-dessous.

-- 	Toutes les contraintes doivent être nommées et doivent être non différées.
-- 	Pour être inscrit, l’étudiant doit avoir au moins 17 ans
-- 	Tout étudiant est attaché à un groupe
-- 	Tout groupe a un délégué(qui est un étudiant)
-- 	Les 4 premiers caractères du numéro de l'étudiant sont son mois et jour d’inscription (MMDD)


-- Consigne :

-- 	les noms de toutes les contraintes d'entités devront contenir le nom de la table et CP ;
-- 	celui des contraintes référentielles devront contenir au minimum le nom de la table et REF
-- 	celui des contraintes applicatives devront contenir au minimum le nom de la table et CK


DROP TABLE etudiants;
DROP TRIGGER tr_etudiants_age;
DROP TABLE groupes;


CREATE TABLE etudiants(
	nretudiant CHAR(10)CONSTRAINT cpetudiantsnretudiant PRIMARY KEY,
	nom VARCHAR2(20),
	prenom VARCHAR2(20),
	nrgroupe CHAR(4),
	anneenaissance CHAR(4),
	dateinscription DATE
);

CREATE TRIGGER tr_etudiants_age
BEFORE INSERT OR UPDATE OF anneenaissance ON etudiants
FOR EACH ROW
BEGIN
	IF EXTRACT(YEAR FROM :NEW.dateinscription) - :NEW.anneenaissance < 17 THEN
		RAISE_APPLICATION_ERROR(-20001, 'L''étudiant doit avoir au moins 17 ans');
	END IF;
END;


CREATE TABLE groupes(
	nrgroupe CHAR(4),
	delegue CHAR(10)CONSTRAINT refgroupesdelegueinetudiants REFERENCES etudiants(nretudiant)
);

ALTER TABLE etudiants ADD CONSTRAINT refetudiantsnrgroupeingroupes FOREIGN KEY(nrgroupe)REFERENCES groupes(nrgroupe);

-- DEUXIEME PARTIE(25%)

-- Insérez en un minimum de commandes dans les tables que vous venez de créer un nouveau groupe ainsi qu’un étudiant. L'étudiant appartient à ce groupe et en est le délégué.