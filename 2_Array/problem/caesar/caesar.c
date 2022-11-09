// 2022/11/08 -
// https://cs50.jp/x/2021/week2/problem-set/caesar-less-comfortable/
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool validate_args(int length, string args[]);
bool key_is_digit(string input);
void crypt(int key, string text);

int main(int argc, string argv[])
{
    // コマンドライン引数からkeyを取得する
    if (!validate_args(argc, argv))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // TODO 後で消す
    printf("%i\n", key);

    // 平文を受け取る
    string plain = get_string("plaintext: ");

    // 変換したものを出力する
    crypt(key, plain);
}

void crypt(int key, string text)
{
    printf("ciphertext: ");
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        char c = text[i];
        // アルファベット以外はそのまま出力する
        if (!isalpha())
        {
            printf("%c", c);
        }
    }
}

// コマンドライン引数のチェック
bool validate_args(int length, string args[])
{
    if (length != 2)
    {
        return false;
    }
    return key_is_digit(args[1]);
}

bool key_is_digit(string input)
{
    for (int i = 0, length = strlen(input); i < length; i++)
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}