#include <cs50.h>
#include <stdio.h>

// Declare function names
int get_height(void);
int print_pyramid(int height);

// Main
int main(void)
{
    int height = get_height();
    print_pyramid(height);
}

// Function to get input height
int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

// Function to print pyramid
int print_pyramid(int height)
{
    for (int row = 0; row < height; row++)
    {
        for (int i = 0; i < height - row - 1; i++)
        {
            printf(" ");
        }
        for (int j = 0; j < row + 1; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k < row + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0; // Non-void function must have a return value
}