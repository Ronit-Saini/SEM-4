set serveroutput on
declare
score numeric(2,1);
grade varchar(2);
i integer:=1;
begin
<<start_here>>
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
    dbms_output.put_line('Grade is:'||grade);
    i:=i+1;
    if i<6 then goto start_here;
    end if;
end;
/


@ "C:\Users\Student\Desktop\210905322-DBS\WEEK-6 (LAB 8 THOUGH)\Q7.sql"
Grade is:D
Grade is:C
Grade is:F
Grade is:B
Grade is:A+



