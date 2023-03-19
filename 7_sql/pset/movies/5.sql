-- すべてのハリー・ポッター映画のタイトルと公開年を時系列でリストする
-- 映画のタイトルが 「Harry Potter」 という単語で始まる場合、それはハリー・ポッター映画であると判別できます。
-- 「含む」ではないらしい
SELECT title, year FROM movies WHERE title LIKE 'Harry Potter%' ORDER BY year;