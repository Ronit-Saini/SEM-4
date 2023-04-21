COMMIT; 
--To have a save to rollback to
SELECT * FROM takes WHERE ID = 12345 AND sec_id = 2; 
--View old
UPDATE takes SET sec_id = 1 WHERE ID = 12345 AND sec_id = 2; 
--Update
DELETE FROM takes WHERE ID = 12345 AND course_id = 'CS-190' 
--Delete
SELECT * FROM takes WHERE ID = 12345 AND sec_id = 2; 
--View after updating
SELECT * FROM log_change_Takes; 
--See output from trigger
ROLLBACK; 
--Rollback to original data
