// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 10;

// Hash table
node *table[N];

// Recursive check (added)

bool recursive_check(const char *word, node *ptr_node)
{
    if (ptr_node == NULL)
    {
        return false;
    }
    if (strcmp(word, ptr_node->word) == 0)
    {
        return true;
    }
    else if (ptr_node->next == NULL)
    {
        return false;
    }
    else
    {
        return recursive_check(word, ptr_node->next);
    }
}

char *str_tolower(char *word_tmp)
{
    for (int i = 0; i < (LENGTH + 1); i++)
    {
        if (word_tmp[i] == '\0')
        {
            break;
        }
        word_tmp[i] = tolower(word_tmp[i]);
    }
    return word_tmp;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char *word_tmp = malloc(sizeof(char[LENGTH + 1]));
    strcpy(word_tmp, word);
    word_tmp = str_tolower(word_tmp);
    bool flag = recursive_check(word_tmp, table[hash(word)]);
    free(word_tmp);
    return flag;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int word_length = strlen(word);
    // cut tail <=3 or >=12
    if (word_length <= 3)
    {
        word_length = 3;
    }
    else if (word_length >= 12)
    {
        word_length = 12;
    }
    // normalise length to be [0,9]
    word_length = word_length - 3;
    // add a-z to each length category
    return word_length * 26 + toupper(word[0]) - 'A'; //[0 - 259]

    // return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // initialise hash table to NULL
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    // load
    FILE *ptr_dict = fopen(dictionary, "r");
    node *temp = NULL;
    char temp_char;
    int counter = 0;
    while (fread(&temp_char, sizeof(char), 1, ptr_dict))
    {
        if (temp == NULL)
        {
            temp = malloc(sizeof(node));
            temp->next = NULL;
        }
        if (temp_char == '\n')
        {
            // finish current node creation
            temp->word[counter] = '\0';
            temp->next = table[hash(temp->word)];
            table[hash(temp->word)] = temp;
            // reset for the next node
            temp = NULL;
            counter = 0;
        }
        else
        {
            temp->word[counter] = temp_char;
            counter++;
        }
    }
    fclose(ptr_dict);
    return true;

    // return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int number = 0;
    for (int i = 0; i < 260; i++)
    {
        node *count_next = table[i];
        while (count_next != NULL)
        {
            number++;
            count_next = count_next->next;
        }
    }
    return number;
}

// Recursively free memory
void free_node(node *next_node)
{
    if (next_node->next == NULL)
    {
        free(next_node);
        return;
    }
    free_node(next_node->next);
    free(next_node);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < 260; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }
        free_node(table[i]);
    }
    return true;
    // return false;
}
