set serveroutput on
declare
temp studenttable.gpa%type:=0;
max_score studenttable.gpa%type:=0;
max_roll studenttable.rollno%type;
begin
for i in 1..5 loop
select gpa into temp from studenttable where rollno=i;
if temp>max_score then
    max_score:=temp;
    max_roll:=i;
end if;
end loop;
dbms_output.put_line('Student Roll Number='||max_roll||'and GPA='||max_score);
end;
/


@ "C:\Users\Student\Desktop\210905322-DBS\WEEK-6 (LAB 8 THOUGH)\Q6.sql"
Student Roll Number=5and GPA=9.5

PL/SQL procedure successfully completed.