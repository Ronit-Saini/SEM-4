COMMIT; 
--To have a save to rollback to
SELECT * FROM instructor WHERE ID = 12121; 
--View old
UPDATE instructor SET salary = salary * 1.5 WHERE ID = 12121; 
--Update
SELECT * FROM instructor WHERE ID = 12121; 
--View after updating
SELECT * FROM Old_Data_Instructor; 
--See output from trigger
ROLLBACK; 
--Rollback to original data