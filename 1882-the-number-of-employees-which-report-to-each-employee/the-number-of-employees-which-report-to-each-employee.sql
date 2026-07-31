# Write your MySQL query statement below
Select e.reports_to as employee_id, m.name,Count(*) as reports_count, Round(AVG(e.age),0) as average_age
from Employees e
JOIN Employees m
ON e.reports_to = m.employee_id
group by e.reports_to,m.name 
order by employee_id;