//슬라이드9~14
//배열 값의 위치를 90도 이동 시키는 코드

#include <stdio.h>
int A[5][5]; //배열 선언
int B[5][5];
int rotate;
int x, y, k, h; //변수 선언

int main()
{
    k = 0;
    //배열 초기화(1행 1열 2, 2열 4, 3열 6, ...), 출력
    for (y = 0; y < 5; y++) //행
    {
        for (x = 0; x < 5; x++) //열
        {
            k = k + 2;
            A[y][x] = k;
            printf("%3d ", A[y][x]);
        }
        printf("\n");
    }

    //배열 90도 이동시키기
    for (rotate = 1; rotate < 3; rotate++)
    {
        for (y = 0; y < 5; y++)
        {
            for (x = 0; x < 5; x++)
            {
                h = 4 - x; //배열의 크기 5는 [0]~[4] 까지
                if (rotate == 1)
                    B[y][x] = A[h][y];  //90도
                else
                    A[y][x] = B[h][y];  //180도
            }
        }
    }

    //회전시킨 배열 출력
    printf("======= 90도 1번째=======\n");
    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 5; x++)
        {
            printf("%3d ", B[y][x]);
        }
        printf("\n");
    }

    printf("======= 90도 2번째=======\n");
    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 5; x++)
        {
            printf("%3d ", A[y][x]);
        }
        printf("\n");
    }
    return 0;
}