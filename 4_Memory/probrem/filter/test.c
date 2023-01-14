#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

int main(int argc, char *argv[])
{
    printf("test start\n");
    // (編集) テストしたい関数の種類
    char filter = 'b';

    // (編集) テストする画像の高さと幅
    int height = 0;
    int width = 0;

    RGBTRIPLE(*image)
    [width] = calloc(height, width * sizeof(RGBTRIPLE));

    // imageに値を詰める

    // image[0][0]

    // テスト対象の関数を呼び出す
    switch (filter)
    {
    // Blur
    case 'b':
        blur(height, width, image);
        break;

    // Grayscale
    case 'g':
        grayscale(height, width, image);
        break;

    // Reflection
    case 'r':
        reflect(height, width, image);
        break;

    // Sepia
    case 's':
        sepia(height, width, image);
        break;
    }

    // imageが想定通りか出力する
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            RGBTRIPLE pixel = image[h][w];
            BYTE blue = pixel.rgbtBlue;
            BYTE green = pixel.rgbtGreen;
            BYTE red = pixel.rgbtRed;
            printf(" %i, %i, %i ", blue, green, red);
        }
        printf("\n");
    }

    // 後片付け
    free(image);
    printf("test end\n");
    return 0;
}
