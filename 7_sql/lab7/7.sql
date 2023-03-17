-- Drakeの曲の平均エネルギーを返すSQLクエリ
SELECT AVG(energy) AS average FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = "Drake");