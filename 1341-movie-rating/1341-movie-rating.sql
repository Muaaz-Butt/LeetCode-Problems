WITH user_ratings AS (
    SELECT u.name, COUNT(mr.movie_id) AS rating_count
    FROM MovieRating mr
    JOIN Users u ON mr.user_id = u.user_id
    GROUP BY u.name
),
max_ratings AS (
    SELECT MAX(rating_count) AS max_count
    FROM user_ratings
),
top_user AS (
    SELECT ur.name
    FROM user_ratings ur
    JOIN max_ratings mr ON ur.rating_count = mr.max_count
    ORDER BY ur.name
    LIMIT 1
),


february_ratings AS (
    SELECT mr.movie_id, AVG(mr.rating) AS avg_rating
    FROM MovieRating mr
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY mr.movie_id
),
max_avg_rating AS (
    SELECT MAX(avg_rating) AS max_rating
    FROM february_ratings
),
top_movie AS (
    SELECT m.title
    FROM february_ratings fr
    JOIN max_avg_rating mar ON fr.avg_rating = mar.max_rating
    JOIN Movies m ON fr.movie_id = m.movie_id
    ORDER BY m.title
    LIMIT 1
)

SELECT tu.name AS results
FROM top_user tu
UNION ALL
SELECT tm.title AS results
FROM top_movie tm;
