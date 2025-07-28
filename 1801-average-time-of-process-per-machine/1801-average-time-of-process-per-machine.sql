# Write your MySQL query statement below
select
    a1.machine_id, 
    ROUND(AVG(b1.timestamp - a1.timestamp), 3) AS processing_time
    from Activity a1, 
    Activity b1
    where 
    a1.machine_id = b1.machine_id
    and 
    a1.process_id = b1.process_id
    and 
    a1.activity_type = 'start'
    and 
    b1.activity_type = 'end'
    group by machine_id