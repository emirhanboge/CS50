#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            float avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.000); // Calculate RGB average

            // Set the new RGB Values
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; ++h)
    {
        for (int w = 0; w < width; ++w)
        {
            // Finding sepia values
            int sred = round(0.393 * image[h][w].rgbtRed + 0.769 * image[h][w].rgbtGreen + 0.189 * image[h][w].rgbtBlue);
            int sgreen = round(0.349 * image[h][w].rgbtRed + 0.686 * image[h][w].rgbtGreen + 0.168 * image[h][w].rgbtBlue);
            int sblue = round(0.272 * image[h][w].rgbtRed + 0.534 * image[h][w].rgbtGreen + 0.131 * image[h][w].rgbtBlue);

            // Red Check
            if (sred > 255)
            {
                sred = 255;
            }
            else if (sred < 0)
            {
                sred = 0;
            }
            // Green Check
            if (sgreen > 255)
            {
                sgreen = 255;
            }
            else if (sgreen < 0)
            {
                sgreen = 0;
            }
            // Blue Check
            if (sblue > 255)
            {
                sblue = 255;
            }
            else if (sblue < 0)
            {
                sblue = 0;
            }

            image[h][w].rgbtRed = sred;
            image[h][w].rgbtGreen = sgreen;
            image[h][w].rgbtBlue = sblue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width / 2; ++j)
        {
            // Temporary Values
            int first = image[i][j].rgbtRed;
            int sec = image[i][j].rgbtGreen;
            int thr = image[i][j].rgbtBlue;

            // Changing from 0
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            // Changing from last
            image[i][width - j - 1].rgbtRed = first;
            image[i][width - j - 1].rgbtGreen = sec;
            image[i][width - j - 1].rgbtBlue = thr;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Creating copy
    RGBTRIPLE temp[height][width];
    for (int h = 0; h < height; ++h)
    {
        for (int w = 0; w < width; ++w)
        {
            temp[h][w] = image[h][w];
        }
    }
    for (int h = 0; h < height; ++h)
    {
        for (int w = 0; w < width; ++w)
        {
            int sum_blue = 0, sum_green = 0, sum_red = 0;
            float count = 0;

            for (int i = -1; i <= 1; ++i)
            {
                for (int j = -1; j <= 1; ++j)
                {
                    if (w + j !=  -1 && w + j != width && h + i != height && h + i != -1)
                    {
                        // Assigning the new values
                        sum_blue += temp[h + i][w + j].rgbtBlue;
                        sum_green += temp[h + i][w + j].rgbtGreen;
                        sum_red += temp[h + i][w + j].rgbtRed;
                        // Incrementing by one for every connected pixel
                        ++count;
                    }
                }
            }
            image[h][w].rgbtBlue = round(sum_blue / count);
            image[h][w].rgbtGreen = round(sum_green / count);
            image[h][w].rgbtRed = round(sum_red / count);
        }
    }
    return;
}
