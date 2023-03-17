set serveroutput on;
DECLARE
	issue_d date;
	return_d date;
	diff number(10);
	fine number(10);
BEGIN
	issue_d:='&i';
	return_d:='&r';
	diff := TO_DATE(return_d,'dd/mm/yy')-TO_DATE(issue_d,'dd/mm/yy'); 
		DBMS_OUTPUT.PUT_LINE('No.of days: ' ||diff);
	IF diff between 0 and 7 then
		fine := 0;
		DBMS_OUTPUT.PUT_LINE('Fine is: NIL');
	ELSIF diff between 8 and 15 then
		fine:=diff*1;
		DBMS_OUTPUT.PUT_LINE('Fine is: ' ||fine);
	ELSIF diff between 16 and 30 then
		fine:=diff*2;
		DBMS_OUTPUT.PUT_LINE('Fine is: ' ||fine);
	ELSE
		fine:=diff*5;
		DBMS_OUTPUT.PUT_LINE('Fine is: ' ||fine);
	END IF;					
END;
/