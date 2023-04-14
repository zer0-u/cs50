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
- Webアプリケーションを作ってみる(sampleフォルダ)
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