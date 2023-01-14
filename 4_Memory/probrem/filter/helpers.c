#include "helpers.h"
#include <math.h>
#include <cs50.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            RGBTRIPLE pixel = image[h][w];
            BYTE blue = pixel.rgbtBlue;
            BYTE green = pixel.rgbtGreen;
            BYTE red = pixel.rgbtRed;
            int average = round((blue + green + red) / 3.0);
            image[h][w].rgbtBlue = average;
            image[h][w].rgbtGreen = average;
            image[h][w].rgbtRed = average;
        }
    }
}

int adjust(int value);

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            RGBTRIPLE pixel = image[h][w];
            BYTE blue = pixel.rgbtBlue;
            BYTE green = pixel.rgbtGreen;
            BYTE red = pixel.rgbtRed;
            BYTE sepiaBlue = adjust(round(0.272 * red + 0.534 * green + 0.131 * blue));
            BYTE sepiaGreen = adjust(round(0.349 * red + 0.686 * green + 0.168 * blue));
            BYTE sepiaRed = adjust(round(0.393 * red + 0.769 * green + 0.189 * blue));
            image[h][w].rgbtBlue = sepiaBlue;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtRed = sepiaRed;
        }
    }
}

int adjust(int value)
{
    if (value > 255)
    {
        return 255;
    }
    return value;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int max_index = width - 1;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0, half = width / 2; w < half; w++)
        {
            int opposite = max_index - w;
            RGBTRIPLE temp = image[h][w];
            image[h][w] = image[h][opposite];
            image[h][opposite] = temp;
        }
    }
}

bool inside(int h, int w, int height, int width);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*original)
    [width] = calloc(height, width * sizeof(RGBTRIPLE));

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            original[h][w].rgbtBlue = image[h][w].rgbtBlue;
            original[h][w].rgbtGreen = image[h][w].rgbtGreen;
            original[h][w].rgbtRed = image[h][w].rgbtRed;
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {

            int blueSum = 0;
            int greenSum = 0;
            int redSum = 0;
            int count = 0;
            for (int sh = h - 1; sh < h + 2; sh++)
            {
                for (int sw = w - 1; sw < w + 2; sw++)
                {
                    if (inside(sh, sw, height, width))
                    {
                        blueSum += original[sh][sw].rgbtBlue;
                        greenSum += original[sh][sw].rgbtGreen;
                        redSum += original[sh][sw].rgbtRed;
                        count++;
                    }
                }
            }
            int blueAverage = round(blueSum / count * 1.0);
            int greenAverage = round(greenSum / count * 1.0);
            int redAverage = round(redSum / count * 1.0);
            image[h][w].rgbtBlue = blueAverage;
            image[h][w].rgbtGreen = greenAverage;
            image[h][w].rgbtRed = redAverage;
        }
    }
    free(original);
}

bool inside(int h, int w, int height, int width)
{
    return (h >= 0 && h <= (height - 1)) &&
           (w >= 0 && w <= (width - 1));
}