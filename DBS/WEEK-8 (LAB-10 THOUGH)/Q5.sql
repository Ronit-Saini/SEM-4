set serveroutput on

BEGIN
    DBMS_OUTPUT.PUT_LINE(square('&number'));
END;
/



/*
Enter value for number: 6
old   2:     DBMS_OUTPUT.PUT_LINE(square('&number'));
new   2:     DBMS_OUTPUT.PUT_LINE(square('6'));
36
*/