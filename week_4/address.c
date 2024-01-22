#include <stdio.h>

int main(void)
{
    int n = 114514;
    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);

    char *s = "lol";
    // printf is smart! looo;
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%s\n", s); // we don't need to "*s" because printf knows that, when given an address but required to print sth else, it should access that address; if you indeed put "*s", you will only get back a single character

    printf("%c\n", *(s+1));

    // print out substrings
    printf("%s\n", s+1);
    printf("%s\n", s+2);
}
