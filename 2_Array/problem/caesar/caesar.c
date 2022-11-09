// 2022/11/08 - 09
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
        // 出力する文字
        char output;

        char elem = text[i];
        int shift = key % 26;

        // 何も考えずにずらした文字
        // asciiの範囲を超える(128以上)とオーバーフローしてしまうためあえてint型で保持
        int shifted_elem = elem + shift;

        if (isupper(elem) && shifted_elem > 'Z')
        {
            output = 'A' + (shifted_elem - 91);
        }
        else if (islower(elem) && shifted_elem > 'z')
        {
            output = 'a' + (shifted_elem - 123);
        }
        else if (isalpha(elem))
        {
            output = shifted_elem;
        }
        else
        {
            output = elem;
        }
        printf("%c", output);
    }
    printf("\n");
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