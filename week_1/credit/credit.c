#include <cs50.h>
#include <stdio.h>

// Declare Functions
long get_cardnum(void);
int categorise(long cardnum);
int validate(int category, long cardnum);
int show(int result);

// Main
int main(void)
{
    long cardnum = get_cardnum();
    int category = categorise(cardnum);
    int result = validate(category, cardnum);
    show(result);
}

// Function to get input
long get_cardnum(void)
{
    long cardnum = get_long("Number: ");
    return cardnum;
}

// Function to categorise cards
int categorise(long cardnum)
{
    int category;
    if (cardnum - 4000000000000 < 0)
    {
        category = 0; // catetory = 0 "INVALID"
    }
    else if (cardnum - 5000000000000 < 0)
    {
        category = 1; // catetory = 1 "VISA"
    }
    else if (cardnum - 340000000000000 < 0)
    {
        category = 0;
    }
    else if (cardnum - 350000000000000 < 0)
    {
        category = 2; // catetory = 2 "AMEX"
    }
    else if (cardnum - 370000000000000 < 0)
    {
        category = 0;
    }
    else if (cardnum - 380000000000000 < 0)
    {
        category = 2; // catetory = 2 "AMEX"
    }
    else if (cardnum - 4000000000000000 < 0)
    {
        category = 0;
    }
    else if (cardnum - 5000000000000000 < 0)
    {
        category = 1;
    }
    else if (cardnum - 5100000000000000 < 0)
    {
        category = 0;
    }
    else if (cardnum - 5600000000000000 < 0)
    {
        category = 3; // catetory = 3 "MASTERCARD"
    }
    else
    {
        category = 0;
    }
    return category;
}

// Function to check validity
int validate(int category, long cardnum)
{
    int result = 0;
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
    }
    if (sum % 10 == 0)
    {
        result = category;
    }
    return result;
}

// Function to print out results
int show(int result)
{
    string name;
    if (result == 0)
    {
        name = "INVALID\n";
    }
    else if (result == 1)
    {
        name = "VISA\n";
    }
    else if (result == 2)
    {
        name = "AMEX\n";
    }
    else
    {
        name = "MASTERCARD\n";
    }
    printf("%s", name);
    return 0;
}