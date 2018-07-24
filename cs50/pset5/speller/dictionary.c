// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    (void)word;
    return false;
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
    node head;
    head.is_end = false;

    while(fgets(word, LENGTH + 1, file) != NULL)
    {
        if (strlen(word) == 1)
        {
            continue;
        }
        word[strlen(word) - 1] = '\0';

        register_word(head.hasht, word);
        printf("\n");
    }

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    return true;
}

void register_word(node **hasht, char *word)
{
    node *current = malloc(sizeof(node));
    hasht[INDEX_OF(word)] = current;

    if (strlen(word) == 1)
    {
        current->is_end = true;
        printf("%c", word[0]);
    }
    else
    {
        printf("%c", word[0]);
        register_word(current->hasht, &word[1]);
    }
    return;
}
