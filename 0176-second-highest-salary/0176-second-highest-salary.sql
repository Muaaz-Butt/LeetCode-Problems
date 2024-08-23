# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT MAX(salary) AS secondHighestSalary
FROM Employee 
WHERE salary < (SELECT MAX(salary)
                    FROM Employee);