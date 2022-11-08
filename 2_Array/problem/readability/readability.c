#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);

int main(void)
{
    string input = get_string("Text: ");
    int letters = count_letters(input);
    int words = count_words(input);
    printf("%i letter(s)\n", letters);
    printf("%i word(s)\n", words);
}

// 文章の字数を数える
// 句読点、数字、その他の記号は字数に含めない
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// 文章の単語数を数える
// 除外していいパターン
// (1) 文がスペースで始まる
// (2) 文がスペースで終わる
// (3) スペースが2個以上続く
int count_word(string text)
{
    int count = 0;
    return count;
}