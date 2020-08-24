// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

int word_count = 0;
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cursor = table[hash(word)];
    if(table[hash(word)] != NULL)
    {
        while(cursor != NULL)
        {
            if(strcasecmp(cursor->word, word) == 0)
            {
                return true;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int i = (int) tolower(word[0]) - 97;
    return i;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dic
    FILE *input = fopen(dictionary, "r");
    // Creating a buffer
    char buffer[LENGTH + 1];
    // Check for errors
    if (input == NULL)
    {
        return false;
    }

    // Reading the file
    while (fscanf(input, "%s", buffer) != EOF)
    {
        // Creating Nodes
        node *n = malloc(sizeof(node));
        // Safety Check
        if (n == NULL)
        {
            return false;
        }
        // Copy the word
        strcpy(n->word, buffer);
        // Next
        n->next = table[hash(buffer)];
        // Set new beginning of list
        table[hash(buffer)] = n;

        ++word_count;
    }
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; ++i)
    {
        while (table[i] != NULL)
        {
            node *temp = table[i];

            table[i] = table[i]->next;

            free(temp);
        }
    }
    return true;
}
