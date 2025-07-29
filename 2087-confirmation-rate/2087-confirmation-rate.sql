# Write your MySQL query statement below
select
    s1.user_id,
    round(avg(if(c1.action = 'confirmed',1,0)),2) as confirmation_rate 
    from Signups s1 
    left join Confirmations c1
    on 
    c1.user_id = s1.user_id
    group by user_id;