# Write your MySQL query statement below
Select ROUND(Count(case when order_date = customer_pref_delivery_date then 1 end)*100/Count(*),2) as immediate_percentage
FROM Delivery d
JOIN (Select customer_id,min(order_date) as first_order
      from Delivery
      group by customer_id) f
on d.customer_id = f.customer_id 
AND d.order_date = f.first_order;

