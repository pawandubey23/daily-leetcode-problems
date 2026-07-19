# Write your MySQL query statement below
select s.machine_id,
ROUND(AVG(e.timestamp - s.timestamp),3)as processing_time
FROM activity s
JOIN activity e
on s.machine_id = e.machine_id
AND s.process_id = e.process_id
where s.activity_type = "start"
AND e.activity_type = "end"
group by machine_id;


