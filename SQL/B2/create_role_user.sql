--useless on Oracle Cloud
--ALTER SESSION SET "_ORACLE_SCRIPT" = TRUE;

--créer un role avec les droits requis pour faire les labos
CREATE ROLE sgbd2s_role NOT IDENTIFIED;
GRANT ALTER SESSION TO sgbd2s_role;
GRANT CREATE SESSION TO sgbd2s_role;
GRANT CREATE TABLE TO sgbd2s_role;
GRANT CREATE PROCEDURE TO sgbd2s_role;
GRANT CREATE SEQUENCE TO sgbd2s_role;
GRANT CREATE TRIGGER TO sgbd2s_role;
GRANT CREATE TYPE TO sgbd2s_role;

--créer un user et lui attribuer le role sgbd2s_role + les droits de lock nécessaires pour les labos du Q2
CREATE USER testuser IDENTIFIED BY oracle DEFAULT TABLESPACE users ACCOUNT UNLOCK;
ALTER USER testuser QUOTA UNLIMITED ON users;
GRANT sgbd2s_role TO testuser;