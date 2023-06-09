# 0414

## 講義動画
- これまで学んできた言語を組み合わせる
- まだAndroidがKotlinじゃなくてJavaの時代らしい
  - 2021年なのに？
  - KotlinもJavaに含めているのかな
- http-serverは無償なのでちょっと機能が弱い
  - クライアントサイドに完結した処理はできるがサーバサイドとの連携はできない
  - 別のツールを後ほど紹介する
- ルーティング
  - 特定のフォルダやサイトを参照しないURLのあり方
- 先週までのツールではクエリパラメータを解析できなかった
  - 追加できても読み取れない
- pythonで構築されたWebサーバを使うとパスパラメータが使えるようになる
  - dictオブジェクトに変換してくれる
- フレームワークを使う
  - 誰かが書いたライブラリの束
  - 物事を行うための一連の規則
  - bootstrapもフレームワークの一種
- flaskはpythonのフレームワーク
  - パスパラメータ解析やメール送信などが簡単にできる
- flaskを利用する
  - from flask import Flask
- flaskの規則
  - ルートディレクトリにapp.py, requirements.txt, staticディレクトリ, templatesディレクトリが必要
  - requirements.txtは参照したいライブラリの名前を列挙したテキストファイル
  - staticディレクトリには画像やCSSなど静的コンテンツを入れる
  - templatesディレクトリはHTMLを入れる
  - これはflaskの慣習
    - フレームワークが変われば慣習も変わる

## 講義動画(8:47)
- Webアプリケーションを作ってみる(helloフォルダ)
- pythonのコメントは `//` でなく#だと忘れていた
- app.py→index.html
- 静的ファイルがないのでstaticsは不要
- requirements.txtはシンプルなものでいいと言っているが具体的な手順は不明
- 起動する
  - http-serverはapp.pyの中身をそのまま表示する
  - flask runで実行(必要なものは事前のインストール済)
- requrements.txtは今のところつくらなくていいらしい
- flaskはデフォルトでポート5000を使う
- URLの末尾に「/?name=david」を足してみる
  - /はChromeによって省略されたものを補完している
- davidを取れるようにしたい
  - request.args.getを使う
- 今日はここまで(18:00)

# 0415

## 講義動画(19:00)
- render_templateの使い方について補足
  - テンプレートで参照する用の変数名=python内の値(変数も可)
- URLを直接いじる形式はやめたい
  - テキストボックス等に入力された値をURLに含めたい
- hello1フォルダ
- form要素のactionでsubmit時のURLを指定できる
  - ルートURL/greet?name=入力値 に移動する(現時点では404)
- /greetにアクセスしたらgreet.htmlを返すよう、greet関数を実装する
  - HTMLファイルはまだ用意されていない
- この時点でsubmitすると500になる(greet.htmlがないので)
- ターミナルにはスタックトレースが表示されている
  - jinja2.exceptions.TemplateNotFound: greet.html
- greet.htmlを作ったら正常に動作した
- nameが空欄のままsubmitするつ「hello,」としか表示されない
  - request.args.get("パラメータ名", デフォルト値) が使える
  - パラメータが無い時にデフォルト値が代入される
  - キーがある場合は何も起こらない
    - 空文字が代入されているとみなされている
- input要素にrequiredをつけて解決した
  - クライアントサイドの入力チェックは信頼できない
  - Devtoolから改変してすり抜けられるので
- index.htmlとgreet.htmlには問題がある
  - 一部が共通している(doctype,html,head等)
  - ファイルが増えると変更の手間も増える
  - 共通点をくくり出したい

## 動画 レイアウト共通化(34:25)
- hello2フォルダ
- templatesフォルダにlayout.htmlを作ってindex.htmlの内容をコピペ
- index.htmlとgreet.htmlは大幅に書き換える
- {% %}でブロックを定義する
- {{}}や{% %}はJinja構文と呼ぶ
  - FlaskはJinja構文を借りている
- app.pyは変更なし
- 実行したら503になってしまった
  - 再実行で問題なく動作
- devtoolで参照するとjinja構文が解消されて完全なHTMLになっていることが分かる
- デザインのよさ(保守しやすさ)とメモリ効率の両方を意識した書き方

## 動画 セキュリティの問題(41:00頃)
- URLから入力値が推測できてしまうのはよくない
  - 名前はともかくパスワード等は漏らしたくない
- index.htmlのform要素のmethod属性をgetからpostに変更するとURLの末尾には載らない
- submitで405(method not allowed)が起きる
- @app.routeの第2引数でメソッドを指定してやる
- 405は解消した
- POSTリクエストのデメリット
  - 履歴やオートコンプリートの有用性が下がる
  - リロード時に不要な更新が行われてしまう可能性がある
  - ブックマークができない
- GETとPOSTはそれぞれ適切に使い分ける必要がある
- 今日はここまで(46:50)

# 0417

## 動画 46:52
- POSTリクエストにしたら名前が取れなくなった
- request.formでリクエストボディを参照できる
  - 使い方はrequest.argsとほぼ同じ
- /greetページを更新するとPOSTリクエストが再送される→正しい結果が表示される
- FlaskはMVCに基づいたフレームワーク
  - app.pyはコントローラに相当する
  - htmlファイルはビューテンプレート(ユーザーインターフェース)
  - 現時点ではモデルがない(CSVやDBを指すことが多い)
- 新たなアプリケーションを作るので現在のコマンドは停止する

## 動画 FroshIMS 50:44
- 下準備
  - app.py
  - templates/layout.html(hello2からコピー)
    - titleタグの中身だけ変えておく
- 学生が学内スポーツに参加するための登録作業を行うらしい
  - 以前は紙で管理していた
- index.htmlもとりあえず用意する
- ファイルを変更するたびにflask runをやり直しているがこれは意味があるんだろうか？
  - こちらの手元ではちゃんと変更が反映されている
  - pset9で再起動を自動化する方法を紹介するらしい
- optionタグにdisabledとselectedをつけるとドロップボックスに簡易的な説明を追加できる
- registerボタンを押した後の処理を実装する
  - まずは入力値チェック
- 動画内の指示に細々したミスがある
  - デモのためか単なる間違いか
- 正しいデータを送ったはずなのにsuccess.htmlが表示されない
  - selectタグで選んだ結果が送れていない？
  - selectタグにname属性をつける必要があった
- devtoolのnetworkタブ(のPayloadタブ)でリクエストボディが参照できる
  - リクエストボディも見えちゃうんならPOSTのセキュリティはちょっと問題がありそう
  - 暗号化してあればいいのかな
- CSSファイルの適用方法
  - layout.htmlのheadにlinkをつけるだけ
  - layoutの中にプレースホルダを用意すると、それぞれのファイルに特定のCSSファイルを適用できる
  - ↑は複雑になりやすいのでクラス名などで判別する方が多い
- selectの中身がハードコートされているのが気になる
  - app.pyでもたせよう
  - pythonに定数という機能はない
  - 変数名を大文字にして区別する慣習
- index.htmlを変更する
  - {% 変数 in リスト %}と{% endfor %}で繰り返しが表現できる
- 今日はここまで(1:13:59)
- ※次回はfroshims1フォルダを編集する

# 0423

## 入力形式の変更 動画(1:13:59)
- セレクトボックスをチェックボックスやラジオボタンに変更する
- なんか503が出たけど時間を置いたら直った
- ラジオボタンの挙動がおかしい
  - ラベルにカーソルが合う感じがする
- ラジオボタンは同じnameの中で1つだけ選ばれるよう調整される

## データの保存 動画(1:16:00)
- 送信したデータを保存できるようにしたい
- froshims3というディレクトリがあるらしい
  - 画面を見ながら作ってみる
  - こういうファイルってあらかじめ配布されているのかな
- 辞書オブジェクトに保存する
- 登録後に一覧画面が表示されるようになった
  - エラー画面も出た
- 辞書オブジェクトはサーバを停止すると中身がなくなってしまう
- 別の方法を使った方がよい
- DBを導入しよう

## DBの導入 動画(1:23:24)
- froshims4
  - また手作業で動画から書き写す必要がある
- sqliteのdbファイルがないと動作しないっぽい？
  - sqlite3 froshims.db でdbファイルを生成できた
  - スキーマも作るしかないかぁ
- create table registrants (id integer, name text not null, sport text not null, primary key(id));
- registrantsテーブルは現時点で空っぽ
- バリデーションがまたfailure.htmlに戻っている
- 関数と変数でそれぞれ同じ名前を使えるのでなんだかもぞもぞする
- registrant.idとregistrant["id"]って何が違うんだっけ
  - プロパティアクセス？辞書オブジェクトの参照？
- またsqliteのプロンプトから抜ける方法を調べた
  - .exit
- 突然コンソールの出力がカラフルになった
  - 実行したSQL文も表示される
- 登録・参照・削除ができることを確認した
  - テーブルにも反映された
- 削除にはユニークなIDを使っている
  - 任意の行が削除されないよう、URLではなくリクエストボディに入れている
  - クロスサイトリクエストフォージェリ
- 今日はここまで(1:34:14)


## 0429

## メール送信機能の追加 動画(1:34:14)
- バージョン5になった
- さすがに複雑すぎる……
  - 見える範囲で書き足したけれどメール送信処理の部分が見えないので分からない
  - DBは使っていないっぽい？
- index.htmlにはEmailの入力欄が増えている
- メールがスパムに振り分けられていた
- import reは何のために追加したんだろう？
- requirements.txtも表示された
  - 今までFlaskも追加しなかったけどどうして動いてたんだろう
  - このファイルには謎が多い

## セッション 動画(1:40:55)
- Webアプリケーションの重要な機能
- ログイン状態やショッピングカートの中身を維持するために使われている
- ステートフル＝状態を持っている
- HTTPはステートレスなプロトコル
- Gmaukを例に考えてみる
- Webサイトを訪問すると、たいていCookieが置かれる
- Cookieはセッションを実現するために必要
  - ログイン状態など大事なものを保持することも、広告のターゲティングに使われることもある
- Cookieは通常とても大きい数字
- その後すべてのリクエストにCookieの値が追加される

## ログイン機能を作る 動画(1:46:44)
- またあらかじめ配布してあるファイルだ(login)
- どこで配布されているんだこれは
  - https://cs50.harvard.edu/x/2023/weeks/9/ のSource Code > zip
  - 年度は違うけど大まかには同じだろう、多分
  - インポートできないのでコピペした
  - 動いた
- index.htmlでJinja構文のifが使われている
  - Jinjaはインデントを気にしない(みやすさのために付けているだけ)
- flask_sessionディレクトリが生成されている
  - 中身のファイルは参照できない
- htmlファイルでもセッションの値は参照できるので、render_templateで渡す必要がなくなる
- NoneはNullと同じ

## ショッピングカートを作る (1:54:29)
- store
- ファイルがインポートできたらな～～～～！
- storeにはdbファイルもあるんだけどこれは移植できない
- 配布されたプロジェクトを見ると、どれもrequirements.txtを用意している
  - なくても動くのか……？
  - TODO 後で調べる
- デモデータにはハリポタ(全7冊)が追加されている
  - さすがに面倒なので適当なタイトルを5個ほど追加しておこう
  - setup.sqlを参照する
- 本のIDはhiddenで持っている
- 同じrouteを指定してPOSTとGETで関数を分けることは出来ないのかな
  - リクエストメソッドで分岐するのはダサく見える
- IN句の中のプレースホルダは1個でよい
  - 適宜区切ってくれる
- この実装だとユーザごとにカートが別れる理屈が謎だけども
  - 変数sessionは宣言せずに使えるっぽい
  - ユーザごとに変数が生成されるのかな

## 最後の例(shows) (2:02:20)
- 具体的な実装よりは動作のメンタルモデルを得るためのプロジェクト
- テレビ番組を検索するプログラム
- LIKEの後は手動で%を追加する必要があるらしい
  - そうだったっけ？
  - Mybatisと混同しているかも
- CREATE TABLE shows (id INTEGER, title TEXT NOT NULL, PRIMARY KEY(id));
- gitリポジトリとしてcloneしてcommit->pushでこっちにもファイルが反映されないかなぁ
- shows1では入力補完的に動作する
  - 検索ボタンがなくなっている
- inputイベントにイベントリスナが追加されている
- fetchの結果としてHTML(の一部)を生成し、ul要素の子に差し込んでいる
- いちいちli要素を生成するのは面倒
  - 検索結果だけを返したい
- show2でさらに改善する(動作はshow1と同じ)
- jsonfy関数で検索結果をJSONとして返している
- pset9ではサードパーティのAPIを使うらしい
- ティッカーシンボル？
  - アメリカの株式銘柄を判別するためのコード
- 講義終わり！

# 0430

## lab
- とりあえず疎通確認と思ったらなぜかtbody内のtr要素がテーブルの外に表示されてしまった
  - tdも足したら直った
  - なんだったんだろう？
- 誕生日は月と日に分かれている
- そんなに難しくなかった
- 入力検証とかした方がいいのかな
  - 要件には含まれないので一旦保留
- リクエストメソッドごとに関数を分けられないか試してみる
  - できたっぽい
  - 関数は増えるけど私はこっちの方がしっくり来るかなぁ
- importが過剰なのは発展的な要件に備えてかな？

### requirements.txtの謎
- そういえば配布されたプロジェクトにもrequirements.txtはない
- こいつは一体なんなんだろう
- requirements.txtはFlask独自の存在ではないらしい
  - pythonにおけるpackage.jsonみたいな存在
  - バージョン指定もできる
  - 他の環境において一括ダウンロードを行うために使う
- requirements.txtがなくてもアプリケーションは動作……する……？
  - 事実動いてるしなぁ
  - 他の環境でも同じライブラリをインストールするために必要なもの、という認識でいいのかもしれない
- この環境にはpipがインストールされている可能性がある
  - pylanceとpythonの拡張がインストールされていた
- ChatGPTも「なくても動作するけどあった方が便利」と言っている
- https://www.m3tech.blog/entry/python-packaging
- pip listでインストールされたライブラリを見るとFlaskとFlask-Sessionがある
  - versions.txtに出力済み
  - この間の講義で使ったからかもしれない
  - 最初からインストールされていたからrequirements.txtがなくても動いた……かも？
- ひとまず「なくても大丈夫そう」と結論付けておく

## pset
- labが案外するっと終わったのでpsetに手を付ける

### IEX Cloud
- APIキーを登録する必要があるのか……
  - 無料だからやっておこう
  - ちょっと操作方法が違う
  - APIキー1個までなら無料なのかな？
  - プランがわからん……
- https://iexcloud.io/pricing
  - 使うごとにかかるって感じじゃない？
- 2023の課題指示を見ても特に変わりがない
  - https://cs50.harvard.edu/x/2023/psets/9/finance/
  - 30日だけ有効って書いてある気がする
  - 怖いな～～～～！
- とりあえず今はフリープランだと分かった
  - https://iexcloud.io/console/account
- アカウントも消せない
- 怖い！
- https://www.reddit.com/r/cs50/comments/z2lmna/how_to_delete_iex_cloud_account_after_pset9/
- 同じこと考えている人見つけた
- 使わなければ払わなくていいよね……？
- 怖いから実装はしても動作はさせないようにしよう

### register
- 「ユーザの入力をPOST経由で/registerに送信します。」は「/loginに送信します」の間違い？
  - login.htmlではそう実装されている
- 違うかこれユーザ登録画面だ
- HTMLファイルも作らないといけない
- これを動かさずに実装するの無理では？
- 絶望したので今日は一旦終わり

# 0501

## pset

### register
- APIアクセスをしなければお金も発生しないはず
- ユーザ登録画面はAPI関係ないので普通に作っていく
- API keyが環境変数に含まれていないとアプリケーションが動かない
  - export API_KEY=pk_111111111 で代用
- apology画面が重い
  - 画像の生成に時間がかかっている？
  - 文字だけにした
- 「ユーザーが登録されると、ユーザーに自動的にログインするか、ユーザーが自分でログインできるページにユーザーを誘導することができます。」
  - とりあえずログインページにリダイレクトした
  - 自動的にログインする方法は後で調べて実装したい

### quote
- APIが必要なやつだ……
- というかアメリカの株式市場が分からなさすぎてなんもわからんだな
- お手本を忠実になぞるしかない
  - https://finance.cs50.net/quote
- 関数の数が増えるのもなんか嫌な気がしてきた
  - POSTではなくGETで分岐をかけて、表示だけの部分は早めに返してみる
- 横着して入力と結果を同じ画面に表示できないかなと思ったが難しい
  - まずはお手本通りに作ろう

### lookup_dummy
- 今回の課題はAPIアクセスを行う処理を実装することではない
  - helpers.pyのlookup関数は実装済
- これと同じオブジェクトを返す関数を作って、そちらを参照しよう
- APIアクセスを行う処理を呼び出さないので、そっちをlookup_api関数として隔離した
- 株価が固定値なのはちょっと寂しい
- random.uniformを使おう
  - https://it-ojisan.tokyo/python-random-range/
  - https://docs.python.org/ja/3/library/random.html?highlight=random#random.uniform
- ランダムにはなったが小数点以下の桁数がおかしい
  - usd関数を噛ませたら直った
  - lookup_apiではusd関数を呼び出していないので外側で噛ませる

### quote(再び)
- quoteページを呼び出すために毎回ログインし直すのは面倒くさいな
  - 一旦デコレータ外そう
- app.jinja_env.filters["usd"] = usd てなんだろう(application.py)
  - もしかしてjinja構文の中でusd関数が使えるようになっている？
  - 違った
- ヒントに書いてあった
  - {{ value | usd }} でusdフィルタ(関数)を適用できる
- できた！
- 今日はここまで

# 0502
- なんだかcodespaceの調子が悪い
- 一旦markdownのプラグインを止めた
- というか自宅のネットワークが不安定なのかもしれない

## pset

### buy
- symbolとshareの2つを入力するページが必要
- templatesフォルダの中がごちゃごちゃしてきた
  - サブフォルダみたいな分け方はしてもいいんだろうか
  - 良いとしてもいい感じの分け方は思いつかないが
- 今度はbuy関数のlogin_requiredをコメントアウトした
- ブラウザだとなぜかpythonのフォーマッタが入ってなくてオートフォーマットが効かない
  - どこでそんな差が生まれたんだ
- GET(画面周り)はできたのでPOST処理を書く
- 指示書きがちょっと雑というか翻訳しきれてない部分がある
- 自分なりに読み解いた手順
  - リクエストからsymbolとsharesを取得
  - symbolを使って現在の株価を取得(lookup関数を呼び出す)
  - ユーザが持っている現金を取得(謎)
  - 残高と株価×sharesを比較する
  - 購入できない場合はapologyを表示する
  - 購入できる場合は購入履歴をテーブル(謎)に登録する
  - 新たなページ(/index?)に遷移する
  - Symbol, Name, Shares, Price, Totalを表形式で表示する
  - 表の下にCash(株になっていない現金)とTOTAL(株と現金の合計)を表示する
- 新たなページへの遷移はindexの時に実装するから、今はとりあえずテーブルへの登録でいいらしい

### テーブル定義
- 新しいテーブルには何が定義されているべきか？
- 指示書きには↓とある
  - 購入を追跡する
  - 誰が・いつ・どの価格で・何を買ったのか
  - 一意であるフィールドにはUNIQUE制約(インデックス)をつける
  - 検索で使うフィールドには(UNIQUE以外の)インデックスをつける
- 何のために使うんだこのテーブルは
- history機能で使うっぽい？
  - symbol, shares, price(売買時), transacted(実行日時)の表
  - 売却した場合はsharesがマイナスで表示される(1株売った＝-1)
- もしかして、現時点で持っている数もこのテーブルの集約結果なのでは？
  - indexの指示を見るとGROUP BYとか使うって書いてある
- なるほどな～～～
- username, symbol, shares, transacted の4つを持っていれば大丈夫かな？
- idはtransactedでよいとは思うが面倒なのでidを立てる
- インデックスはusernameでいいのかな？
  - 後で調整する
- schema.sqlにCREATE文を作っておく
- sqliteに日付型は存在しないらしい
  - https://qiita.com/TomK/items/132831ab45e2aba822a8
  - https://www.sqlite.org/lang_datefunc.html
- datetime(CURRENT_TIMESTAMP,'localtime')で時差も考慮した文字列を生成できるらしい
  - しかしcodespaceの内部はUTCで固定されているようだ
  - 5/2 21:47に実行して5/2 12:47と表示される
  - 致し方ないのでCURRENT_TIMESTAMPだけにする
- transactionsテーブルを追加した

### buy(POST)
- それはともかく現在の残高はusersテーブルにあるんだよな
- transactionsへのINSERTとusersのUPDATEを同時に行う必要がある
- 競合は気にしなくていいらしい
- ユーザ情報はセッションから取得できる
  - usernameではなくidだった
  - transactionsテーブルも直す必要がある→直した
- いちいちログインし直すのは面倒なので、一旦user_idを1で固定しておく
  - 関数全体が実装できたら直す
- pythonのリファレンスの読み方が未だに少し分からない
  - isdecimalはメソッドだけどintは関数らしい
- 株価がランダムに返るのも面倒だな
- どんどんモック化が進んでいく
- エラーメッセージの英語を考えるのも面倒なので日本語にした
- transactionsテーブルにshares列がなかったので足した
- cashが取れない
  - db.executeの戻り値はlistらしい
  - dictのlistだから[0]["列名"]で絞る必要があった
- lookupの戻り値もdictなので["key"]の絞り込みが必要
- どうにか登録・更新できた
- phpLiteAdminでdbを読み込めるようにしたいんだが一向にファイルが開かない
- 残高以上ならapologyを返すはずが決済が通ってしまう
  - cashもマイナスで保存される
  - 単純なミスだった(remainではなくrequireで分岐していた)
- 各種テーブルをリセットするSQL文もschema.sqlに残しておこう
- 残高以上の時は決済されないように修正できた
- 今日はここまで

# 0503
- 今日はcodespace起動できた
- markdownのプラグインも有効化した
- phpLiteAdminはdbファイルを読み込むとブラウザで操作できるものらしい
  - でも読み込みが遅くてbad gatewayになったりする

## pset

### index
- ログイン中のユーザが持っている資産を一覧する
- 表の中に収めればいいんだろうか
- 現金と総合計はtfoot要素の中にある
- ファイル名はindex.htmlでいいのかな
  - ログインしてすぐに表示されるページだし、URLにもなにもないのでindex.htmlでよさそう
- とりあえずjinja構文抜きでちゃんと表示できるか確かめたい
- コメントアウトしてもjinja構文は無効化できないんかい
- 要素は出てるけどなんか位置がおかしい
- コピペしたのに揃わない
- mainタグにかかるCSSクラスがちょっと足りない
  - 表示したいものは出ているのでよしとする
- なんかコンソールが文字化けしている
  - 再起動して直した
- 表示する内容はusersテーブルとtransactionテーブルに分かれている
  - Cash : users
  - Symbol, Shares : transactions
  - Name, Price : lookupの結果(Symbolを使う)
  - Total : 計算
- 全部をまとめたオブジェクトがあるとよさそう
  - 値は決め打ちでportfolioオブジェクトを作った
  - index.htmlに反映させる
- jinja構文で掛け算を行おうとすると文字列の繰り返しになってしまう
  - なんで？
  - |usdの方が先に処理されてしまうっぽい
  - 計算式を()でくくったらちゃんとできた
- サンプルサイトで使えそうなシンボル一覧
  - https://search.sbisec.co.jp/v2/popwin/info/stock/pop6040_usequity_list.html
- サンプルサイトの時点で総合計の計算が合ってない謎
- どうやって総合計を出そうかなぁ
  - 計算はpythonで行い、htmlは表示だけの方がいいかもしれない
- 表示周りはできたので中身を作り込んでいく
- lookupの戻り値がでかすぎて計算が狂う
  - 上限が10000だったのでとりあえず100にした
- 小数点以下があるから正確には計算できないのかもしれない
  - 大まかに合っていればよしとしたい
- dictの値を取るのがとても面倒くさい
  - ついオブジェクトっぽく取ろうとしてしまう
- 恐らく大丈夫だろう

### sell
- HTMLはサンプルからコピペすると早いことが分かってきた
- やっぱりなんか表示が違うんだよな……
- 最初のうちはuser_idを決め打ちにするんだけど、これをいちいち戻すのが面倒
  - login_requiredと共になんとかできないかな
  - もういっそhelperに手を入れるか
- なんかflaskが動かなくなった、つらい
  - 何回か再起動したら直った
- 表示面は完成
- 突然codespacesが再起動した
  - 長い間起動しているとよくないのかな？
- application.pyがどんどん長くなっていく……つらい……
- util系の関数は先頭にまとめておく
- usersテーブルでもuser_idと指定しがち

### ここまでを見直す
- indexのテーブルで会社名が表示されていない
  - オブジェクトに含めてなかった
- コメントの行をずらしたらインデントが崩れて大変なことになった
- フォーマッタでも直してくれないの大変
- apologyを呼び出す時にステータスコードを渡しそびれている
  - 403で統一しておこう

### history
- transactionテーブルにpriceを含めていなかった
  - あ～～～～～～めんどくせ～～～～～！！！！！
- 関数の並び順に規則性がないせいで余計にストレスフル
- スキーマ変更完了
- historyも実装できた
- それにしてもデザインが若干違うのが気になる
  - layout.htmlでmainにクラスを足してもなんか違う
- できたのではなかろうか

### check50
:) application.py exists
:) application starts up
:) register page has all required elements
:) registering user succeeds
:( registration with an empty field fails
    expected status code 400, but got 403
:( registration with password mismatch fails
    expected status code 400, but got 403
:( registration rejects duplicate username
    application raised an exception (see the log for more details)
:) login page has all required elements
:) logging in as registered user succceeds
:) quote page has all required elements
:( quote handles invalid ticker symbol
    application raised an exception (see the log for more details)
:( quote handles blank ticker symbol
    expected status code 400, but got 403
:) quote handles valid ticker symbol
:) buy page has all required elements
:( buy handles invalid ticker symbol
    application raised an exception (see the log for more details)
:( buy handles fractional, negative, and non-numeric shares
    expected status code 400, but got 403
:) buy handles valid purchase
:) sell page has all required elements
:( sell handles invalid number of shares
    expected status code 400, but got 403
:) sell handles valid sale

- 未入力の場合のステータスコードは403ではなく400
  - 403はForbidden(閲覧権限がない)
  - 400はBad Request
- 他のエラー
  - 同じユーザ名を登録しようとすると例外が発生する
  - symbolが存在しない？不正？(quote, buy)

### 修正1 ユーザ名の重複
- 登録前に存在チェックを入れてみた
- 多分大丈夫だと思う
- check50も大丈夫だと言っている

### 修正2 不正なsymbol
- そもそも何が返ってくるんだろう？ None？
- エラーメッセージを見ると TypeError: 'NoneType' object とある
- 恐らくNoneが返ってくるはず
- importした関数と同じ名前の関数は宣言できない
  - 無限ループになる
- Noneだった場合にapologyを返しても処理が続いてしまう
- quoteがログイン限定の意味が分からない
  - login_requiredを外した
- 例外を発生させても駄目だった
- お手本では400/invalid symbolが返ってくる
- 呼び出し元でapologyを呼んだらちゃんと400になった
- 横着は駄目だったか～
- ちょっとダサいけどどうにか直った
- error_handler関数の使い所がわからなかったなぁ