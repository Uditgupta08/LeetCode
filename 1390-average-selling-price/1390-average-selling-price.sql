# Write your MySQL query statement below
select
    distinct p1.product_id,
    ifnull(round(sum(p1.price*u1.units)/sum(u1.units),2),0) as average_price
    from Prices p1
    left join UnitsSold u1 on
    p1.product_id = u1.product_id 
    and u1.purchase_date between p1.start_date and p1.end_date
    group by p1.product_id;