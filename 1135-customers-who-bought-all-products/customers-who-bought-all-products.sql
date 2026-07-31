# Write your MySQL query statement below
Select  customer_id
from Customer
group by customer_id
having count(Distinct product_key) = (
    select count(*) from product
);
