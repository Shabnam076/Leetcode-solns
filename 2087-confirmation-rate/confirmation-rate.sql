# Write your MySQL query statement below
Select s.user_id, ROUND(
            IFNULL(
                count(case when c.action = "confirmed" then 1  end) / Count(c.action)
                ,0)
                ,2) as confirmation_rate
from Signups s
LEFT JOIN Confirmations c
ON s.user_id = c.user_id
group by s.user_id;