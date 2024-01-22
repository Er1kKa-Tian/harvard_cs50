#include <stdio.h>
#include <cs50.h>

int main(void){
    string first_name = get_string("What's your first name? ");
    printf("Hello, %s!\n", first_name); //We use a placeholder and plug answer -> %s
    //Surely you can use 2 %s and 2 additional arguments
    string last_name = get_string("What's your last name? ");
    printf("Hello, %s %s!\n", first_name, last_name);
}