#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char key_ordered[] = "00000000000000000000000000";
    key_ordered[0] = '1';
    printf("%s\n", key_ordered);
    printf("%i\n", (int) strcmp("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
}