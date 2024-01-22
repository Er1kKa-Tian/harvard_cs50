#include <stdio.h>
#include <cs50.h>
#include <string.h> // strings library

int main(void)
{
    string name = get_string("What's your name?");

    int n = 0;
    while (name[n] != '\0') // Strings ends with '\0'
    {
        n++;
    }
    printf("%i\n", n);

    // Easier way using a library
    printf("%i\n", (int) strlen(name));

}