# Write your MySQL query statement below
with data as (select score,dense_rank() over(order by score desc) rankd from Scores order by rankd)
select score,rankd as `rank` from data;