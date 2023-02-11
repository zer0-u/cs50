// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// Loads dictionary into memory, returning true if successful, else false
// 辞書ファイルに載っている単語を全て読み込み、ハッシュテーブル等のデータ構造に収める
// 読み込みに成功したらtrue、失敗したらfalse
bool load(const char *dictionary)
{
    // TODO
    return false;
}

// Hashes word to a number
// 引数のwordに対応したハッシュ値を返す
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
