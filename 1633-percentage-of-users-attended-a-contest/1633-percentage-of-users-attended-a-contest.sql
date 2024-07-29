# Write your MySQL query statement below
SELECT 
    r.contest_id,  
    ROUND(COUNT(DISTINCT user_id) * 100.0 / (SELECT COUNT(user_id) FROM Users), 2) AS percentage 
FROM Register AS r
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC




