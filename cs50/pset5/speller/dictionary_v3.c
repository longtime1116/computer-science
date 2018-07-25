// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"

node *g_hasht[HASH_SIZE];
int g_word_num;

static int hash_func(char *word);

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

    node *head = g_hasht[hash_func(lower_word)];
    node *cur;

    if (head == NULL)
    {
        return false;
    }
    for (cur = head; cur->next != NULL; cur = cur->next)
    {
        if (strcmp(cur->word, lower_word) == 0)
        {
            return true;
        }
    }
    if (strcmp(cur->word, lower_word) == 0)
    {
        return true;
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
    int hash_value;

    while(fgets(word, LENGTH + 1, file) != NULL)
    {
        if (strlen(word) == 1)
        {
            continue;
        }

        word[strlen(word) - 1] = '\0';


        node **target = NULL;
        hash_value = hash_func(word);

        if (g_hasht[hash_value] == NULL)
        {
            target = &g_hasht[hash_value];
        }
        else
        {
            node *head = g_hasht[hash_value];
            node *current;
            bool need_insert = true;

            for (current = head; current->next != NULL; current = current->next)
            {
                if (strcmp(word, current->word) == 0)
                {
                    need_insert = false;
                    break;
                }
            }

            if (!need_insert)
            {
                continue;
            }

            target = &current->next;;
        }

        *target = malloc(sizeof(node));
        strcpy((*target)->word, word);
        (*target)->next = NULL;
        g_word_num++;
    }

    fclose(file);
    return true;
}
static int hash_func(char *word)
{
    unsigned long long int val = 0;
    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        val += word[i];
        val += (val << 10);
        val ^= (val >> 6);

    }
    val += val << 3;
    val ^= val >> 11;
    val += val << 15;

    return (int)(val % HASH_SIZE);
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return g_word_num;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        node *head = g_hasht[i];
        node *cur, *next;

        if (head == NULL)
        {
            continue;
        }

        for (cur = head; cur->next != NULL; cur = next)
        {
            next = cur->next;
            free(cur);
        }
        free(cur);
    }
    return true;
}
