#include <stdio.h>
#include "helpers.h"

/* makeは使えないので以下のコマンドでコンパイルを行う

clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -lm -o test test.c helpers.c

*/

int main(int argc, char *argv[])
{

    printf("test start\n");
    // (編集) テストしたい関数の種類
    char filter = 'b';

    // (編集) テストする画像の高さと幅
    int height = 3;
    int width = 3;

    // (固定) 画像を模した配列を用意
    RGBTRIPLE image[height][width];

    // (編集)imageに値を詰める
    image[0][0].rgbtBlue = 10;
    image[0][0].rgbtGreen = 20;
    image[0][0].rgbtRed = 30;

    image[0][1].rgbtBlue = 40;
    image[0][1].rgbtGreen = 50;
    image[0][1].rgbtRed = 60;

    image[0][2].rgbtBlue = 70;
    image[0][2].rgbtGreen = 80;
    image[0][2].rgbtRed = 90;

    image[1][0].rgbtBlue = 110;
    image[1][0].rgbtGreen = 130;
    image[1][0].rgbtRed = 140;

    image[1][1].rgbtBlue = 120;
    image[1][1].rgbtGreen = 140;
    image[1][1].rgbtRed = 150;

    image[1][2].rgbtBlue = 130;
    image[1][2].rgbtGreen = 150;
    image[1][2].rgbtRed = 160;

    image[2][0].rgbtBlue = 200;
    image[2][0].rgbtGreen = 210;
    image[2][0].rgbtRed = 220;

    image[2][1].rgbtBlue = 220;
    image[2][1].rgbtGreen = 230;
    image[2][1].rgbtRed = 240;

    image[2][2].rgbtBlue = 240;
    image[2][2].rgbtGreen = 250;
    image[2][2].rgbtRed = 255;

    // (固定) テスト対象の関数を呼び出す
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

    // (固定) 処理を終えた後のimageを出力する
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            RGBTRIPLE pixel = image[h][w];
            BYTE blue = pixel.rgbtBlue;
            BYTE green = pixel.rgbtGreen;
            BYTE red = pixel.rgbtRed;
            printf(" (%i, %i, %i) ", blue, green, red);
        }
        printf("\n");
    }

    printf("test end\n");
    return 0;
}
