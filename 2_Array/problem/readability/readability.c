#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int compute_coleman_liau(int letters, int words, int sentences);

int main(void)
{
    string input = get_string("Text: ");
    int letters = count_letters(input);
    int words = count_words(input);
    int sentences = count_sentences(input);
    int grade = compute_coleman_liau(letters, words, sentences);

    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
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
    // LとSについてめちゃくちゃ難しく考えすぎた
    // wordsで割る＝1単語あたりの数を出して100倍するだけだった
    // wikipediaでちょっとカンニングした
    // https://en.wikipedia.org/wiki/Coleman%E2%80%93Liau_index
    // wordsで割る時に既に切り捨てられていることにしばらく気付かなかった
    float l = (letters / (float)words) * 100;
    float s = (sentences / (float)words) * 100;
    int grade = round(0.0588 * l - 0.296 * s - 15.8);
    return grade;
}
