# Write your MySQL query statement below
Select c.class from 
Courses c
JOIN (
     Select class, Count(student) as cnt
     from Courses group by class having cnt >= 5
    ) s
ON c.class = s.class
group by class;
