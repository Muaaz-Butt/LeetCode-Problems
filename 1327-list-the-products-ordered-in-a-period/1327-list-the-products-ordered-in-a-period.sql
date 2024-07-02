# Write your MySQL query statement below
SELECT p.product_name, SUM(o.unit) AS unit
FROM products AS p
LEFT JOIN Orders o USING(product_id)
WHERE YEAR(o.order_date)='2020' AND MONTH(o.order_date)='02'
GROUP BY p.product_id
HAVING (SUM(unit) >= 100);