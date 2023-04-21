CREATE TABLE Old_Data_Instructor (
    ID VARCHAR(5),
    name VARCHAR(20),
    dept_name VARCHAR(20),
    salary NUMERIC(8,2),
    PRIMARY KEY (ID));

CREATE OR REPLACE TRIGGER logSalary
BEFORE UPDATE OF salary ON instructor
FOR EACH ROW
BEGIN
INSERT INTO Old_Data_Instructor VALUES (:OLD.ID, :OLD.name, :OLD.dept_name, :OLD.salary);
END;
/