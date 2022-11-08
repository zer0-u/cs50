#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int compute_l(int words, int letters);
int compute_s(int words, int sentences);

int main(void)
{
    string input = get_string("Text: ");
    int letters = count_letters(input);
    int words = count_words(input);
    int sentences = count_sentences(input);
    printf("%i letter(s)\n", letters);
    printf("%i word(s)\n", words);
    printf("%i sentence(s)\n", sentences);
}

// 文字数
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

// 単語数
// 除外していいパターン
// (1) 文がスペースで始まる
// (2) 文がスペースで終わる
// (3) スペースが2個以上続く
int count_words(string text)
{
    int count = 0;
    int length = strlen(text);

    // 長さ0の文章に対応する
    // TODO もっといい方法があると思う
    if (length <= 0)
    {
        return count;
    }
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    // 最後の単語がカウントされない問題に対応
    // TODO もっといい方法があると思う
    count++;
    return count;
}

// 文の数
// .や ! や ? で終わるものを文章とする
// 略称としてのピリオドは気にしなくて良い
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        char c = text[i];
        if (c == '.' || c == '!' || c == '?')
        {
            count++;
        }
    }
    return count;
}

// 100語あたりの平均文字数
int compute_l(int words, int letters)
{
    return 0;
}

// 100語あたりの平均文章数
int compute_s(int words, int sentences)
{
    return 0;
}