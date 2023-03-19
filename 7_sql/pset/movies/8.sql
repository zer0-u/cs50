-- トイ・ストーリーに出演したすべての人の名前をリストする
SELECT p.name AS name FROM people p  WHERE id in (SELECT person_id FROM stars WHERE movie_id = (SELECT id FROM movies WHERE title = 'Toy Story'));