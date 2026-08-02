# Write your MySQL query statement below
(Select u.name as results
from Users u
Join (
    select user_id,count(*) as cnt
    from movieRating 
    group by user_id
) m
ON m.user_id = u.user_id
where cnt = (
    select max(cnt)
    from (
        select count(*) as cnt
        from MovieRating 
        group by user_id
    )temp
)
order by u.name
LIMIT 1)

UNION ALL 

(Select m.title as results
from Movies m
JOIN (
    Select movie_id, avg(rating) as average
    from MovieRating
    WHERE created_at >= '2020-02-01'
    AND created_at < '2020-03-01'
    group by movie_id
) r
ON m.movie_id = r.movie_id

where average = (
    select max(average) 
    from (
        select avg(rating) as average
        from MovieRating
        WHERE created_at >= '2020-02-01'
        AND created_at < '2020-03-01'
        group by movie_id
    ) temp
)
order by m.title
LIMIT 1);
