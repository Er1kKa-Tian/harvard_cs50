#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check validity of input
    if (argc != 2)
    {
        printf("Usage: ./reciver filename\n");
        return 1;
    }

    // open raw file
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("unable to read file");
        return 2;
    }

    int counter = 0;
    uint8_t buffer[512];
    char output_name[8];
    FILE *outptr = NULL;
    while (1)
    {
        // read a block
        if (fread(buffer, 512, 1, inptr) < 1) // inptr will resume its progress
        {
            if (outptr != NULL) // close opened output file
            {
                fclose(outptr);
            }
            fclose(inptr); // close opened input file
            return 0;      // reach the end of file
        }

        // search for JPEG signature
        bool flag_found = (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef));

        // if found, write a file, until find the next one
        if (flag_found)
        {
            if (outptr != NULL) // close opened output file
            {
                fclose(outptr);
            }
            sprintf(output_name, "%03d.jpg", counter); // update counter name
            outptr = fopen(output_name, "a");
            fwrite(buffer, 512, 1, outptr);
            counter++;
        }
        else if (outptr != NULL)
        {
            fwrite(buffer, 512, 1, outptr);
        }
    }
}
