# Array

- 便利リファレンス
    - https://manual.cs50.io/
- token
    - とりあえずeditaroにある

## lab

### scrabble
- 2022/11/07に取り組む
- 入力された文字と配列POINTSの対応付け
- 大文字Aからの距離が相当するのでは
    - 処理を簡単にするためまずは大文字に変換する
    - 65(Aのasciicode)ではなく 'A' を引くことで処理の意図を明確にする
- ちょっと面倒だけどdebug50を使う
    - debug50とprintfってどっちもそれなりに面倒
- 通常でもデバッグでも2個入れるのが手間だからまずはplayer1だけで実行
    - player2はコメントアウト
- 記号の考慮が漏れていた
    - 多分変なところのメモリを参照してscoreがおかしな値になっている
    - 計算前に分岐を追加
    - それでもうまくいかない
    - デバッグ実行の結果、追加した分岐 index <= 'Z' はよくないとわかった
    - 確かによくないので愚直に0以上25以下とした
        - indexを求めるときに - 'A' とした成功を引きずりすぎた
- check50が使えるようになった
    - https://cs50.readthedocs.io/github/#personal-access-token に従ってトークン生成
    - ↓の警告が出たので指示通り submit.cs50.io にアクセス
    - https://submit.cs50.io/users/zer0-u

```
Make sure your username and/or personal access token are valid and check50 is enabled for your account. To enable check50, please go to https://submit.cs50.io in your web browser and try again. For instructions on how to set up a personal access token, please visit https://cs50.ly/github
```
    - 再度トークンを使ってアクセス
    - 成功！
    - チェック内容も問題なし
- submit50もできた
- これらのコマンドはローカルのフォルダ構成に依存しないらしい
    - カレントに対象ファイルがあればOKっぽい？
- 後で前のファイルもチェックしたい