-- Johnny DeppとHelena Bonham Carterの両方が主演したすべての映画のタイトルをリストする
SELECT count(m.title) FROM movies m WHERE m.id IN
    (SELECT s.movie_id FROM stars s WHERE s.person_id IN
        (SELECT p.id FROM people p WHERE name = 'Johnny Depp' OR name = 'Helena Bonham Carter')
    );