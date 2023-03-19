-- リリース日が2018年以降のすべてのムービーのタイトルをアルファベット順にリストする
SELECT title FROM movies WHERE year >= 2008 ORDER BY title;