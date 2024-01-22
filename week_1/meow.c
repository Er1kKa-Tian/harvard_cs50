#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i=0;
    while (i < 3) //While loop approach
    {
        printf("Meow!\n");
        i++; // equivalent: counter+=1 or counter = counter + 1
        // Convention: start from 0, loop while < desired number
    }
    for (int counter = 0; counter < 3; counter++) //For loop approach: for (counter; boolean condition; interation)
    {
        printf("Meow!!!\n");
    }
    while (true) // or while (1)
    {
        printf("Forever Meow!!!\n");
    }
}