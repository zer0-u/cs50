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
- 