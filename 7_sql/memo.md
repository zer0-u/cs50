# week7 SQL

## 0306

### 講義動画
- TV番組の名前とジャンルのアンケートを取ったらしい
  - ジャンルは複数選べる
  - ジャンルは1つの列にカンマ区切りで収められている
- 結果を使っていろいろな分析をしてみたい
- スプレッドシートが得意なこと
  - 検索やソートが素早い
  - 大量のデータを保存できる(限度はある)
- スプレッドシートは行と列でデータを保存する
- データを追加する時は行が増える
- 列は属性やフィールド(保存するデータの種類)を表す
  - フォームやシートを作る時に考えるべきこと
  - 列はあまり増えない
- データのレイアウトやスキーマ(構造)は事前に決めておくのが一般的
- CSVファイルはフラットファイルデータベースと呼ばれる
- データベース＝データを保存するファイルやプログラムのこと
- カンマの代わりに違う区切り文字を使っても良い
- データの中にカンマがあると混乱を起こしやすい
  - 含めたい時はデータをダブルクォートで挟むとよい
  - 区切り文字としてのカンマとそうでないものを分ける
- フラットファイルデータベースでは数式を扱えない
- 回答結果をCSVとしてダウンロードしてCS50 IDEにアップロードする
- Pythonを使って分析してみる(favorites.py)
  - 実行はできないが一応実装してみる
- やりたいことは小さく分けて実装する
- open関数の第2引数(モード)のデフォルト値はr(読み込み)
  - →読み込みの場合は第2引数がなくても動く
- DictReaderはpythonに組み込まれたもの
  - 最初の行をカンマで分割し、それぞれの値が列名だと「仮定」している
  - 1行目にヘッダがないとうまく動作しない
- タイトルの重複をなくしたい
- 方法1：setを使う
  - addメソッドで追加
  - forループで取り出し(setはイテレータを保持している)
- setの中身をソートする
  - sorted関数に渡せば自動的にソートしてくれる
- 表記ゆれまではカバーできない
  - 大文字・小文字を揃える＝正規化(なんらかのルールに従って標準化すること)
  - upper()メソッドを呼び出す
- 多少はまとまったがまだ重複している
  - 末尾のスペースの有無が差を生んでいるっぽい
  - stripメソッドで取り除く(先頭と末尾の空白文字を削除)
- これ以上の正規化はとても手間がかかる
  - typoの検知・修正など
  - これが現実
- 今日はここまで(30:55)

## 0308

### 講義動画
- 一昨日見ていたものと違う気がする
- 6日は2020版・8日は2021版
  - 困ったことになった
  - 新しいものの方がいいだろうし改めて2021版を見ることにした
  - 冒頭は倍速で
  - 6日に実装したものは2020フォルダへ移動した
- この回のポイントはデータの永続化
  - プログラムが終了してもデータを残す方法
- CSVとエクセルの違い
  - テキストファイルだが規則を持っている
  - フラットファイルデータベース
  - CSVは完全にポータブル
- 一番人気のある番組を調べたい
- DictReaderは単純なreaderより堅牢性が高い
- 重複のフィルタリング
- ますはlistを用いる
  - favorites0.py
- 入力値から不要な空白を取り除く
- すべて大文字に変換する
- pythonはメソッドチェーンが書けるので便利
- 結構違う流れなので結局等速で見ている
- データの外見を標準化＝正規化している
- python2を使っているらしい？
- listをsetに置き換える(favorites2.py)
  - setの省略記法的なものはないのかな
  - {}だった
- sortedでタイトル一覧をソートする
- これ以上の正規化はとてもむずかしい
- タイトルを入力した人数を数える
  - ここで実装していない差分については無視する
  - 「Brooklyn-99」と「Brooklyn 99」とか
- dictを使ってタイトル(title)と回数(count)を紐づけたい
  - favorites3.py
- dictとsetは省略記法が同じ{}
  - 中身の書き方で差別化するらしい
- titles[title]+=1で数を記録する？
- 実行するとエラーが発生する
  - KeyError(存在しない要素を参照しようとしている)
- 回数を増やす前に存在チェックを挟む
  - 存在すれば1増やす、しなければ0と紐づける
- dictをforで回すとキー名しか参照されない
  - print(title, titles[title]) で回数も表示される
- 存在チェックでfalseだった場合は0ではなく1で初期化すべきだった
  - あるいは0で初期化し、1増やす処理を常に行う
  - どちらの方法でも良い
  - 重要なのは事前にチェックすること
- dictのソート(sorted(dictオブジェクト))はキーによって行われる
- 値(登場回数)でソートしたい
- sorted関数には複数の引数を渡せる
  - 例 reverse=Trueで逆順
- 値でソートしたい時はソート用の関数を用意する
  - get_value関数
- sorted関数のkey引数にキー(を取得する関数そのもの)を渡す
- reverse=Trueは数値だと大きい順を意味する
- THE OFFICEってどんな番組なんだろう
- favorites3.pyをもっと短くしたい
- 引数keyにget_value関数ではなくラムダ関数を渡す
  - lambda 引数:戻り値
  - 再利用しないと分かっている関数を用意したい時に便利
- ラムダは1行だけの関数に使う
  - 基本的にすぐreturnされるとみなす(returnは書かない)
  - 難しい処理も盛り込めるが推奨されない
- 今回はここまで(36:14)

## 0309

### 講義動画(36:15)
- 1つのタイトルに注目する(favorites4.py)
- 「The Office」のつもりで「Office」と投稿した人がいたらもちろん総数は減る
  - 両方カウントするにはどうしたらいいか
- orで条件を複雑にする
- "OFFICE" in title ともできる
  - title(文字列)に「OFFICE」が含まれたら
- 「thevoffice」があることが分かった
- 「THE OFFICE」と「OFFICE」が同じものってどうして分かるんだろう？
  - テレビ番組はよくわからない
- 正規表現
- Googleフォームは回答の検証ができる
  - 検証に正規表現も使える
  - メールアドレスを表す正規表現は「.+@.+\..+」
- pythonでも正規表現が使える
  - reライブラリをimportする
  - re.search(パターン,対象文字列)
- re.search("office", title)にしたら何も検出されなかった
  - ひとまず大文字にしなければならない
- 「^(OFFICE|THE OFFICE)$」
  - OFFICEまたはTHE OFFICEで始まり、それ以外の内容がない
- 「^(OFFICE|THE.OFFICE)$」
  - THEの後に任意の1文字を指定できる
- THE OFFICE以外の番組名にも対応させる(favorites5.py)
  - 調べたいタイトルを最初に入力してもらう

### 講義動画(48:17)
- 生のコードを書くよりも効率的にデータを保持・操作したい
- この後SQLを紹介するらしい
  - ツールを使うことのトレードオフも紹介するらしい
- リレーショナルデータベース
  - スプレッドシートそのものに近い
  - CSVはスプレッドシートの中の1つのシートに相当する
- なんかVSCodeの調子が悪いのでMarkdownの拡張機能を一旦無効にした
- データを上手く処理するためのツールや言語が必要
- CRUDの話
- CREATE TABLE
- favorites.csvをリレーショナルデータベースに変換するには
  - .move csv
  - .import FILE TABLE
  - SQLなら↑2つでいいらしい
- この講座だとSQLは「シークェル」読み
- SQLite3を使う
- sqlite3 favorites.db で新しいデータベースを作る
  - 拡張子.dbは慣習的なもの
  - 自分の手元では確認プロンプトが出たが動画では出ていない
- .mode csvでCSVモードに切り替えた後、.import favorites.csv favorites.dbでインポートする
- .schemaでスキーマ構造を参照できる
- 今回はimportを使ったので、sqliteがよしなにしてくれる
  - テーブル作成(列名や型はファイルから推測)
  - データ追加
- プロンプトの終わり方が分からない
  - .exit だった
  - https://so-zou.jp/web-app/tech/database/sqlite/sqlite-command/
- CSVファイルがないので一旦見るだけにする
- SELECT文
- 組み込み関数
  - distinct(title)で重複を排除する
- 途中で空白行があるのが気になる
  - 誰かがタイトルに空白文字を投稿した？
- distinct(upper(title))で大文字小文字の差を無視して重複を排除できる
- count(title)で投稿されたタイトルの総数が分かる
- WHEREやGROUP BYで行をフィルタリングする
- LIKEでパターンマッチングを行う
  - title like "%office%"
  - SQLがサポートする正規表現はちょっと控えめなので細かいことをやりたい場合はPythonを使う
- LIMITで表示件数を制限する
- DELETE文
- UPDATE文
- データを簡単に変更できるのがリレーショナルデータベースの強み
- 今日はここまで(1:08:06)

## 0310
- Markdownプラグインを有効化した

### 講義動画(1:08:06)
- データベースの設計
- SQLの予約語は大文字、列名やテーブル名は小文字で表している
  - 慣習的なもの
- 現在のfavoritesテーブルのgenresを見る
- UPDATEのデモの時にWHEREを指定しそびれて全部が同じ結果になってしまった
  - 取り消せないのでfavorites.dbを消して作り直す
- comedyを選択した作品を出してみる
  - WHERE genres = "Comedy" だとComedy「だけ」を指定した作品が出てくる
  - 複数ジャンルの中にComedyが含まれるものは検出できない
  - LIKEを使うとComedyを含む作品がすべて表示される
- LIKEを使うと「Music」と「Musical」が区別できない
  - MusicにMusicalが含まれてしまう
- カンマ区切りで1つのセルに複数の値を入れるのは単純だが参照しづらい
- Pythonのコードを使ってデータを加工する
  - showsテーブルとgenresテーブルに分ける
- バージョン8？
  - オンラインで公開されているらしい
  - どこにあるか分からない
- CS50ライブラリに含まれるSQL操作関数を呼び出している
- favorites.csvを読み込み、1行ごとに処理をする
  - 最終的にshowsテーブルとgenresテーブルができる
- showsテーブル
  - id列(整数・プライマリキー)
  - title列(文字列・NOT NULL)
- genresテーブル
  - show_id(整数・外部キー)
  - genre(文字列・NOT NULL)
- この時点ではタイトルを正規化していない
  - 同じタイトルが複数出てくる
- 1行1データなのでスッキリ見える
- 同じshow_idを持つ行が複数ある
  - ジャンルを複数選んだ場合
- 1対多の関係
  - 1つの番組に対して複数のジャンルを持っていること
- genresテーブルを使えば「Comedy」にチェックを入れた番組が簡単に抽出できる
- select title from shows where id in (select show_id from genres where genre = "Comedy");
- distinctをつければ重複も排除できる
- SQLは徐々に作っていく方がよい
- DBをCSVに転送する方法はいくつかある
  - SQLiteには書き出しコマンドがある
  - 基本的にはSQLの世界でデータを長期的に保存する
- データを増やす場合はshowsテーブルとgenresテーブルの両方に追加する必要がある
  - 場合によってはgenresテーブルに複数の行を追加する
- これらの作業はいずれpythonやSQLを使って全て自動化される予定
- 今日はここまで(1:31:38)

## 0313

### 講義動画(1:31:40)
- pythonでやっていたあれこれをSQLに置き換えてみる(favorites6.py)
- cs50ライブラリのSQL関数を使う
  - ほかはわりと複雑
- 今アクセスするのはfavoritesテーブル
  - showsとgenresはまだもう少し先の話
- LIKE ?でプレースホルダが成立するらしい
  - %ほげほげ%って感じになるんだろうか？
  - ならないっぽい(1:36:10頃のデモ)
- LIKEによる検索は大文字小文字のゆらぎを無視してくれるらしい
  - 「LIKE "The Office"」で「ThE OffiCE」が引っかかる

### 講義動画(1:40:00)
- データセットを大きくする
- IMDbの実際のデータセットから作ったRDB
  - InternetMovieDatabase.com
  - https://www.imdb.com/
  - テレビ番組や映画・俳優などを検索できるウェブサイト
  - データセットはTSV(タブ区切り)で提供される
- データセットの中身を確かめる
  - 今回の講義は基本的に見ているだけなのかな？
- shows, genres, stars, writers, ratingsなどのテーブルが見える
- shows
  - id・タイトル・年・総エピソード数
- SQLiteで扱うデータ型は全部で5つ
  - integer(整数)
  - numeric(日付や時間のための、整数や実数でない数値)
  - real(実数)
  - text(字数制限のないテキスト)
  - blob(binary large object)

## 0314
- 昨日はなんか変なところで終わらせてしまった

### 講義動画(1:42:45)
- showsテーブルの詳細
  - idは自動的に挿入された整数(プライマリキー)
- genresテーブルはshowsテーブルへの外部キーを持っている
- stars(出演者)
  - show_id, person_id
- writers(脚本家)
  - show_id, person_id
- rating(評価？)
  - show_id
  - rating(評価の★の数？・実数)
  - votes(投票数)
- people(人物)
  - writersとstarsの親
  - 氏名と生まれ年を持つ
  - peopleとpersonてニュアンス的にはどう違うんだろう
- 共通点を取り出して1つのテーブルに定義している
- peopleテーブルには100万人以上のデータが保存されている
- SQLの実行時間をはかる
  - .timer onの後にSQL文を実行すると、実行結果の後に所要時間が表示される
- titleが"The Office"のshows一覧は0.02秒ほどで取得できた
- showsテーブルのtitle列にインデックスを張ってみる
  - 作成に0.349秒かかる
  - インデックス作成後のSELECT文は計測できないほど短時間で実行できた
- データ構造(week5)と実行時間(week3)にも関わってくる
- インデックスなしの場合は上から順番に参照していく
- インデックスを張ると、DBへ事前にヒントを与えられる
  - 線形探索ではなくツリー構造が使えるようになる
- RDBの世界ではB-treeをよく使う
  - 二分木ではない
  - 高さ控えめ・子が3つ以上あるときもある木構造
- テーブルを結合する
- Steve Callelが出演する番組を全て知りたい
  - showsとpeopleをつなぐ必要がある
  - starsテーブルは結合テーブル(2テーブルをつなぐもの)
- まずはpeopleでIDを取得する
  - 名前と生年は気にしなくて良い
- starsテーブルを使うと、あるperson_idに紐付けられたshow_idをすべて取得できる
- SELECT title FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Steve Carell"));
- 長くなるので要素に分解して考える
- order by titleをつけるとタイトルのアルファベット順で参照できる
- 0.094秒で結果が出た
  - スピードアップできないか？
  - starsテーブルのperson_id列・show_id列にもインデックスを張る
  - それぞれ作成に0.89秒・0,64秒かかった
  - peopleテーブルのname列にもインデックスを張る
  - 0.84秒で作成
  - 0.001秒まで短縮できた
- データセットが遅い時は適切なインデックスが存在しない場合が多い
  - プログラムが採用したアルゴリズムが悪い可能性もある
- ネストされた＝括弧で括られたクエリが多くなってきた
- JOINで短縮しよう
  - SELECT title FROM people JOIN stars ON people.id = stars.person_id;
  - id列を使ってpeopleテーブルとstarsテーブルを結合する
  - SELECT title FROM people JOIN stars ON people.id = stars.person_id JOIN shows ON stars.show_id = shows.id
  - showsテーブルも結合する
  - SELECT title FROM people JOIN stars ON people.id = stars.person_id JOIN shows ON stars.show_id = shows.id WHERE name = "Steve Carell";
  - 検索対象を指定する
  - 1つのクエリで同じ結果が得られるようになった
- SELECT title FROM people, stars, shows WHERE people.id = stars.person_id AND stars.show_id = shows.id AND name = "Steve Carell";
  - 同じ結果を得るためのSQL文は複数ある
  - 必要なテーブルを列挙してWHEREで絞る
  - セミコロンをつけなければ文中での改行も可
- インデックスのデメリット
  - インデックスが増えるほどメモリが必要になる
  - ちょうどいい数を見つけるのも設計プロセスの一部
- 今日はここまで(2:03:40)

## 0316
codespacesがアップデートしたのでプラグインを入れ直した

### 講義動画(2:03:40)
- SQLインジェクションの話
- 大きな力には大きな責任が伴う
- cs50ライブラリのexecute関数はプレースホルダをサポートしている
- 文字列結合でSQL文を組み立てるとインジェクションの恐れがある
- ユーザ名に '存在するユーザ'--' とするだけでパスワードを入力せずにログインできてしまう
- updateやdropも実行できてしまう

### 講義動画(2:11:40)
- 競合状態(race conditions)
- 複数のユーザが同時に同じデータを参照しようとする時の問題
  - SQLやpythonに限らずコンピュータ全般で発生する
- Instagramの投稿に「いいね！」を押すと何が起きるか
  - SELECT文で対象の投稿の「いいね！」数を取得する(IDで特定)
  - 「いいね！」数を1増やす(Python)
  - UPDATE文で「いいね！」数を更新する
- 複数のユーザが同時に「いいね！」を押すと何がおきるか
  - ↑の処理はアトミックではない
  - 上から順に実行されるが、間に別のユーザの処理が割り込んでくるかもしれない
  - 正しい結果が得られなくなる
- 正しく実行するにはそれぞれの処理をアトミックにする必要がある
  - 他のユーザの処理を割り込ませないようにする
- 「ロック」という解決策があることを知っておいて欲しい
  - トランザクションの概念
- 講義動画おわり！

## 0317

### lab
- 既存のテーブルはsongsとartistsの2つ

CREATE TABLE songs (
    id INTEGER,
    name TEXT,
    artist_id INTEGER,
    danceability REAL,
    energy REAL,
    key INTEGER,
    loudness REAL,
    speechiness REAL,
    valence REAL,
    tempo REAL,
    duration_ms INTEGER
);
CREATE TABLE artists (
    id INTEGER,
    name TEXT
);

- sql文だけでいいのかな？
- 曲が分からないから結果の正しさも推測できない
- valence : 曲のポジティブ性を表す尺度。0.0～1.0の値を取り、高いほど陽気な曲
- SQLにおける平均はAVG関数
- そんなに難しいものはなかった
- プロンプトを終わらせる時は「.exit」
  - やらないと覚えられない
- check50も無事通ったのでよしとする
- 一応solutions動画だけ見ておこう
- 8.sqlの正解は「like '%feat.%'」だった
  - ドットも必要
  - 日本語の問題文だとドットが抜けている
  - check50も通ってしまうが気持ち悪いので直しておく
- 簡単な演習だった

## 0319

### pset movies
- 参照するスキーマ構造は講義中で扱ったものと同じ

CREATE TABLE movies (
                    id INTEGER,
                    title TEXT NOT NULL,
                    year NUMERIC,
                    PRIMARY KEY(id)
                );
CREATE TABLE stars (
                movie_id INTEGER NOT NULL,
                person_id INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id),
                FOREIGN KEY(person_id) REFERENCES people(id)
            );
CREATE TABLE directors (
                movie_id INTEGER NOT NULL,
                person_id INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id),
                FOREIGN KEY(person_id) REFERENCES people(id)
            );
CREATE TABLE ratings (
                movie_id INTEGER NOT NULL,
                rating REAL NOT NULL,
                votes INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id)
            );
CREATE TABLE people (
                id INTEGER,
                name TEXT NOT NULL,
                birth NUMERIC,
                PRIMARY KEY(id)
            );

- ratingって何かなとデータを覗いてみたがよく分からない
  - 評価数？
  - 少なくとも年齢制限ではない
  - 1.0から10.0
  - 10点満点中何点かって感じらしい
- 参照しているデータが少し古いので、現在のIMDbで確かめても正しい値が得られるわけではない
- 相変わらず映画に詳しくないので結果の正しさが直感的には理解できない
- 1個1個の件数が多いのでテストにも時間がかかる
  - テストする時はlimitをつけた方がいいかもしれない
- inner join の使い方を忘れる
- 主演した＝出演した？
  - starsテーブルに主演とそれ以外の区別はないので恐らく誤訳
  - 原文は「all people who starred in a movie...」
  - star(動詞)は「主演する」という意味
  - まぁともかく「starsテーブルに存在する」と読み替えて良いんじゃなかろうか
- テーブルが増えてくると大変
- どういう風に改行すると後から読みやすいだろうか
- 内側から順番に組み立てないとこんがらがる
- kevin baconは1人しかいない気がするが
  - 1958年生まれのKevin Baconと生年不明のKevin Baconがいた
- それぞれの結果の行数だけヒントとして出てくる
- とはいえ数多いしなーーーーーーー
- 一旦check50しよう
  - 3, 10, 12が間違っている

#### pset movies 修正(3)
- 期待値より多くの作品が出力されている
- 2018とすべきところを2008としていた(凡ミス)
- しかし2018にしてもまだ多い
- 見た感じ正しい結果が出ていそうな気がするんだけどな
- countを使ったら行数が合致したので恐らく大丈夫だろう
- expected valueが全てではないらしい

#### pset movies 修正(10)
- Christopher Nolanがいない
  - 違った
  - この演習に関してはexpected valueを信じたら駄目だ
- 「以上」が「より大きい」になっていた
- 件数が合っているから大丈夫なはず

#### pset movies 修正(12)
- 6件のところが94件になっている
- おそらく「どちらかが出演した」作品の和になっている
- Johnnyが61件・Helenaが39件・共演が6件
  - 61+39-6=94
  - 推測通り
- Johnnyが出演した中で、かつHelenaが出演したものっていう絞り方にすればいける？
- できたと思われる

#### pset movies 再チェック
- 10.sqlを件数表示のままにしていた
  - 凡ミス注意
- できた！

### pset fiftyville
- 面白そう
- fiftyville.dbにあるテーブルの一覧
  - airports
  - crime_scene_reports
  - people
  - atm_transactions
  - flights
  - phone_calls
  - bank_accounts
  - interviews
  - courthouse_security_logs
  - passengers
- まずはcrime_scene_reportsを参照すると良いらしい
- テーブルを絞ってCREATE文を見たい時は「.schema TABLE_NAME」
  - 先頭にドットが必要

#### fiftyville crime_scene_reports
- 事件は2020年7月28日にチェンバリン通りで起きた
- cat filename.sql | sqlite3.fiftyville.db > output.txt
- ファイル実行用のスクリプトを用意しておこう
   - run.sh
   - 引数で実行用のファイル名を指定
   - answers.txtを上書きしたりすると面倒なのでkeepフォルダへ移動
   - 最後に戻す
- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.
  - 盗難事件は午前10時15分にchemberlin通りの裁判所で起きた
  - 同じ日に3人の目撃者へインタビューが行われた
  - それぞれの目撃者は裁判所について言及している
- 次はinterviewsかな？

#### fiftyville interviews.sql
- 違うかもしれない
- 一旦年月日で絞ってみる
- 6件出てきた
- 目撃者は3人なのでちょっと多い
- 突然codespacesが落ちたのでｷｰってなった
- crime_reportのときに「目撃者は裁判所について言及している」とあるから、transcriptsに裁判所(courthouse)があるものに絞る
- いちいち切り替えるのも面倒だしcodespaces上では色付けされるので全部小文字で書くことにした
- 3人に絞り込めた
- 駐車場の監視カメラ・ATMの利用情報・飛行機の便情報が使えそう

#### fiftyville courthouse_security_logs
- 恐らくこれが駐車場の監視カメラ情報
- 2020年7月28日の午前10時15分から25分の情報が知りたい
- activityはentrance(入場)とexit(出場)のどちらか
- 今回は「出ていった車の情報」がほしいのでexitに絞る
- 全部で8件
  - うーん
- 一旦保留として次の手がかりに移る

#### fiftyville atm_transactions
- 朝早くって何時くらいだろう
  - とりあえず10時より前で出してみる
  - atm_transactionsテーブルに時刻情報はなかった
- 「引き出しているところを見た(saw the thief there withdrawing some money.)」だから種類はwithdrawに絞れる
  - そんな細かいところまで見られるものなのかな
- これも結果は8件

#### fiftyville flight
CREATE TABLE flights (
    id INTEGER,
    origin_airport_id INTEGER,
    destination_airport_id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    PRIMARY KEY(id),
    FOREIGN KEY(origin_airport_id) REFERENCES airports(id),
    FOREIGN KEY(destination_airport_id) REFERENCES airports(id)
);
- テーブル情報は別のファイルに用意しておこう(0_schema.txt)
- 「2020年7月29日(事件の翌日)、Fiftyvilleの空港を一番はやく出発する便」が知りたい
- Fiftyvilleの空港の略称はCSF・idは8
- 恐らく8時20分発のヒースロー(ロンドン)行きに乗ったと思われる
  - 乗客は8人
  - やたら「8」だな……

#### fiftyville phone_calls
- チケットを取るように電話していた
- 泥棒が「they」で表されてる＝複数犯？
  - これ日本語だとニュアンスが落ちるやつでは
- このテーブルにも時刻情報はない
- durationは電話をかけていた秒数？
  - less than a minute = 60秒以下
- 9件ヒット
  - 8件じゃなかった

#### fiftyville 考える
- ここまでで使えそうな個人情報
  - 車のナンバー(security / license_plate)
  - 口座番号(atm / account_number)
  - パスポート番号(flight / passport_number)
  - 電話番号(phone / callerとreceiver)
- peopleテーブルに一通りまとまっている

#### fiftyville 泥棒を特定する(7_people)
- これまでヒットした情報をすべて持っている人物が泥棒
- 3人ヒットした
  - Roger, Evelyn, Ernest
  - theyだし3人でもいいのかなー

#### fiftyville 協力者を特定する(8_receiver)
- 泥棒が電話をかけた相手が協力者のはず
- なんかうまく絞れてないな
- 手作業でちまちま絞り込んだ
  - 6_phoneの実行結果から泥棒の通話相手の番号を特定
  - peopleテーブルで絞り込み
  - Larry, Jack, Berthold

#### fiftyville テスト
- answer.txtだと「The THIEF is」なんだよな
- 違った
- 3つとも合ってないと駄目らしいのでヒントもなし

#### fiftyville 考え直し
- これまでの情報を整理してみる
- interviewの1つ目(駐車場)
  - I saw the thief get into a car in the courthouse parking lot and drive away.
  - 駐車場で車に乗り込み、走り去っていった
  - 車はいつ駐車場に入ったのか？
  - いやでも「駐車場から出ていった」ことが大事だから関係ないか
- 10時10分から25分について調べている
  - 事件が起きたのは10:15だからちょっとズレている
  - あまり関係ないが直しておこう
- log.sqlをもっと詳しく書いている
- bank_accountsテーブルを使っていないことに気がついた
- ↑を踏まえて情報を整理したら1人ずつに絞り込めた
- 相手がよくわかっていない時はtheyを使うんだろうか？
- 解けた！