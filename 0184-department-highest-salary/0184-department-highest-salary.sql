
select t.Department,t.Employee,t.Salary from
(
    select d.name as 'Department',e.name as 'Employee',e.salary as 'Salary',rank() over(partition by d.name order by e.salary desc) as rnk
    from Employee e inner join Department d on 
    e.departmentId = d.id
) t  
where rnk = 1;