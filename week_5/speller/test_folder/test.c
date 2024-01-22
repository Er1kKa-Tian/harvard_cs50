#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cs50.h>

unsigned int hash(const char *word);

int main(void)
{
    while(1)
    {
        char *input = get_string("String: ");
        printf("Hash value: %i", hash(input));
    }
}

unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int word_length = strlen(word);
    // cut tail <=3 or >=12
    if (word_length <=3)
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
