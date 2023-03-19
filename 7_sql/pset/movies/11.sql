-- Chadwick Bosemanが主演した映画の評価の高い順に5つのタイトルをリストする
SELECT m.title FROM movies m WHERE m.id IN
    (SELECT s.movie_id FROM stars s WHERE s.person_id =
        (SELECT p.id FROM people p WHERE p.name = 'Chadwick Boseman'
        ));