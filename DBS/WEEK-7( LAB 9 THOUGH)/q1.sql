CREATE TABLE salary_raise(
  Instructor_ID NUMBER(5),
  Raise_date DATE,
  Raise_amt NUMERIC(10,2)
);

DECLARE
  CURSOR raise_cursor IS
    SELECT * FROM Instructor WHERE dept_name = 'Physics' FOR UPDATE;
  raise_amt NUMERIC(8, 2);

BEGIN
    FOR i IN raise_cursor
    LOOP
		raise_amt := i.salary * 1.05;
		UPDATE Instructor
        SET salary = salary * 1.05;
		INSERT INTO salary_raise VALUES (i.ID, CURRENT_DATE, raise_amt);
	END LOOP;
END;
/

SELECT * FROM salary_raise;
