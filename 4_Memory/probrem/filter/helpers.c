#include "helpers.h"

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
            BYTE sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            BYTE sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            BYTE sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
