-- 2012年にリリースされたすべての映画の平均レーティングを決定する
SELECT AVG(rating) AS average FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2012);