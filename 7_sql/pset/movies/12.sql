-- Johnny DeppとHelena Bonham Carterの両方が主演したすべての映画のタイトルをリストする
SELECT count(m.title) FROM movies m WHERE m.id IN
    (SELECT s.movie_id FROM stars s WHERE s.person_id IN
        (SELECT p.id FROM people p WHERE name = 'Johnny Depp' OR name = 'Helena Bonham Carter')
    );
-- Johnny Deppが出演したすべての映画のタイトル(61件)
SELECT m.title FROM movies m WHERE m.id IN
    (SELECT s.movie_id FROM stars s WHERE s.person_id =
        (SELECT p.id FROM people p WHERE name = 'Johnny Depp')
    );
-- Helena Bonham Carterが出演したすべての映画のタイトル(39件)
SELECT m.title FROM movies m WHERE m.id IN
    (SELECT s.movie_id FROM stars s WHERE s.person_id =
        (SELECT p.id FROM people p WHERE name = 'Helena Bonham Carter')
    );