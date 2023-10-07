# Write your MySQL query statement below
select distinct l1.num as ConsecutiveNums from Logs l1 where (select count(l2.id) from Logs l2 where l2.num =l1.num and( l2.id=l1.id+1 or l2.id=l1.id-1)) > 1;