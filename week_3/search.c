#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Linear Search for Integers
/*
int main(void)
{
    int numbers[7] = {20, 500, 10, 5, 100, 114514, 50};
    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
*/

// Linear Search for Strings

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon"};
    string s = get_string("String: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0; // This "return" will stop the programme once excuted
        }
    }
    printf("Not found\n");
    return 1;
}
