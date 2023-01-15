#include <stdio.h>
#include <stdlib.h>

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // 引数チェック
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // メモリーカードを開く
    FILE *memory = fopen(argv[1], "r");
    if (memory == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    byte b;

    while (fread(&b, int16size, 1, input))
    {
        b = b * factor;
        fwrite(&b, int16size, 1, output);
    }

}