# Write your MySQL query statement below
Select qu.person_name 
from 
(Select 
    person_name, 
    sum(weight) over(order by turn) as running_sum
    from Queue q) qu
where qu.running_sum <= 1000 
order by qu.running_sum desc limit 1;



