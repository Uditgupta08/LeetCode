# Write your MySQL query statement below
select 
    v1.customer_id,
    count(v1.visit_id) as count_no_trans
    from visits v1 
    left join Transactions t1 on 
    v1.visit_id = t1.visit_id
    WHERE t1.transaction_id IS NULL
    GROUP BY v1.customer_id;