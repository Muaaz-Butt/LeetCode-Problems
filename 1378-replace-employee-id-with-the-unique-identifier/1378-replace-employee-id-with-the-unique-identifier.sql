# Write your MySQL query statement below
SELECT Employees.name, EmployeeUNI.unique_id
FROM Employees 
LEFT JOIN EmployeeUNI ON EmployeeUNI.id = Employees.Id;
