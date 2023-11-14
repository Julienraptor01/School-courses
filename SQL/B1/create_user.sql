alter session set "_ORACLE_SCRIPT"=true;

create user testUser identified by testPassword default tablespace users account unlock;
alter user testUser quota unlimited on users;
grant agd2_role to testUser;