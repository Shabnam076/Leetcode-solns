# Write your MySQL query statement below
-- mushkil
Select c.category, count(a.account_id) as accounts_count from (
    SELECT 'Low Salary' AS category 
    union all 
    Select 'Average Salary'
    UNION ALL 
    Select 'High Salary'
) c 
LEFT JOIN Accounts a 
ON c.category = 
    case 
        when income < 20000 then 'Low Salary'
        when income between 20000 AND 50000 then 'Average Salary'
        else 'High Salary'
    end 
group by c.category;
