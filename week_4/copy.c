#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("String: ");
    // stop the program if the memory cannot fit the string
    if (s == NULL)
    {
        return 1;
    }

/*
    // Only copy the pointer
    char *t = s;
    // Note that this will also change the origin string, because s,t just contain the same pointer
    if (strlen(t) > 0)
    {
        t[0] = toupper(s[0]);
    }
    printf("s: %s\n", s);
    printf("t: %s\n", t);
*/

    // Correct method
    char *cpstring = malloc(strlen(s) + 1); // we need 1 additional byte to store '\0'
    if (cpstring == NULL)
    {
        return 1;
    }
    for (int i = 0, j = strlen(s) + 1; i < j; i++)
    {
        cpstring[i] = s[i];
    }
    if (strlen(cpstring) > 0)
    {
        cpstring[0] = toupper(s[0]);
    }
    printf("s: %s\n", s);
    printf("cpstring: %s\n", cpstring);
    free(cpstring); // we must free memories after malloc them

    // You can use "strcpy(t, s)" instead

}
