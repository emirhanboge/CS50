#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Emirhan Boge 
// 8/5/2020 2.54 PM

int main(void)
{
    int count_letters = 0, count_words = 1, count_sentences = 0;
    string text = get_string("Text: \n");

    for (int i = 0; i < strlen(text); ++i)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) // Letter Count
        {
            ++count_letters;
        }
        else if (text[i] == ' ') // Word Count
        {
            ++count_words;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!') // Sentence Count
        {
            ++count_sentences;
        }
    }

    // The Coleman-Liau Formula
    float L = ((float)count_letters * 100) / (float)count_words;
    float S = ((float)count_sentences * 100) / (float)count_words;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int output = round(index);

    // Printing the output
    if (output > 16)
    {
        printf("Grade 16+\n");
    }
    else if (output < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", output);
    }
}
