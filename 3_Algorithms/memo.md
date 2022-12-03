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
    - 