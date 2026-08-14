# Write your MySQL query statement below


select distinct num as 'ConsecutiveNums' from (
    select num,
    lead(num,1) over(order by id) as nxt,
    lag(num,1) over (order by id) as prev
    from logs
) t
where nxt = num and prev = num;