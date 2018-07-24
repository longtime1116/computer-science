// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"

node head = {false, {0}};
int word_count = 0;

static bool is_word_included(node **hasht, const char *word);
static void register_word(node **hasht, char *word);
static void free_hasht(node **hasht);

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char lower_word[strlen(word) + 1];

    strcpy(lower_word, word);
    for(int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            lower_word[i] -= 'A' - 'a';
        }
    }

    return is_word_included(head.hasht, lower_word);
}

static bool is_word_included(node **hasht, const char *word)
{
    if (hasht[INDEX_OF(word)] == NULL)
    {
        return false;
    }
    else
    {
        if (strlen(word) == 1)
        {
            return  hasht[INDEX_OF(word)]->is_end;
        }
        return is_word_included(hasht[INDEX_OF(word)]->hasht, &word[1]);
    }
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }

    char word[LENGTH + 1];

    while(fgets(word, LENGTH + 1, file) != NULL)
    {
        if (strlen(word) == 1)
        {
            continue;
        }

        word[strlen(word) - 1] = '\0';
        register_word(head.hasht, word);
    }
    fclose(file);

    return true;
}

static void register_word(node **hasht, char *word)
{
    node *current;
    if (hasht[INDEX_OF(word)] == NULL)
    {
        current = hasht[INDEX_OF(word)] = calloc(sizeof(node), 1);
    }
    else
    {
        current = hasht[INDEX_OF(word)];
    }

    if (strlen(word) == 1)
    {
        current->is_end = true;
        word_count++;
    }
    else
    {
        register_word(current->hasht, &word[1]);
    }
    return;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    free_hasht(head.hasht);
    return true;
}

static void free_hasht(node **hasht)
{
    for (int i = 0; i < APOSTOROFY_NUM; i++)
    {
        if (hasht[i] != NULL)
        {
            free_hasht(hasht[i]->hasht);
            free(hasht[i]);
        }
    }
}
