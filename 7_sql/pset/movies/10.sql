-- 9.0以上のレーティングを受けた映画を監督したすべての人の名前をリストする
SELECT p.name FROM people p WHERE id IN (SELECT person_id FROM )