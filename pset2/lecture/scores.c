// 2022/11/03
#include <stdio.h>
#include <cs50.h>

const int TOTAL = 3;

int main(void)
{
    int scores[TOTAL];
    for (int i = 0; i < TOTAL; i++)
    {
        scores[i]=get_int("Score : ");
    }

    printf("Average: %d\n", (scores[0] + scores[1]+scores[2])/TOTAL);
}

// float calculate_average