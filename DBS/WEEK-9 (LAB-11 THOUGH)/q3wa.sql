COMMIT; 
--To have a save to rollback to
SELECT * FROM instructor; 
--View old
INSERT INTO instructor VALUES('12345','NewInstructor','Comp. Sci.',50000);
--Error: Not enough department budget
INSERT INTO instructor VALUES('12345','NewInstructor12','Music',20000);
--Error: Name must contain only alphabets
INSERT INTO instructor VALUES('12345','NewInstructor','Comp. Sci.',0);
--Insert
SELECT * FROM instructor; 
--View after inserting
ROLLBACK; 
--Rollback to original data
