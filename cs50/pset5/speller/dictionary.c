// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"


char **table;
int word_num;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int from = 0;
    int to = word_num - 1;
    char lower_word[strlen(word) + 1];

    strcpy(lower_word, word);
    for(int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            lower_word[i] -= 'A' - 'a';
        }
    }

    while(1)
    {
        if (from > to)
        {
            break;
        }

        int index = (from + to) / 2;
        int result = strcmp(lower_word, table[index]);

        if (result > 0)
        {
            from = index + 1;
            continue;
        }
        else if (result < 0)
        {
            to = index - 1;
            continue;
        }
        else
        {
            return true;
        }

    }

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
    int count = 0;

    while(fgets(word, LENGTH + 1, file) != NULL)
    {
        if (strlen(word) == 1)
        {
            continue;
        }
        count++;
    }

    table = malloc(sizeof(char *) * count);
    word_num = count;

    rewind(file);
    int i = 0;
    while(fgets(word, LENGTH + 1, file) != NULL)
    {
        if (strlen(word) == 1)
        {
            continue;
        }

        word[strlen(word) - 1] = '\0';

        char *str = malloc(strlen(word) + 1);
        strcpy(str, word);
        table[i] = str;
        i++;
    }
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_num;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < word_num; i++)
    {
        free(table[i]);
    }
    free(table);
    return true;
}
