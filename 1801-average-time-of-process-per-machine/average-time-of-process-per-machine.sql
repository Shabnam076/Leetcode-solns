Select a.machine_id, 
       round(avg(b.timestamp-a.timestamp),3) as processing_time
from Activity a
Join Activity b
ON a.machine_id = b.machine_id
AND a.process_id = b.process_id
where a.activity_type = "start"
And b.activity_type = "end"
group by a.machine_id;
