#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool check(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];

        if (check(key))
        {
            int val = atoi(key);
            string plaintext = get_string("plaintext: "); // Getting the input

            // Printing the ciphertext
            printf("ciphertext: ");
            for (int i = 0; i < strlen(plaintext); ++i)
            {
                if (plaintext[i] >= 'a' && plaintext[i] <= 'z') // if char is lower
                {
                    printf("%c", (((plaintext[i] - 97) + val) % 26) + 97);
                }
                else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') // if char is upper
                {
                    printf("%c", (((plaintext[i] - 65) + val) % 26) + 65);
                }
                else
                {
                    printf("%c", plaintext[i]);
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("./caesar key\n");
        return 1;
    }
}
// Digit check for key
bool check(string key)
{
    for (int i = 0; i < strlen(key); ++i)
    {
        if (key[i] < '0' || key[i] > '9')
        {
            return false;
        }
    }
    return true;
}