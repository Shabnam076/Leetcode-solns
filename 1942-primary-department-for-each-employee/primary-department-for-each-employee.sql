# Write your MySQL query statement below
Select e.employee_id, e.department_id
from Employee e
Join (
    Select employee_id, count(*) as cnt
    from Employee
    group by employee_id
) ee
ON e.employee_id = ee.employee_id
Where ee.cnt = 1 
OR primary_flag = 'Y';