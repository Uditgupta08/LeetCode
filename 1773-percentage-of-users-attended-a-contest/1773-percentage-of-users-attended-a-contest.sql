# Write your MySQL query statement below
select
    r1.contest_id,
    round(count(distinct r1.user_id)*100/(select count(*) from users),2) as percentage
    from Register r1
    left join users u1 on
    r1.user_id = u1.user_id
    group by r1.contest_id
    order by percentage desc,r1.contest_id;