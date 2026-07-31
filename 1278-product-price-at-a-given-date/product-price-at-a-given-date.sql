# Write your MySQL query statement below
Select p.product_id, p.new_price as price              #case when date before 16 is found
from Products p
Join (
    Select product_id, max(change_date) as latest
    from Products 
    where change_date <= "2019-08-16"
    group by product_id
) pr
On p.product_id = pr.product_id
AND p.change_date = pr.latest

UNION
SELECT DISTINCT product_id, 10 AS price                #case when date before 16 doesnt exist 
FROM Products
WHERE product_id NOT IN (
    SELECT product_id
    FROM Products
    WHERE change_date <= "2019-08-16"
)
Order by product_id;