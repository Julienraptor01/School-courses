alter session set "_ORACLE_SCRIPT"=true;  

--créer un role avec les droits requis pour faire les labos
create role sgbd2s_role not identified;
grant alter session to sgbd2s_role;
grant create session to sgbd2s_role;
grant create table to sgbd2s_role;
grant create procedure to sgbd2s_role;
grant create sequence to sgbd2s_role;
grant create trigger to sgbd2s_role;
grant create type to sgbd2s_role;

--créer un user et lui attribuer le role sgbd2s_role + les droits de lock nécessaires pour les labos du Q2
create user testUser identified by oracle default tablespace users account unlock;
alter user testUser quota unlimited on users;
grant sgbd2s_role to testUser;