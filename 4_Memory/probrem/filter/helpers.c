#include "helpers.h"
#include "math.h"

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

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0, half = width / 2; w < half; w++)
        {
            RGBTRIPLE u1 = image[h - 1][w - 1];
            RGBTRIPLE u2 = image[h - 1][w];
            RGBTRIPLE u3 = image[h - 1][w + 1];

            RGBTRIPLE s1 = image[h][w - 1];
            RGBTRIPLE s2 = image[h][w];
            RGBTRIPLE s3 = image[h][w + 1];

            RGBTRIPLE d1 = image[h + 1][w - 1];
            RGBTRIPLE d2 = image[h + 1][w];
            RGBTRIPLE d3 = image[h + 1][w + 1];
        }
    }
}
