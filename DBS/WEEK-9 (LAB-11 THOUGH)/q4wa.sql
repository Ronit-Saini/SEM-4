COMMIT; 
--To have a save to rollback to
SELECT * FROM Client_master; 
--View old
UPDATE Client_master SET bal_due = 10000 WHERE client_no = 1;
--Update
DELETE FROM Client_master WHERE client_no = 2;
--Delete
SELECT * FROM auditClient; 
--View output of trigger
ROLLBACK; 
--Rollback to original data