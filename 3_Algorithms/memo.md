# week3 algorithms

## 1123

### names.c
- strcmpの戻り値とif文の関係がよくわからない
     - 2つの文字列が等しい時は0が返る
     - C言語で0は(0だけが)falseとみなされる
     - つまり2つの文字列が等しい時はstrcmpの戻り値0がfalseとみなされ、FoundではなくNot Foundが表示されるのでは？
     - debug50してみたところ、ループ1周目で配列の要素"Bill"と比較対象"Ron"とを比較→strcmpの戻り値が負→true→Foundと出力して終了していた
     - そもそも配列の要素"Ron"に到達していなかった

### 電話番号をstringとして扱う
- クレジットカード番号を文字列で扱えばもっと簡単かもしれない話
    - 後でweek1の課題をやり直してみたい

## 1124

### ソートアルゴリズム
- https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html

## 1130

### lab3
- とりあえず順番にタイムを取ってみる
- random5000.txt
    - 1: real 0m0.106s, user 0m0.052s, sys 0m0.026s
    - 2: real 0m0.033s, user 0m0.007s, sys 0m0.018s
    - 3: real 0m0.074s, user 0m0.031s, sys 0m0.021s
- random10000.txt
    - 1: real 0m0.414s, user 0m0.237s, sys 0m0.055s
    - 2: real 0m0.181s, user 0m0.003s, sys 0m0.047s
    - 3: real 0m0.191s, user 0m0.100s, sys 0m0.051s
- random50000.txt
    - 1: real 0m7.500s, user 0m6.916s, sys 0m0.269s
    - 2: real 0m0.527s, user 0m0.039s, sys 0m0.201s
    - 3: real 0m3.257s, user 0m2.649s, sys 0m0.220s
- 2がマージソートっぽいなーという気がしてくる
- reversed5000.txt
    - 1: real 0m0.115s, user 0m0.062s, sys 0m0.028s
    - 2: real 0m0.057s, user 0m0.006s, sys 0m0.020s
    - 3: real 0m0.060s, user 0m0.031s, sys 0m0.024s
- reversed10000.txt
    - 1: real 0m0.287s, user 0m0.189s, sys 0m0.056s
    - 2: real 0m0.104s, user 0m0.010s, sys 0m0.041s
    - 3: real 0m0.176s, user 0m0.105s, sys 0m0.040s
- reversed50000.txt
    - 1: real 0m5.775s, user 0m5.095s, sys 0m0.223s
    - 2: real 0m0.584s, user 0m0.039s, sys 0m0.190s
    - 3: real 0m3.256s, user 0m2.783s, sys 0m0.232s
- 多分3が選択ソートかな
- sorted5000.txt
    - 1: real 0m0.038s, user 0m0.000s, sys 0m0.022s
    - 2: real 0m0.030s, user 0m0.007s, sys 0m0.014s
    - 3: real 0m0.068s, user 0m0.031s, sys 0m0.022s
- sorted10000.txt
    - 1: real 0m0.147s, user 0m0.000s, sys 0m0.051s
    - 2: real 0m0.076s, user 0m0.009s, sys 0m0.041s
    - 3: real 0m0.229s, user 0m0.114s, sys 0m0.043s

## 1201

### lab3
- todoコメントを残したままだとcheck50がうまく動かない
- 1がバブルソート(bubble sort)・2がマージソート(merge sort)・3が選択ソート(selection sort)で正解
- windowsのchromeだとなぜかコピペが効かず不便

## 1203

### plurality
- ソートアルゴリズムを自分で実装する必要があるらしい
- とりあえず選択ソートで試してみる
- わからなくなってきたので手書きでアウトラインを作ってみる
- C言語の変数のスコープがよくわからない(関数？)
    - 同じ関数の中に2つのループを宣言し、それぞれのインデックスをint iで宣言したらコンパイルエラーが起きた
- コピペできないの不便だなー
    - open in vscode desktopを試してみた
    - しかしターミナルの出力内容はコピペできない
    - ctrl+cではなくctrl+shift+cらしい
- 変数のスコープはシンプルにループの宣言位置を間違えていただけだった
    - 並列にするつもりが入れ子になっていた
- しかし想定通りに動かない
    - 全部の要素が出てきてしまう
    - debug50の結果そもそも投票がうまくいっていないっぽいと分かった
- 入力で注意していないとブレークポイントの行がズレて何もわからなくなる
- 配列の要素を変数で持っているとダメか？
- あーーーーーーーーーーーあれだ
    - strcmpの戻り値はboolではなくintの罠にハマっていた
- それはそれとして、配列の要素を変数で持つと配列の中身は変更されないことが分かった
- まずはちゃんと投票できるようにしたい
- 得票の集計は問題なさそう
- 指示ページの例題をこなしていく
- check50も問題なくクリアできた
    - ターミナルへの貼り付けはctrl+shift+v
    - 得票数が同じ場合の出力順は問わないらしい
- 他の方法(バブルソートやマージソート)で実装するか迷うけど、とりあえず前に進むことを重視して完成とする

### Runoff
- ルールが難しい……
    - 1位→2位の順でどんどん比較していくっぽい
- zipファイルを展開したらrunoff/runoff/runoff.cになってしまった
    - 移動して解決済
- #define を使うと変数名と値の間の=は不要になるらしい
- preferencesの使い方が分からない
- 集中力が切れてきた……(17時ころ)
- debugしたいのにdebug50をつけ忘れることがある
- 今日はvote関数ができたらおしまいとする
- preferencesの要素はcandidatesのインデックス
    - (voters)番目の投票者が(rank)番目に投票した候補者のインデックス
    - 名前ではないらしい
    - 直接参照できるようにだろうか？
- debug50で正しい動作が確認できたので今日はここまで

## 1204

### Runoff
- 引き続きtabulate関数を実装する
- やりたいことを箇条書きにして実装すると迷わずに済む
- 無限ループが検証の邪魔なので、ひとまずprint_winner関数の戻り値をtrueにしておく
- debugの感じからするとtabulateはきちんと実装できたらしい
    - 複雑だしテストコードがほしくなってきた……
- print_winner関数を実装する
- 特に危なげなく完了
- デバッグ実行で一つ一つ確かめつつ進めているけれど、mainに書かれたロジックが複雑で呼び出し回数に自信が持てない
- 面倒になってきたのでtieとeliminateは一気に実装した
- 例題は問題なく動作する
- check50
    - find_min ignores eliminated candidates
    - 確かにeliminatedによる分岐は行っていなかった
- 修正後check50もクリア

## 1206

### tideman
- またしてもルールが難しい
- 今度はフォルダの入れ子構造を回避できた
- MAXは候補者だけでなく投票者の上限も定めている？
    - 仕様上は特に書かれていないが配列preferencesの要素数がMAX×MAXだから多分暗黙的に上限が決まっている気がする
- candidatesには候補者の名前しか入っていない
    - 投票数を保持する必要はないらしい

## 1208

### tideman
- どれだけ読んでも仕様が分からない
- 実装しながら把握するしかなさそう

## 12011

### tideman(vote関数)
- 時間が経ちすぎて説明を忘れた
- desktop版vscodeでも再読み込みは走る