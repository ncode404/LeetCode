# Write your MySQL query statement below
SELECT e2.product_name, e1.year, e1.price
FROM Sales as e1
JOIN Product as e2
ON e1.product_id=e2.product_id