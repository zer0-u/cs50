-- 9.0以上のレーティングを受けた映画を監督したすべての人の名前をリストする
SELECT count(p.name) FROM people p WHERE id IN (SELECT person_id FROM directors WHERE movie_id IN (SELECT movie_id FROM ratings WHERE rating >= 9.0));