# Write your MySQL query statement below
Select e.product_id, e.year as first_year, e.quantity,price
From Sales e
JOIN (
    Select product_id, Min(year) as fy from Sales group by product_id
) s
ON e.product_id = s.product_id
AND e.year = s.fy;