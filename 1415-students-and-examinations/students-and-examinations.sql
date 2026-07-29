# Write your MySQL query statement below
Select 
    s.student_id,
    s.student_name,
    sub.subject_name,
    COUNT(e.student_id) AS attended_exams
from Students s
CROSS JOIN Subjects sub
Left join Examinations e
ON s.student_id = e.student_id
AND sub.subject_name = e.subject_name
Group by s.student_id,s.student_name,sub.subject_name
Order by  s.student_id,sub.subject_name;