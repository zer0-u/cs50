#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

    uint8_t block[BLOCK_SIZE];
    while (fread(block, BLOCK_SIZE, 1, memory))
    {
        if (block[0] == 0xff)
        {
            printf("%i ", block[0]);
        }
    }

    printf("\n");
    // 後片付け
    fclose(memory);
}