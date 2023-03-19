-- 2010年にリリースされたすべての映画とそのレーティングをレーティングの降順でリストするSQLクエリを記述します。同じ評価の映画の場合は、タイトルのアルファベット順に並べ替えます
SELECT m.title AS title, r.rating AS rating FROM movies m, ratings r INNER JOIN m.id = r.movie_id;