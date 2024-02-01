DROP TABLE pays CASCADE CONSTRAINTS;

DROP TABLE adresses CASCADE CONSTRAINTS;

DROP TABLE mutuelles CASCADE CONSTRAINTS;

DROP TABLE specialites CASCADE CONSTRAINTS;

DROP TABLE medecins CASCADE CONSTRAINTS;

DROP TABLE patients CASCADE CONSTRAINTS;

DROP TABLE patientsmedecins CASCADE CONSTRAINTS;

DROP TABLE hopitaux CASCADE CONSTRAINTS;

DROP TABLE services CASCADE CONSTRAINTS;

DROP TABLE hopitauxservices CASCADE CONSTRAINTS;

DROP TABLE medecinsservices CASCADE CONSTRAINTS;

DROP TABLE groupes CASCADE CONSTRAINTS;

DROP TABLE fabricants CASCADE CONSTRAINTS;

DROP TABLE medicaments CASCADE CONSTRAINTS;

DROP TABLE substances CASCADE CONSTRAINTS;

DROP TABLE allergies CASCADE CONSTRAINTS;

DROP TABLE composition CASCADE CONSTRAINTS;

--1
CREATE TABLE pays(
    codepays CHAR(2)CONSTRAINT cppays PRIMARY KEY,
    libelle VARCHAR2(50)
);

--2
CREATE TABLE adresses(
    codeadresse NUMBER(4)CONSTRAINT cpadresses PRIMARY KEY,
    adresse VARCHAR2(100),
    localite VARCHAR2(50),
    codepostal CHAR(5)
);

--3
CREATE TABLE mutuelles(
    codemutuelle CHAR(3)CONSTRAINT cpadresse PRIMARY KEY,
    libelle VARCHAR2(100),
    codeadresse NUMBER(4)CONSTRAINT refmutuelleadresses REFERENCES adresses(codeadresse),
    email VARCHAR2(100)
);

--4
CREATE TABLE specialites(
    specialite CHAR(3)CONSTRAINT cpspecialites PRIMARY KEY,
    libelle VARCHAR2(80)
);

--5
CREATE TABLE medecins(
    nrmedecin CHAR(11)CONSTRAINT cpmedecins PRIMARY KEY,
    nom VARCHAR2(20)CONSTRAINT medecinsnomnn CHECK(nom IS NOT NULL)CONSTRAINT medecinsnomlg CHECK(length(nom) >= 2),
    prenom VARCHAR2(50),
    sexe CHAR(1)CONSTRAINT medecinssexenn CHECK(sexe IS NOT NULL)CONSTRAINT medecinssexemf CHECK(sexe IN('M', 'F')),
    etatcivil CHAR(1)CONSTRAINT medecinsetatcivilnn CHECK(etatcivil IS NOT NULL)CONSTRAINT medecinsetatcivilcmdv CHECK(etatcivil IN('C', 'M', 'D', 'V')),
    titre VARCHAR2(20),
    datediplome DATE,
    cptbancaire VARCHAR2(12),
    gsm VARCHAR2(15),
    codeadresse NUMBER(4)CONSTRAINT refmedecinsadresses REFERENCES adresses(codeadresse),
    specialite CHAR(3)CONSTRAINT refmedecinsspecialites REFERENCES specialites(specialite),
    datenaissance DATE
);

--6
CREATE TABLE patients(
    nrsis CHAR(11)CONSTRAINT cppatients PRIMARY KEY,
    nom VARCHAR2(20),
    prenom VARCHAR2(50),
    sexe CHAR(1),
    etatcivil CHAR(1),
    nationalite CHAR(2)CONSTRAINT refpatientspays REFERENCES pays(codepays),
    datenaissance DATE,
    cptbancaire VARCHAR2(12),
    grpsanguin CHAR(2),
    taille NUMBER(3),
    poids NUMBER(3),
    codemutuelle CHAR(3)CONSTRAINT refpatientsmutuelles REFERENCES mutuelles(codemutuelle),
    codeadresse NUMBER(4)CONSTRAINT refpatientsadresses REFERENCES adresses(codeadresse)
);

--7
CREATE TABLE patientsmedecins(
    nrsis CHAR(11)CONSTRAINT refpatientsmedecinspatients REFERENCES patients(nrsis),
    nrmedecin CHAR(11)CONSTRAINT refpatientsmedecinsmedecins REFERENCES medecins(nrmedecin),
    CONSTRAINT cppatientsmedecins PRIMARY KEY(nrsis, nrmedecin)
);

--8
CREATE TABLE hopitaux(
    nrhopital CHAR(7)CONSTRAINT cphopitaux PRIMARY KEY,
    nom VARCHAR2(50)CONSTRAINT hopitauxnomnn CHECK(nom IS NOT NULL)CONSTRAINT hopitauxnomlg CHECK(length(nom) > 10),
    telephone VARCHAR2(15),
    email VARCHAR2(50)CONSTRAINT hopitauxemailck CHECK(email LIKE '_%@_%'),
    codeadresse NUMBER(4)CONSTRAINT refhopitauxadresses REFERENCES adresses(codeadresse),
    capacite NUMBER(5)CONSTRAINT hopitauxcapaciteck CHECK(coalesce(capacite, 15) > 10),
    type CHAR(1)CONSTRAINT hopitauxtypecu CHECK(type IN('C', 'U')),
    cptbancaire VARCHAR2(12)
);

--9
CREATE TABLE services(
    nrservice CHAR(4)CONSTRAINT cpservices PRIMARY KEY,
    libelle VARCHAR2(50)
);

--10
CREATE TABLE hopitauxservices(
    nrhopital CHAR(7)CONSTRAINT refhopitauxserviceshopitaux REFERENCES hopitaux(nrhopital),
    nrservice CHAR(4)CONSTRAINT refhopitauxservicesservices REFERENCES services(nrservice),
    chefservice CHAR(11)CONSTRAINT refhopitauxservicesmedecins REFERENCES medecins(nrmedecin),
    nbremedecins NUMBER(4),
    CONSTRAINT cphopitauxservices PRIMARY KEY(nrhopital, nrservice)
);

--11
CREATE TABLE medecinsservices(
    nrhopital CHAR(7),
    nrservice CHAR(4),
    CONSTRAINT refmedserviceshopservices FOREIGN KEY(nrhopital, nrservice)REFERENCES hopitauxservices(nrhopital, nrservice),
    nrmedecin CHAR(11)CONSTRAINT refmedservicesmedecins REFERENCES medecins(nrmedecin),
    CONSTRAINT cpmedecinsservices PRIMARY KEY(nrhopital, nrservice, nrmedecin)
);

--12
CREATE TABLE groupes(
    nrgroupe NUMBER(2)CONSTRAINT cpgroupes PRIMARY KEY,
    libelle VARCHAR2(50)
);

--13
CREATE TABLE fabricants(
    nrfabricant NUMBER(2)CONSTRAINT cpfabricants PRIMARY KEY,
    nom VARCHAR2(50)CONSTRAINT fabricantsnomnn CHECK(nom IS NOT NULL)CONSTRAINT fabricantsnomlg CHECK(length(nom) > 2),
    adresse VARCHAR2(40)CONSTRAINT fabricantsadressenorlg CHECK(adresse IS NULL OR length(adresse) > 10),
    cpostal VARCHAR2(10),
    CONSTRAINT fabricantscpostalnorlg CHECK(cpostal IS NULL OR length(cpostal) = 4),
    localite VARCHAR2(30),
    cpays CHAR(2)CONSTRAINT reffabricants_pays REFERENCES pays(codepays)
);

--14
CREATE TABLE medicaments(
    nrmedicament VARCHAR2(12)CONSTRAINT cpmedicaments PRIMARY KEY,
    denomination VARCHAR2(100)CONSTRAINT medicamentsdenominationnn CHECK(denomination IS NOT NULL)CONSTRAINT medicamentsdenominationlg CHECK(length(denomination) > 5),
    type VARCHAR2(50)CONSTRAINT medicamentstypenn CHECK(type IS NOT NULL),
    conditionnement VARCHAR2(50),
    indications VARCHAR2(50)CONSTRAINT medicamentsindications CHECK(indications IS NULL OR length(indications) > 5),
    nrgroupe NUMBER(2)CONSTRAINT refmedic_groupes REFERENCES groupes(nrgroupe),
    nrfabricant NUMBER(2)CONSTRAINT refmedic_fabricants REFERENCES fabricants(nrfabricant)
);

--15
CREATE TABLE substances(
    nrsubstance CHAR(4)CONSTRAINT cpsubstances PRIMARY KEY,
    nom VARCHAR2(50)
);

--16
CREATE TABLE allergies(
    nrsis CHAR(11)CONSTRAINT refallergique_patients REFERENCES patients(nrsis),
    nrsubstance CHAR(4)CONSTRAINT refallergies_substances REFERENCES substances(nrsubstance),
    CONSTRAINT cpallergique PRIMARY KEY(nrsis, nrsubstance)
);

--17
CREATE TABLE composition(
    nrmedicament VARCHAR2(12)CONSTRAINT refcomposition_medicaments REFERENCES medicaments(nrmedicament),
    nrsubstance CHAR(4)CONSTRAINT refcomposition_substances REFERENCES substances(nrsubstance),
    quantite NUMBER(4),
    unite CHAR(3),
    CONSTRAINT cpcomposition PRIMARY KEY(nrmedicament, nrsubstance)
);