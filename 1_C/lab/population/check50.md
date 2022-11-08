# check50の実行結果

:) population.c exists
:) population.c compiles
:) handles starting values less than 9
:) handles ending values less than starting values
:) handles decimal number of llamas
:( handles same starting and ending sizes
    Did not find "Years: 0" in "End size: "
    → (解決策1) 一通り計算した後にstartとendが等しい場合の分岐を追加
    → (解決策2) 計算ロジックをdo-whileからwhileに変更
:) handles starting population of 1200
:) rejects invalid populations and then handles population 9
:) rejects invalid populations and then handles population 20
:) handles starting population of 100