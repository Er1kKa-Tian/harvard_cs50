#include <stdio.h>
#include <cs50.h>

// To demonstrate that strings are arrays of char

int main(void)
{
    string word[2];

    word[0] = "Hi!";
    word[1] = "Bye!";
    printf("%c%c%c\n", word[0][0], word[0][1], word[0][2]);
    printf("%c%c%c%c\n", word[1][0], word[1][1], word[1][2], word[1][3]);
}