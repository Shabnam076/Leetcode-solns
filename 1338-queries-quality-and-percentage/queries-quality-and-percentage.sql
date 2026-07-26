# Write your MySQL query statement below

#Round, AVG, (case when condition then 1 end)
SELECT
    query_name,
    ROUND(AVG(rating / position), 2) AS quality,
    ROUND(
        COUNT(CASE WHEN rating < 3 THEN 1 END) * 100.0 / COUNT(*),
        2
    ) AS poor_query_percentage
From Queries
group by query_name;