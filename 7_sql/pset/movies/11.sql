-- Chadwick Bosemanが主演した映画の評価の高い順に5つのタイトルをリストする
SELECT m.title AS title FROM movies m INNER JOIN ratings r
    ON m.id = r.movie_id
    WHERE m.id IN
        (SELECT s.movie_id FROM stars s WHERE s.person_id =
            (SELECT p.id FROM people p WHERE p.name = 'Chadwick Boseman')
        )
    ORDER by r.rating DESC
    LIMIT 5;
