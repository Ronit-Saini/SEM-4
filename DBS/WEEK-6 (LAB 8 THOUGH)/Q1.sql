set serveroutput on
declare 
gpa1 numeric(2,1);
begin
    select gpa into gpa1 from studentTable where ROLLNO=1; 
    dbms_output.put_line('GPA : '||gpa1);
end;
/