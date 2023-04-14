set serveroutput on

DECLARE
    CURSOR C IS SELECT DISTINCT dept_name FROM instructor;
BEGIN
    FOR I IN C
    LOOP
        disp6(I.dept_name);
    END LOOP;
END;
/


/*
Highest paid instructor of Elec. Eng. is Kim
Highest paid instructor of Physics is Gold
Highest paid instructor of Comp. Sci. is Brandt
Highest paid instructor of Finance is Singh
Highest paid instructor of Biology is Crick
Highest paid instructor of Music is Mozart
Highest paid instructor of History is Califieri
*/