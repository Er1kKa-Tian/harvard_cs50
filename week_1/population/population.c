#include <cs50.h>
#include <stdio.h>

// Declare functions
int get_start_size(void);
int get_end_size(int start_size);
int calculate_time(int start, int end);

// Main
int main(void)
{
    // TODO: Prompt for start size
    int start_size = get_start_size();

    // TODO: Prompt for end size
    int end_size = get_end_size(start_size);

    // TODO: Calculate number of years until we reach threshold

    int years = calculate_time(start_size, end_size);

    // TODO: Print number of years

    printf("Years: %i\n", years);
}

// Function to get start size
int get_start_size(void)
{
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);
    return start_size;
}

// Function to get end size
int get_end_size(int start_size)
{
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);
    return end_size;
}

// Function to calculate time
int calculate_time(int start, int end)
{
    int count = start;
    int years = 0;
    while (count < end)
    {
        count = count + count / 3 - count / 4;
        years++;
    }
    return years;
}