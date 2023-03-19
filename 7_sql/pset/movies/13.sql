-- Kevin Baconが主演した映画に出演したすべての人の名前をリストする
-- 1.kevin baconが出演した映画のIDを一覧する
-- SELECT m.id FROM movies m WHERE m.id IN
--     (SELECT s.movie_id FROM stars s WHERE s.person_id =
--         (SELECT p.id FROM people p WHERE p.name = 'Kevin Bacon' AND p.birth = 1958)
--     )
-- ;
-- ↑に出演したすべての人の名前をリストする
SELECT p.name FROM people p WHERE p.id IN
    (SELECT s.person_id FROM stars s WHERE s.movie_id IN
        (SELECT m.id FROM movies m WHERE m.id IN
            (SELECT s.movie_id FROM stars s WHERE s.person_id =
                 (SELECT p.id FROM people p WHERE p.name = 'Kevin Bacon' AND p.birth = 1958)
            )
         )
    )
    AND p.id <> (SELECT p.id FROM people p WHERE p.name = 'Kevin Bacon' AND p.birth = 1958)
ORDER BY p.name
;