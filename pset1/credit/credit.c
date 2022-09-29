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
    } while (number <= 0);

    int place = calculate_place(number);

    // 桁数がおかしいものは弾く
    if (!(place == 13 || place == 15 || place == 16))
    {
        printf("INVALID\n");
        return 0;
    }

    // 桁数を指定した操作がやりやすいように配列に変換する
    // ついでに並び順を変える（後ろからn番目をやめる）
    long work[place];
    long digit = 1;
    for (int i = 0; i < place; i++)
    {
        long elem = (number % (digit * 10)) / digit;
        work[i] = elem;
        digit = digit * 10;
    }

    // チェックデジットの計算
    // 1. 偶数桁(インデックスは奇数)に2をかける
    // 2. かけた結果が10より大きい場合は10の位と1の位に分ける
    // 3. 結果を足し合わせる
    int even_sum = 0;
    for (int i = 1; i < place; i += 2)
    {
        long elem = work[i] * 2;
        if (elem >= 10)
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
    for (int i = 0; i < place; i += 2)
    {
        odd_sum += work[i];
    }

    int check_sum = 0;
    for (int i = 0; i < place; i++)
    {
        long elem = work[i];
        if (i % 2 == 0)
        {
            elem *= 2;
            if (elem >= 10)
            {
                check_sum += elem / 10;
                check_sum += elem % 10;
            }
            else
            {
                check_sum += elem;
            }
        }
        else
        {
            check_sum += elem;
        }
    }

    // 5. 合計値の最後の桁が0、つまり10で割り切れるなら正しい
    bool isValid = (check_sum % 10) == 0;

    if (!isValid)
    {
        printf("INVALID\n");
        return 0;
    }

    // カード会社の確認
    // AMEX : 34, 37
    // MASTERCARD : 51, 52, 53, 54, 55
    // VISA : 4
    // 配列は逆順に入っていることに注意

    int first_elem = work[place - 1];
    int second_elem = work[place - 2];
    if (first_elem == 4)
    {
        printf("VISA\n");
        return 0;
    }
    if (first_elem == 3 && (second_elem == 4 || second_elem == 7))
    {
        printf("AMEX\n");
        return 0;
    }
    if (first_elem == 5 && second_elem >= 1 && second_elem <= 5)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    printf("INVALID\n");
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