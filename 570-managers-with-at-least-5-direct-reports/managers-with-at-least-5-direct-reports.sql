# Write your MySQL query statement below
Select e.name
from Employee e
JOIN (
    Select managerId,count(id) as cnt
    from Employee
    WHERE managerId IS NOT NULL
    group by managerId
    having count(id) >= 5
    ) a
ON e.id = a.managerId;