//슬라이드 35
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
int main()
{
    int i, *ptr;
    int sale[2][4] = {{63, 84, 140, 130},
                      {157, 209, 251, 312}}; // 2차원 배열의 초기화
    ptr = &sale[0][0];
    for (i = 0; i < 8; i++)
    {
        printf("\n addresss : %u sale %d= %d", ptr, i, *ptr);
        ptr++;
    }
    getchar();

    return 0;
}
