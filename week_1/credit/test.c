#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long cardnum = get_long("N: ");
    int count = 0;
    int sum = 0;
    while (cardnum > 0)
    {
        if (count % 2 == 0)
        {
            sum = sum + (cardnum % 10);
        }
        else
        {
            if ((cardnum % 10) < 5)
            {
                sum = sum + 2 * (cardnum % 10);
            }
            else
            {
                sum = sum + 1 + (2 * (cardnum % 10)) % 10;
            }
        }
        cardnum = cardnum / 10;
        count++;
        printf("%i, %li\n", sum, cardnum);
    }
    printf("%i\n", sum);
}