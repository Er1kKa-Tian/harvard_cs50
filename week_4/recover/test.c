#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./receiver filename\n");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "rb");
    if (inptr == NULL)
    {
        perror("Unable to read file");
        return 2;
    }

    int counter = 0;
    uint8_t buffer[512];
    char output_name[8]; // Array to hold the output file name

    FILE *outptr = NULL;

    while (1)
    {
        if (fread(buffer, 512, 1, inptr) != 1)
        {
            if (feof(inptr))
            {
                // End of file reached
                break;
            }
            else
            {
                perror("Error reading from input file");
                return 3;
            }
        }

        bool flag_found = (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef));

        if (flag_found)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            sprintf(output_name, "%03d.jpg", counter);
            outptr = fopen(output_name, "wb");
            if (outptr == NULL)
            {
                perror("Unable to create output file");
                return 4;
            }

            counter++;
        }

        if (outptr != NULL)
        {
            fwrite(buffer, 512, 1, outptr);
        }
    }

    if (outptr != NULL)
    {
        fclose(outptr);
    }

    fclose(inptr);
    return 0;
}
