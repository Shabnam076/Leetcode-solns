# Write your MySQL query statement below
Select  e.name,u.unique_id
From Employees e
LEFT Join EmployeeUNI u
ON e.id = u.id;