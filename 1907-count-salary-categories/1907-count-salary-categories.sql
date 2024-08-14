# Write your MySQL query statement below
SELECT 
    'Low Salary' AS category,
    SUM(income < 20000) AS accounts_count
FROM 
    Accounts
UNION
    SELECT 
        'Average Salary' AS category,
        SUM(income BETWEEN 20000 AND 50000 ) AS accounts_count
    FROM 
        Accounts

UNION

    SELECT 
        'High Salary' AS category,
        SUM(income > 50000) AS accounts_count
    FROM 
        Accounts;
