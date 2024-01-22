#include <stdio.h>
#include <cs50.h>

int main(void){
    int x = get_int("Provide an integer x~ ");
    int y = get_int("Provide an integer y~ ");
    if (x<y)
    {
        printf("x is smaller than y!\n");
    }
    else if (x==y)
    {
        printf("x is equal to y!\n");
    }
    else
    {
        printf("x is larger than y!\n");
    }
}