#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

const int BLOCK_SIZE = 512;
const int FILENAME_SIZE = 8;

bool start_jpeg(uint8_t block[]);

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
    int filenum = 0;
    // TODO string型に置き換えるかもしれない
    char filename[FILENAME_SIZE];
    bool started = false;
    while (fread(block, BLOCK_SIZE, 1, memory))
    {
        if (start_jpeg(block))
        {
            // 既にファイルが開いている場合は閉じる
            if (started)
            {
                printf("file closed.\n");
            }
            // 新しいファイルを開く
            sprintf(filename, "%03i.jpg", filenum);
            filenum++;
            printf("%s\n", filename);
            started = true;
        }
        else
        {
            if (started)
            {
                // ファイルが開いている場合は書き込む
                printf("*");
            }
            else
            {
                // そうでない場合は何もしない
                printf("aaaaa");
            }
        }
    }
    printf("\n");

    // 後片付け
    fclose(memory);
}

bool start_jpeg(uint8_t block[])
{
    return block[0] == 0xff &&
           block[1] == 0xd8 &&
           block[2] == 0xff &&
           (block[3] & 0xf0) == 0xe0;
}