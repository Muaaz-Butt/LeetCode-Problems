# Write your MySQL query statement below
SELECT 
    ROUND(SUM(CASE WHEN DATEDIFF(customer_pref_delivery_date, order_date) = 0  THEN 1 ELSE 0 END) / COUNT(DISTINCT customer_id) * 100, 2) AS immediate_percentage
FROM delivery
WHERE (customer_id, order_date) IN (
        SELECT customer_id, MIN(order_date) AS first_order_date
        FROM delivery
        GROUP BY customer_id
);

