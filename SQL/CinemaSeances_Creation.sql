/*
drop table CS_FILMS cascade constraints;                       
drop table CS_PAYS cascade constraints;                        
drop table CS_INTERVENANTS cascade constraints;                
drop table CS_FONCTIONS cascade constraints;                   
drop table CS_TRAVAILLER cascade constraints;                  
drop table CS_PRODUIRE cascade constraints;                    
drop table CS_CATEGORIES cascade constraints;                  
drop table CS_FC cascade constraints;                          
drop table CS_SEANCES cascade constraints;                     
drop table CS_SALLES cascade constraints;                      
drop table CS_ADHERENTS cascade constraints;                   
drop table CS_RESERVATIONS cascade constraints;
*/

CREATE TABLE CS_FILMS
(
	numfilm number(4), 
	titre varchar2(40) constraint films_titre not null enable,
	annee number(4) constraint films_annee not null enable,
	duree number(3) constraint films_duree not null enable,
	constraint pk_films primary key(numfilm)
);

CREATE TABLE CS_PAYS
(
	codepays char(2), 
	designation varchar2(20) constraint pays_designation not null enable,
	constraint pk_pays primary key(codepays)
);

CREATE TABLE CS_INTERVENANTS
(
	numintervenant number(4), 
	nom varchar2(30) constraint intervenants_nom not null enable,
	prenom varchar2(30), 
	nationalite char(2),
	sexe char(1),
	constraint intervenants_sexe CHECK (upper(sexe) IN ('F','M')) enable,
	constraint pk_intervenants primary key (numintervenant),
	constraint fk_intervenantspays foreign key (nationalite) references CS_pays (codepays) enable
);

CREATE TABLE CS_FONCTIONS
(
	numfonction number(4), 
	fonction varchar2(30) constraint fonctions_nom not null enable,
	constraint pk_fonctions primary key(numfonction)
);

CREATE TABLE CS_TRAVAILLER
(
  numfilm number(4), 
	numfonction number(4),
  numintervenant number(4),  
	constraint pk_travailler primary key(numfilm,numfonction,numintervenant),
  constraint fk_travaillerfilms foreign key(numfilm) references CS_films (numfilm) enable,
  constraint fk_travaillerfonctions foreign key(numfonction) references CS_FONCTIONS (numfonction) enable,
  constraint fk_travaillerintervenants foreign key(numintervenant) references CS_intervenants (numintervenant) enable
);

CREATE TABLE CS_PRODUIRE
(
  numfilm number(4), 
  codepays char(2), 
  constraint pk_produire primary key(numfilm, codepays),
  constraint fk_produirefilms foreign key(numfilm) references CS_films (numfilm) enable,
  constraint fk_produirepays foreign key(codepays) references CS_pays (codepays) enable
);

CREATE TABLE CS_CATEGORIES 
(
  numcat number(2), 
  libelle varchar2(20) constraint categories_libelle not null enable, 
  constraint pk_cat primary key(numcat)
);

CREATE TABLE CS_FC
(
  numfilm number(4), 
  numcat number(2),  
  constraint pk_fc primary key(numfilm, numcat),
  constraint fk_fcfilms foreign key(numfilm) references CS_films (numfilm) enable,
  constraint fk_fccategories foreign key(numcat) references CS_categories (numcat) enable
);

CREATE TABLE CS_SALLES
(
  numsalle number(3),   
  nomsalle varchar2(30) constraint salles_nomsalle not null enable,
  adressesalle varchar2(50), 
  villesalle varchar2(30) constraint salles_villesalle not null enable, 
  telephone char(14),
	constraint salles_telephone CHECK (telephone LIKE ('__ __ __ __ __')) enable,
  constraint pk_salles primary key(numsalle)
);

CREATE TABLE CS_SEANCES
( 
  numfilm number(4), 
  numsalle number(3), 
  jour char(8), 
  heuredeb char(5),
  constraint seances_heuredeb CHECK (heuredeb LIKE ('__h__')) enable,
  constraint pk_seances primary key(numfilm,numsalle,jour,heuredeb),
	constraint fk_seancesfilms foreign key(numfilm) references CS_films (numfilm) enable,
	constraint fk_seancessalles foreign key(numsalle) references CS_salles (numsalle) enable
);

CREATE TABLE CS_ADHERENTS
(
  numadhe number(5), 
  nomadhe varchar2(30) constraint adherents_nomadhe not null enable,
  prenomadhe varchar2(30), 
  adresse varchar2(50), 
  code_postal char(5),
  ville varchar2(30) constraint adherents_ville not null enable,
  ordrecotisation char(1),
	constraint adherents_codepostal CHECK (code_postal LIKE ('_____')) enable,
  constraint pk_adhe primary key(numadhe)
);

CREATE TABLE CS_RESERVATIONS
(
  numfilm number(4),
  numsalle number(3),
  jour char(8), 
  heuredeb char(5),
  numadhe number(5),
  nbplaces number(3) constraint reservations_nbplaces not null enable, 
  paye char(1),
  modepaiement char(2),
  constraint reservations_paye CHECK (upper(paye) IN ('O','N')) enable,
  constraint reservations_modepaiement CHECK (upper(modepaiement) IN ('ES','CH','CB')) enable,
  constraint reservations_heuredeb CHECK (heuredeb LIKE ('__h__')) enable,
  constraint pk_reserv primary key(numfilm,numsalle,jour,heuredeb,numadhe),
  constraint fk_reservationsseances foreign key(numfilm,numsalle,jour,heuredeb) references CS_seances (numfilm,numsalle,jour,heuredeb) enable,
  constraint fk_reservationsadherents foreign key(numadhe) references CS_adherents (numadhe) enable
);