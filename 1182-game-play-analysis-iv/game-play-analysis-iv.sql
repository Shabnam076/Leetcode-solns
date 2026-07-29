# Write your MySQL query statement below
Select Round(Count(DISTINCT a.player_id)/
    (SELECT COUNT(DISTINCT player_id) FROM Activity),2)
    as fraction
from Activity a
Join (
    Select player_id,min(event_date) as first_login
    from Activity
    group by player_id
    ) b

ON a.player_id = b.player_id
AND a.event_date = DATE_ADD(b.first_login, INTERVAL 1 DAY);