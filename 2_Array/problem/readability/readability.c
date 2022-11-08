#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int compute_coleman_liau(int letters, int words, int sentences);
float compute_l(int words, int letters);
float compute_s(int words, int sentences);

int main(void)
{
    string input = get_string("Text: ");
    int letters = count_letters(input);
    int words = count_words(input);
    int sentences = count_sentences(input);
    printf("%i letter(s)\n", letters);
    printf("%i word(s)\n", words);
    printf("%i sentence(s)\n", sentences);
    int index = compute_coleman_liau(letters, words, sentences);
    printf("grade : %i\n", index);
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

// Coleman-Liau指数
int compute_coleman_liau(int letters, int words, int sentences)
{
    float l = compute_l(words, letters);
    float s = compute_s(words, sentences);
    int index = round(0.0588 * l - 0.296 * s - 15.8);
    return index;
}

// 100語あたりの平均文字数
float compute_l(int words, int letters)
{
    float f = 100.0 / words;
    float l = (letters * f) / 100;
    return l;
}

// 100語あたりの平均文章数
float compute_s(int words, int sentences)
{
    float f = 100.0 / words;
    float s = (sentences * f) / 100;
    return s;
}