# Write your MySQL query statement below
Select w.id 
from Weather w
Join (
    select recordDate as nextdate, temperature as nexttemp
    from weather
) n
ON w.recordDate = DATE_ADD(n.nextdate,INTERVAL 1 DAY)       #w wil be the next day not n acc to statement
AND w.temperature > n.nexttemp;