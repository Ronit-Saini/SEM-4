NOT WORKING


set serveroutput on

create table studentTable(
	roll number(2),
	gpa numeric(4,2));
insert into studentTable values(1,5.8);
insert into studentTable values(2,6.5);
insert into studentTable values(3,3.4);
insert into studentTable values(4,7.8);
insert into studentTable values(5,9.5);
insert into studentTable values(6,11);

alter table studentTable 
add  lettergrade varchar2(2);

declare
cursor curs is select * from studentTable for update;
begin
    for stud in curs
    loop
    if stud.gpa between 0 and 4 then
        update studentTable set LetterGrade='F' where current of curs;
    elsif stud.gpa between 4 and 5 then
        update studentTable set LetterGrade='E' where current of curs;
    elsif stud.gpa between 5 and 6 then
        update studentTable set LetterGrade='D' where current of curs;
    elsif stud.gpa between 6 and 7 then
        update studentTable set LetterGrade='C' where current of curs;
    elsif stud.gpa between 7 and 8 then
        update studentTable set LetterGrade='B' where current of curs;
    elsif stud.gpa between 8 and 9 then
        update studentTable set LetterGrade='A' where current of curs;
    else
        update studentTable set LetterGrade='A+' where current of curs;
    end if;
    end loop;
end;
/