#include <stdio.h>

int main()
{
    int num[9]; //9개의 자연수를 받기 위한 정수형 배열 선언
    int i, j, temp, loc;
    for (i = 0; i < 9; i++)
    {
        printf("100보다 작은 자연수를 입력하세요 : ");
        scanf("%d", &num[i]);
        while (1)
        {
            if (num[i] > 0)
            {
                if (num[i] < 100)
                    break;
            }
            printf("다시 입력하세요 : ");
            scanf("%d", &num[i]);
        }
        for (j = 0; j < i; j++)
        {
            while (num[i] == num[j])
            {
                printf("다시 입력하세요 : ");
                scanf("%d", &num[i]);
                while (1)
                {
                    if (num[i] > 0)
                    {
                        if (num[i] < 100)
                            break;
                    }
                    printf("다시 입력하세요 : ");
                    scanf("%d", &num[i]);
                }
                j = 0;
            }
        }
    }

    temp = num[1];
    loc = 2;

    for (i = 0; i < 9; i++)
    {
        if (num[i] > temp)
        {
            temp = num[i]; //num[0]~num[8]까지 서로를 비교해서 가장 큰 수를 temp에 저장
            loc = i + 1;   //해당 변수의 위치를 loc에 저장
        }
        else
            ;
    }

    for (i = 0; i < 9; i++) //출력
    {
        printf("%d  ", num[i]);
    }
    printf("\n");
    printf("가장 큰 자연수의 위치는 : %d번째 수, 가장 큰 자연수는 : %d", loc, temp);
    return 0;
}