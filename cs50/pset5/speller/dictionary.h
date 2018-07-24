// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define ALPHABET_NUM 26
#define APOSTOROFY_NUM 27
#define INDEX_OF(W) ( W[0] == '\'' ? APOSTOROFY_NUM - 1 : W[0] - 'a')

typedef struct node
{
    bool is_end;
    struct node *hasht[ALPHABET_NUM];
} node;

// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
void register_word(node *hasht[], char *word);
bool is_word_included(node **hasht, const char *word);

#endif // DICTIONARY_H
