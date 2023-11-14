-- CreationBaseInfosoft
DROP TABLE emppro;
DROP TABLE projets;
DROP TABLE departements CASCADE CONSTRAINTS;
DROP TABLE employes;

-- création de la base de donnees INFOSOFT
prompt 'Création de la base de donnees INFOSOFT';
prompt '****************************************';
prompt 'Creation de la table EMPLOYES';

CREATE TABLE employes(
	numsecu VARCHAR2(8)CONSTRAINT cpemployesnumsecu PRIMARY KEY,
	nom VARCHAR2(30),
	prenom VARCHAR2(30),
	datenais DATE,
	sexe CHAR(1)CONSTRAINT employessexe CHECK(sexe IN('M', 'F')),
	adresse VARCHAR2(30),
	codepostal CHAR(4),
	commune VARCHAR2(30),
	bareme NUMBER(5),
	numdep VARCHAR2(6),
	numchef VARCHAR2(8)CONSTRAINT refnumchefinemployes REFERENCES employes(numsecu)
);

prompt 'Creation de la table DEPARTEMENTS';

CREATE TABLE departements(
	numdep VARCHAR2(6)CONSTRAINT cpdepartements PRIMARY KEY,
	nomdep VARCHAR2(40),
	numsecu VARCHAR2(8)CONSTRAINT refdeptnumsecuinemployes REFERENCES employes(numsecu)
);
ALTER TABLE employes ADD CONSTRAINT refempnumdepindepartements FOREIGN KEY(numdep)REFERENCES departements(numdep);

prompt 'Creation de la table PROJETS';

CREATE TABLE projets(
	numpro VARCHAR2(6)CONSTRAINT cpprojets PRIMARY KEY,
	nompro VARCHAR2(50),
	datedebut DATE,
	site VARCHAR2(30),
	numdep VARCHAR2(6)CONSTRAINT refprojetsnumdepindepartements REFERENCES departements(numdep)
);

prompt 'Creation de la table EMPPRO';

CREATE TABLE emppro(
	numsecu VARCHAR2(8)CONSTRAINT refemppronumsecuinemployes REFERENCES employes(numsecu),
	numpro VARCHAR2(6)CONSTRAINT refemppronumproinprojets REFERENCES projets(numpro),
	heures VARCHAR2(2),
	CONSTRAINT cpemppro PRIMARY KEY(numsecu, numpro)
);

prompt 'Insertion des donnees dans la base de données INFOSOFT';
prompt '*******************************************************';

INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'123456', 'CURTIS', 'Tony', TO_DATE('1960-02-17', 'YYYY-MM-DD'), 'M', 'rue Egalite, 18', '4430', 'ANS', 70000
);
INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'451278', 'CELARIE', 'Clementine', TO_DATE('1990-10-10', 'YYYY-MM-DD'), 'F', 'rue Tige, 7', '4040', 'HERSTAL', 80000
);
INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'654321', 'BEART', 'Emmanuelle', TO_DATE('1995-04-04', 'YYYY-MM-DD'), 'F', 'quai Boverie, 102', '4000', 'LIEGE', 90000
);
INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'123457', 'HOFFMAN', 'Dustin', TO_DATE('1979-03-19', 'YYYY-MM-DD'), 'M', 'rue Lantin, 163', '4430', 'ANS', 60000
);
INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'789999', 'CLAVIER', 'Christian', TO_DATE('1987-11-10', 'YYYY-MM-DD'), 'M', 'La Batte, 9', '4000', 'LIEGE', 65000
);
INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'864231', 'LAFONT', 'Bernadette', TO_DATE('1975-01-14', 'YYYY-MM-DD'), 'F', 'rue Vaudrée, 162', '4000', 'LIEGE', 90000
);
INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'439549', 'DE NIRO', 'Robert', TO_DATE('1980-11-02', 'YYYY-MM-DD'), 'M', 'rue Bonne Foi, 5', '4040', 'HERSTAL', 88000
);
INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'121212', 'STALLONE', 'Sylvester', TO_DATE('1982-01-20', 'YYYY-MM-DD'), 'M', 'chaussee Romaine, 174', '4300', 'WAREMME', 95000
);
INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'334410', 'BERTHIER', 'Marie-Sophie L.', TO_DATE('1990-02-02', 'YYYY-MM-DD'), 'F', 'allee Dubois, 5', '4050', 'CHAUDFONTAINE', 67000
);
INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'935132', 'REDFORD', 'Robert', TO_DATE('1970-02-15', 'YYYY-MM-DD'), 'M', 'avenue Alouettes, 9', '4120', 'NEUPRE', 99000
);
INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'935133', 'MOORE', 'Demi', TO_DATE('2000-12-15', 'YYYY-MM-DD'), 'F', 'rue Noisetiers, 9', '4120', 'NEUPRE', 54000
);
INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'192356', 'BOHRINGER', 'Romane', TO_DATE('2000-01-01', 'YYYY-MM-DD'), 'F', 'rue Bolland, 38', '4260', 'BRAIVES', 66000
);
INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'192357', 'LHERMITTE', 'Thierry', TO_DATE('1985-12-12', 'YYYY-MM-DD'), 'M', 'rue Vieux Pre, 6', '4050', 'CHAUDFONTAINE', 56700
);
INSERT INTO employes(
	numsecu, nom, prenom, datenais, sexe, adresse, codepostal, commune, bareme
)VALUES(
	'999999', 'MONROE', 'Marilyn', NULL, NULL, NULL, NULL, NULL, NULL
);

prompt 'insertion dans la table DEPARTEMENTS ...';

INSERT INTO departements VALUES(
	'd00001', 'Applications bureautiques', '935132'
);
INSERT INTO departements VALUES(
	'd00002', 'Applications Main Frame', '123456'
);
INSERT INTO departements VALUES(
	'd00003', 'Applications telecom', '864231'
);
INSERT INTO departements VALUES(
	'd00004', 'Didacticiels', '121212'
);
INSERT INTO departements VALUES(
	'd00005', 'Images Numeriques', '999999'
);

prompt 'insertion complémentaire dans la table EMPLOYES ...';
prompt ' --> chefs de départements';

UPDATE employes
SET
	numdep = 'd00001'
WHERE
	numsecu = '935132';
UPDATE employes
SET
	numdep = 'd00002'
WHERE
	numsecu = '123456';
UPDATE employes
SET
	numdep = 'd00003'
WHERE
	numsecu = '864231';
UPDATE employes
SET
	numdep = 'd00004'
WHERE
	numsecu = '121212';

prompt ' --> les autres';

UPDATE employes
SET
	numchef = '192357'
WHERE
	numsecu IN('935132', '123456', '864231', '121212');
UPDATE employes
SET
	numchef = '935132'
WHERE
	numsecu = '451278';
UPDATE employes
SET
	numdep = 'd00001'
WHERE
	numsecu = '451278';
UPDATE employes
SET
	numchef = '123456'
WHERE
	numsecu = '439549';
UPDATE employes
SET
	numchef = '123456'
WHERE
	numsecu = '654321';
UPDATE employes
SET
	numchef = '654321'
WHERE
	numsecu = '789999';
UPDATE employes
SET
	numdep = 'd00002'
WHERE
	numsecu IN('439549', '654321', '789999');
UPDATE employes
SET
	numchef = '864231'
WHERE
	numsecu = '192356';
UPDATE employes
SET
	numchef = '864231'
WHERE
	numsecu = '334410';
UPDATE employes
SET
	numdep = 'd00003'
WHERE
	numsecu IN('192356', '334410');
UPDATE employes
SET
	numchef = '121212'
WHERE
	numsecu = '123457';
UPDATE employes
SET
	numchef = '123457'
WHERE
	numsecu = '935133';
UPDATE employes
SET
	numdep = 'd00004'
WHERE
	numsecu IN('123457', '935133');

prompt 'insertion dans la table PROJETS ...';

INSERT INTO projets VALUES(
	'p10345', 'Intranet', TO_DATE('2020-01-05', 'YYYY-MM-DD'), 'SERAING', 'd00003'
);
INSERT INTO projets VALUES(
	'p10346', 'Gihep', TO_DATE('2020-09-12', 'YYYY-MM-DD'), 'LIEGE', 'd00004'
);
INSERT INTO projets VALUES(
	'p10347', 'Eole', TO_DATE('2020-02-01', 'YYYY-MM-DD'), 'LONDON', 'd00004'
);
INSERT INTO projets VALUES(
	'p10348', 'E-commerce', TO_DATE('2020-01-15', 'YYYY-MM-DD'), 'SERAING', 'd00001'
);
INSERT INTO projets VALUES(
	'p10349', 'Web', TO_DATE('2020-06-13', 'YYYY-MM-DD'), 'LIEGE', 'd00002'
);
INSERT INTO projets VALUES(
	'p10350', 'Gps - Cartographie', TO_DATE('2020-05-19', 'YYYY-MM-DD'), 'LIEGE', 'd00002'
);
INSERT INTO projets VALUES(
	'p10351', 'Email', TO_DATE('2020-02-13', 'YYYY-MM-DD'), 'LIEGE', 'd00001'
);
INSERT INTO projets VALUES(
	'p10352', 'Jeux - Divertissements', TO_DATE('2020-03-19', 'YYYY-MM-DD'), 'LIEGE', 'd00002'
);



prompt 'insertion dans la table EMP_PRO ...';

INSERT INTO emppro VALUES(
	'451278', 'p10345', '10'
);
INSERT INTO emppro VALUES(
	'451278', 'p10346', '12'
);
INSERT INTO emppro VALUES(
	'451278', 'p10349', '10'
);
INSERT INTO emppro VALUES(
	'451278', 'p10351', '8'
);
INSERT INTO emppro VALUES(
	'935132', 'p10348', '18'
);
INSERT INTO emppro VALUES(
	'935132', 'p10351', '18'
);
INSERT INTO emppro VALUES(
	'123456', 'p10345', '15'
);
INSERT INTO emppro VALUES(
	'123456', 'p10349', '10'
);
INSERT INTO emppro VALUES(
	'123456', 'p10350', '15'
);
INSERT INTO emppro VALUES(
	'654321', 'p10349', '15'
);
INSERT INTO emppro VALUES(
	'654321', 'p10350', '10'
);
INSERT INTO emppro VALUES(
	'789999', 'p10350', '15'
);
INSERT INTO emppro VALUES(
	'789999', 'p10352', '15'
);
INSERT INTO emppro VALUES(
	'439549', 'p10349', '40'
);
INSERT INTO emppro VALUES(
	'864231', 'p10345', '20'
);
INSERT INTO emppro VALUES(
	'864231', 'p10348', '10'
);
INSERT INTO emppro VALUES(
	'864231', 'p10349', '10'
);
INSERT INTO emppro VALUES(
	'334410', 'p10352', '30'
);
INSERT INTO emppro VALUES(
	'192356', 'p10347', '10'
);
INSERT INTO emppro VALUES(
	'192356', 'p10349', '8'
);
INSERT INTO emppro VALUES(
	'123457', 'p10346', '10'
);
INSERT INTO emppro VALUES(
	'123457', 'p10347', '15'
);
INSERT INTO emppro VALUES(
	'123457', 'p10350', '15'
);
INSERT INTO emppro VALUES(
	'121212', 'p10346', '19'
);
INSERT INTO emppro VALUES(
	'121212', 'p10347', '19'
);

commit;