// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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

    while(fgets(word, LENGTH + 1, file) != NULL)
    {
        word[strlen(word) - 1] = '\0';
        printf("word: %s\n", word);
    }
    fclose(file);


    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
