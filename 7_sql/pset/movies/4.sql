-- IMDbレーティングが10.0の映画の数を判別する
SELECT count(movie_id) AS count FROM ratings WHERE rating = 10.0;