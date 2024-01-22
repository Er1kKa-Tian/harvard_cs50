#include <stdio.h>
#include <cs50.h>

const int length = 3; // Declare length of the array (globally)
// Those configuation variables can be put on the top

float average(int array[]);

int main(void)
{
    int score[length];
    for (int i = 0; i < length; i++)
    {
        score[i] = get_int("Score: ");
    }
    printf("Average: %f\n", average(score));
}

float average(int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}