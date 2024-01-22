#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Declare Functions
int calculation(string input);
int print_result(int grade);

// Main
int main(void)
{
    string input = get_string("Text: ");
    int index = calculation(input);
    print_result(index);
}

// Function to calculate grade
int calculation(string input)
{
    float L = 0;
    float S = 0;
    float W = 1; // Word count starts from 1
    int total_length = strlen(input);
    int temp;
    for (int i = 0; i < total_length; i++)
    {
        temp = (int) toupper(input[i]);
        if (isalpha(input[i]))
        {
            L++;
        }
        else if (temp == 33 || temp == 46 || temp == 63)
        {
            S++;
        }
        else if (isblank(input[i]))
        {
            W++;
        }
        else
        {
            // pass
        }
    }
    L = 100 * L / W;
    S = 100 * S / W;

    int index = 0.0588 * L - 0.296 * S - 15.8 + 0.5; // +0.5 to round to the nearest integer
    return index;
}

// function to print result
int print_result(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    return 0;
}