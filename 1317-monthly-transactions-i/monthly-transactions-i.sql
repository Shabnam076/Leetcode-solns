# Write your MySQL query statement below
#Learn - how to get month and year from a date, sum of elements when state = approved 
select  DATE_FORMAT(trans_date, '%Y-%m') as month,
      country,Count(state) as trans_count,
       Count(case when state = "approved" then 1 END) as approved_count,
       sum(amount) as trans_total_amount,
       IFNULL(sum(case when state = "approved" then amount END),0) as approved_total_amount
       from Transactions
       group by month,country;