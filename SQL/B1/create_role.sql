alter session set "_ORACLE_SCRIPT"=true;

create role agd2_role not identified;

grant alter session to agd2_role;
grant create session to agd2_role;
grant create table to agd2_role;
grant create procedure to agd2_role;
grant create sequence to agd2_role;
grant create trigger to agd2_role;
grant create type to agd2_role;