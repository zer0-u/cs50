// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

unsigned int word_count = 0;



// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // ファイルを開く
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    // ファイルに載った文字列を読み込む
    char w[LENGTH + 1];
    while (fscanf(dict, "%s", w) != EOF)
    {
        // 単語1個分のメモリを確保する
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(dict);
            return false;
        }

        // size関数の戻り値に使うので単語数を数えておく
        word_count++;

        // strcpyを使って読み込んだ単語をnodeにコピーする
        strcpy(n->word, w);

        // 次のノードは今のところ未定なのでNULLを入れておく
        n->next = NULL;

        // 読み込んだ単語のハッシュ値を計算する
        int index = hash(w);

        // ハッシュ値に応じた場所に収納する
        // すでに要素がある場合は先頭をすげ替える
        node *top = table[index];

        if (top != NULL)
        {
            n->next = top;
        }
        table[index] = n;
    }

    // ファイルを閉じる
    fclose(dict);
    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}



// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // load関数の中で数えておいたのでここでの処理は不要
    return word_count;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    node *list = table[hash(word)];
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *current = table[i];
        while (current != NULL)
        {
            node *next = current->next;
            free(current);
            current = next;
        }
    }
    return true;
}
