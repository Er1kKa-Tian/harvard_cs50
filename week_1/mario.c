#include <stdio.h>
#include <cs50.h>

// Name function first, so the compiler knows that they exist
int get_size(void);
void print_grid(int size);

// Main
int main(void)
{
    // Get size of grid
    int n = get_size();

    // Print grid
    print_grid(n);
}

// Define function get_size
int get_size(void) // output name(input)
{
    int n; // Only declare, not assign value
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1); // Use a "do-while" loop to get value
        // In the 1st time, c first excuate do{} before examine while() condtions
        //Python don't have this
    return n;
}

// Define function print_grid
void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}