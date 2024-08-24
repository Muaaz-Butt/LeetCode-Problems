# Write your MySQL query statement below
SELECT 
    DISTINCT l1.num AS ConsecutiveNums
FROM 
    Logs AS l1
JOIN 
    Logs AS l2 
ON 
    l1.id = l2.id - 1
JOIN
    Logs AS l3
ON 
    l1.id = l3.id - 2
WHERE 
    l1.num = l2.num AND l1.num = l3.num