set serveroutput on
alter table studentTable 
add lettergrade varchar2(2);
declare
score numeric(2,1);
grade varchar(2);
i integer:=1;
begin
while i<=5 loop
    select gpa into score from studentTable where rollno=i;
    if score<=4 then
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
end;
/



 @ "C:\Users\Student\Desktop\210905322-DBS\WEEK-6 (LAB 8 THOUGH)\Q5.sql"

Table altered.


PL/SQL procedure successfully completed.

select * from studenttable
  2  ;

    ROLLNO        GPA LE
---------- ---------- --
         1        5.8 D
         2        6.5 C
         3        3.4 F
         4        7.8 B
         5        9.5 A+
