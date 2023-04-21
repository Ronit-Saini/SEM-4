CREATE TABLE log_change_Takes(
    Time_Of_Change DATE,
    ID VARCHAR(5),
    course_id VARCHAR(8),
    sec_id VARCHAR(8),
    semester VARCHAR(6),
    year NUMERIC(4,0),
    grade VARCHAR(2),
    PRIMARY KEY (ID, course_id, sec_id, semester, year));

SET SERVEROUTPUT ON

CREATE OR REPLACE TRIGGER logTakes
BEFORE INSERT OR UPDATE OF ID, course_id, sec_id, semester, year, grade OR DELETE ON takes
FOR EACH ROW
BEGIN
CASE
WHEN INSERTING THEN
    INSERT INTO log_change_Takes 
    VALUES(SYSDATE,:NEW.ID, :NEW.course_id, :NEW.sec_id, :NEW.semester, :NEW.year, :NEW.grade);
WHEN UPDATING OR DELETING THEN
    INSERT INTO log_change_Takes 
    VALUES(SYSDATE,:OLD.ID, :OLD.course_id, :OLD.sec_id, :OLD.semester, :OLD.year, :OLD.grade);
END CASE;
END;
/
