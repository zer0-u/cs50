# week5 data structures

## 0118

- Codespaceそのものをアップデートすると自前で入れたプラグインが削除されてしまう
  - markdown all in oneを入れ直した

### mallocとrealloc
- C言語は今回で最後らしい
- 検索ではなく挿入コストの話
  - ソート済のサイズnの配列に要素を1つ挿入するには何ステップかかるか
  - O(n)・Ω(1)
- list[3]とmalloc()はメモリが確保される領域が違う
  - listはスタック
  - mallocはヒープ
  - このあたり覚えてないから復習しなければ
  - week4のnote見たら動画だった……
- list[3]だと永遠にサイズ3の配列を与えることになる
- list=tmpとする *前に* list(が指しているメモリの塊)を解放する必要がある
- コメントで書いた方が流れがわかりやすいかもしれない
- reallocは↓3つを行う
  - 新たなメモリの確保
  - 以前のメモリにあった内容を新たな領域にコピー
  - 以前のメモリを解放
- reallocの戻り値をもとの変数に代入することはできないんだろうか
  - 試してみたらできた(list_3_1.c)

### struct
- ドット演算子は構造の中のフィールドにアクセスする
- *は掛け算だったりポインタだったり間接参照だったりする
- structとドットと*があれば大抵のデータ構造は網羅できるらしい
- 糖衣構文「->」を使うとプロパティにアクセスして代入された値を見れる(. *と同義)
- 連結リスト(linked list)の話をしている
  - ポインタのための容量(8バイト)と引き換えにデータのコピーを免れる
  - 要素を作る時に、要素そのものを収める空間とは別にポインタを収める空間も要求する
- 連結リストの最後の要素はポインタとして何を持つべきか
  - 先頭の要素は無限ループを引き起こすので推奨できない
  - NULL(0x0)を入れる
- 循環を検出できれば＝先頭が判別できれば先頭の要素へのポインタも入れられる