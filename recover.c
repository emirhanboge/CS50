#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    // Command-Line Arguement Check
    if (argc != 2)
    {
        printf("Invalid arguement!\n");
        return 1;
    }

    // Opening Memory Card File
    char *jpeg = argv[1];
    FILE *file = fopen(jpeg, "r");

    // Checking if file is readible
    if (file == NULL)
    {
        printf("Could not open input file\n");
        return 2;
    }

    // Creating a buffer
    unsigned char buffer[512]; // 512 == Buffer size

    char f[10];

    int file_count = 0; // Opened file count
    int jpeg_count = 0; // To keep track of jpeg count
    FILE *newFile; // New File with JPEGS

    // Loop over the file
    while (fread(buffer, 512, 1, file) != 0)
    {
        // Check if current file is JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1 || buffer[3] == 0xe2 || buffer[3] == 0xe3 || buffer[3] == 0xe4 || buffer[3] == 0xe5 || buffer[3] == 0xe6 || buffer[3] == 0xe7 || buffer[3] == 0xe8 || buffer[3] == 0xe9 || buffer[3] == 0xea || buffer[3] == 0xeb || buffer[3] == 0xec || buffer[3] == 0xed || buffer[3] == 0xee || buffer[3] == 0xef))
        {
            // If a file is not open
            if (file_count == 0)
            {
                // Open a new file for writing
                file_count = 1;
                sprintf(f, "%0.3d.jpg", jpeg_count);
                newFile = fopen(f, "w");
                jpeg_count += 1;
            }
            // If a file is open previously
            else if (file_count == 1)
            {
                // Close the old file to create a new one
                fclose(newFile);

                // Open a file for appending
                file_count = 1;
                sprintf(f, "%0.3d.jpg", jpeg_count);
                newFile = fopen(f, "a");
                jpeg_count += 1;
            }

            fwrite(buffer, 512, 1, newFile);
        }
        // If it is not a JPEG file
        else
        {
            // Since this is not a JPEG file we can write it to opened file
            if (file_count != 0)
            {
                fwrite(buffer, 512, 1, newFile);
            }
        }
    }

    fclose(file);
    fclose(newFile);

    return 0;
}
