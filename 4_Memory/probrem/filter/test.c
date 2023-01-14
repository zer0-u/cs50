#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

int main(int argc, char *argv[])
{
    // (編集) テストしたい関数の種類
    char filter = 'b';

    // (編集) テストする画像の高さと幅
    int height = 0;
    int width = 0;

    RGBTRIPLE(*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));

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


    // 後片付け
    free(image);
    return 0;
}
