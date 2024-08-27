# Write your MySQL query statement below
SELECT 
    p.product_id,
    COALESCE(
        (
            SELECT new_price
            FROM Products AS p2
            WHERE p.product_id = p2.product_id
            AND p2.change_date <= '2019-08-16'
            ORDER BY p2.change_date DESC
            LIMIT 1
        ), 10
    ) AS price
FROM (SELECT DISTINCT product_id FROM products) AS p
