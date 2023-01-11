// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Copy header from input file to output file
    int uint8size = sizeof(uint8_t);
    for (int i = 0; i < HEADER_SIZE; i++)
    {
        uint8_t h;
        fread(&h, uint8size, uint8size, input);
        fwrite(&h, uint8size, uint8size, output);
    }

    // Read samples from input file and write updated data to output file
    int16_t b;
    int omit = HEADER_SIZE;
    int int16size = sizeof(int16_t);
    while (fread(&b, int16size, int16size, input))
    {
        if (omit < 0)
        {
            b = b * factor;
            fwrite(&b, int16size, int16size, output);
        }
        omit--;
    }

    // Close files
    fclose(input);
    fclose(output);
}
