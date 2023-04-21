COMMIT; 
--To have a save to rollback to
SELECT * FROM Advisor; 
SELECT * FROM Advisor_Student; 
--View old
DELETE FROM Advisor_Student WHERE S_ID = 98765 AND I_ID = 98345;
--Delete
SELECT * FROM Advisor; 
--View new
ROLLBACK; 
--Rollback to original data