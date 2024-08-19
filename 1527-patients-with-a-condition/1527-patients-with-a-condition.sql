# Write your MySQL query statement below
SELECT
    *
FROM 
    Patients
WHERE 
   conditions REGEXP '\\bDIAB1'
