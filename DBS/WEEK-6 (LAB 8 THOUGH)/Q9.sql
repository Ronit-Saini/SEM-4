set serveroutput on
declare
score numeric(4,1);
grade varchar(2);
i integer:=1;
incorrect_range exception;
begin
while i<7 loop
    select gpa into score from studentTable where rollno=i;
    if score<0 or score>10 then
        raise incorrect_range;
    elsif score<=4 then
        grade:='F';
    elsif score<=5 then
        grade:='E';
    elsif score<=6 then
        grade:='D';
    elsif score<=7 then
        grade:='C';
    elsif score<=8 then
        grade:='B';
    elsif score<=9 then
        grade:='A';
    else
        grade:='A+';
    end if;
    update studentTable set lettergrade=grade where rollno=i;
    i:=i+1;
end loop;
exception
    when incorrect_range then
    dbms_output.put_line('OUT OF RANGE');
end;
/