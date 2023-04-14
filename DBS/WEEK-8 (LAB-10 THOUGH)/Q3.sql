set serveroutput on
DECLARE
    CURSOR C IS SELECT DISTINCT dept_name FROM course;
BEGIN
    FOR I IN C
    LOOP
        course_popular(I.dept_name);
    END LOOP;
END;
/

/*
Most popular course of Elec. Eng. is EE-181
Most popular course of Physics is PHY-101
Most popular course of Comp. Sci. is CS-101
Most popular course of Finance is FIN-201
Most popular course of Biology is BIO-101
Most popular course of History is HIS-351
Most popular course of Music is MU-199
*/