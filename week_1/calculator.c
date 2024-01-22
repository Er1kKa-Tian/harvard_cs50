# include <stdio.h>
# include <cs50.h>

/*
int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%i\n", x + y);
}
*/

// This calculator will not work properly when x = 2000000000, y = 2000000000 --- an integer overflow
// The biggest int we can represent in RAM is 2^31 (about 2 billion) as 1 digit is used to represents +-

// We can use this instead
// long extends to 64 bits
int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    printf("x+y is: %li\n", x + y);
    float z = (float) x / (float) y; // We need to convert both x,y to float (format casting)
    printf("x/y is: %.20f\n", z); // Print 20 digits and we can see "floating-point imprecision"
    // Similarily, we can use "double" to have more precise, but still limited,  answers
}