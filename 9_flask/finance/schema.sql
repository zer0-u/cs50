


CREATE TABLE users (
    id INTEGER,
    username TEXT NOT NULL,
    hash TEXT NOT NULL,
    cash NUMERIC NOT NULL DEFAULT 10000.00,
    PRIMARY KEY(id)
);

CREATE UNIQUE INDEX username ON users (username);

DROP TABLE IF EXISTS transactions;

CREATE TABLE transactions (
    id INTEGER,
    user_id INTEGER NOT NULL,
    symbol TEXT NOT NULL,
    shares INTEGER NOT NULL,
    price REAL NOT NULL,
    transacted TEXT DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY(id)
);

-- TODO transactionsテーブルにインデックスを追加する
-- TODO user_id列に外部キー制約をかける？

-- やらかし処理をなかったことにする
update users set cash = 10000;
delete from transactions;
select id, username, cash from users;
select * from transactions;
