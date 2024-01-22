#include <stdio.h>
#include <stdlib.h>

void swap_wrong(int a, int b);
void swap_correct(int *a, int *b);

int main(void)
{
    int a = 1;
    int b = 2;

    //pass by value will not work
    swap_wrong(a, b);
    printf("a is %i, b is %i\n", a, b);

    //we need to pass by reference
    swap_correct(&a, &b);
    printf("a is %i, b is %i\n", a, b);
}

void swap_wrong(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_correct(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
