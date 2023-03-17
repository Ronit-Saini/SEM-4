set serveroutput on
declare
score numeric(2,1);
grade varchar(2);
rollll number(1);
begin
    rollll :='&roll';
    select gpa into score from studentTable where rollno=rollll; 
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
    dbms_output.new_line;
    dbms_output.put_line(' Grade is : '||grade);
end;
/