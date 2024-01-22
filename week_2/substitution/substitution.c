#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Declare functions and global variables
int encode(string plain_text, string key);
char aplhabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Main
int main(int argc, string argv[])
{
    char key[] = "00000000000000000000000000";
    char temp_char;

    // Initiate (check input key is valid)
    if (argc != 2) // one command + one argument
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int length = strlen(argv[1]);
        if (length != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            char key_ordered[] = "00000000000000000000000000";
            for (int i = 0; i < 26; i++)
            {
                temp_char = toupper(argv[1][i]);
                if ((int) temp_char >= 65 && (int) temp_char <= 90)
                {
                    key_ordered[(int) temp_char - 65] = temp_char;
                    key[i] = (int) temp_char - (int) aplhabet[i];
                }
                else
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }
            if (strcmp(key_ordered, aplhabet) == 0)
            {
                // printf("Key (%s) is valid.\n", key); // for debugging
            }
            else
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
        }
    }

    string plain_text = get_string("plaintext: ");
    encode(plain_text, key);

    // printf("%s/n", key);
}

// Encoding function

int encode(string plain_text, string key)
{
    char cipher_text[strlen(plain_text) + 1];
    int position_indicator;

    printf("ciphertext: ");

    for (int i = 0, L = strlen(plain_text); i < L; i++)
    {
        if (isalpha(plain_text[i]) != 0)
        {
            for (int j = 0; j < 26; j++)
            {
                if (toupper(plain_text[i]) == aplhabet[j])
                {
                    position_indicator = j;
                }
            }
            cipher_text[i] = (char) ((int) plain_text[i] + (int) key[position_indicator]);
        }
        else
        {
            cipher_text[i] = plain_text[i];
        }
        printf("%c", cipher_text[i]);
    }

    printf("\n");

    return 0;
}