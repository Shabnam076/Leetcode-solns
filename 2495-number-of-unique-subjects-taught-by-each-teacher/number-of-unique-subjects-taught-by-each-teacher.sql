# Write your MySQL query statement below
Select teacher_id, Count(DISTINCT subject_id) as cnt
from Teacher
group by teacher_id;