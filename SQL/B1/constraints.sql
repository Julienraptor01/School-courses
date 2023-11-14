-- Création de la table Auteurs
CREATE TABLE Auteurs (
	ID_Auteur NUMBER(10) PRIMARY KEY,
	Nom_Auteur VARCHAR2(100) NOT NULL,
	Nationalite_Auteur VARCHAR2(100) NOT NULL
);

-- Création de la table Livres
CREATE TABLE Livres (
	ID_Livre NUMBER(10) PRIMARY KEY,
	Titre_Livre VARCHAR2(200) UNIQUE,
	ID_Auteur NUMBER(10),
	Date_Publication DATE,
	Prix_Location NUMBER(10, 2) CHECK (Prix_Location BETWEEN 0 AND 1000),
	Quantite_Stock NUMBER(10) CHECK (Quantite_Stock >= 0),
	CONSTRAINT Livres_Auteurs_FK FOREIGN KEY (ID_Auteur) REFERENCES Auteurs(ID_Auteur)
);

-- Création d'une trigger pour la contrainte de Date_Publication
CREATE OR REPLACE TRIGGER Check_Date_Publication
BEFORE INSERT OR UPDATE ON Livres
FOR EACH ROW
BEGIN
	IF :NEW.Date_Publication IS NULL OR :NEW.Date_Publication > SYSDATE THEN
		RAISE_APPLICATION_ERROR(-20001, 'La date de publication doit être non nulle et antérieure ou égale à la date actuelle.');
	END IF;
END;
/
