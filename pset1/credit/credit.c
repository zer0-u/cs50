#include <stdio.h>
#include <cs50.h>

int calculate_place(long);

int main(void)
{
    // 入力値を得る
    long number = 0;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);

    int place = calculate_place(number);

    // 桁数がおかしいものは弾く
    // if(!(place == 13 || place == 15 || place == 16))
    // {
    //     printf("INVALID\n");
    //     return 0;
    // }

    // 桁数を指定した操作がやりやすいように配列に変換する
    // ついでに並び順を変える（後ろからn番目をやめる）
    long work[place];
    long digit = 1;
    for(int i = 0; i < place; i++)
    {
        long elem = (number % (digit * 10)) / digit;
        work[i] = elem;
        digit = digit * 10;

    }

    // デバッグ用
    // for(int i=0; i<place; i++)
    // {
    //     printf("work[%i] : %li\n", i, work[i]);
    // }

    // チェックデジットの計算
    // 1. 偶数桁(インデックスは奇数)に2をかける
    // 2. かけた結果が10より大きい場合は10の位と1の位に分ける
    // 3. 結果を足し合わせる
    int even_sum = 0;
    for(int i = 1; i < place; i +=2)
    {
        long elem = work[i] * 2;
        if ( elem >= 10)
        {
            even_sum += elem / 10;
            even_sum += elem % 10;
        }
        else
        {
            even_sum += elem;
        }
    }

    // 4. 奇数桁(インデックスは偶数)を足し合わせる
    int odd_sum = 0;
    for(int i = 0, i < place; i+=2)
    {
        odd_sum += work[i];
    }

    printf("even_sum : %i\n", even_sum);
    printf("odd_sum : %i\n", odd_sum);



}

// 入力値の桁数を得る
int calculate_place(long value)
{
    int place = 0;
    while (value != 0)
    {
        value /= 10;
        place++;
    }
    return place;
}