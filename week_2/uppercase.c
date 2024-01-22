#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i]))
        {
            s[i] = s[i] - 32; // ASCII: lower case - 32 = upper case
        }
        // Alternative: s[i] = toupper(s[i]); // This uses ctype library
    }
    printf("%s\n", s);
}