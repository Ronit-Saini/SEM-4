set serveroutput on
declare
in_name varchar(20):='Srinivasan';
multiple_instructor exception;
no_instructor exception;
counts integer;
details instructor%rowtype;
begin
select count(*) into counts from instructor where name=in_name;
if counts<1 then raise no_instructor;
elsif counts>1 then raise multiple_instructor;
else
select * into details from instructor where name=in_name;
dbms_output.put_line(details.salary||details.name);
end if;
exception 
    when no_instructor then
    dbms_output.put_line('NO instructor');
    when multiple_instructor then
    dbms_output.put_line('multiple instructor');
end;
/
