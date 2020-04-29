#define _CRT_SECURE_NO_WARNINGS #include “stdio.h”
int main()
{
    int num;
    int value1 = 0, value2 = 1;
    int printValue = 0;
    int cnt = 0;
    printf("몇 항까지 출력하는가(0이상의 수) : ");
    scanf("%d", &num);
    while (cnt != num)
    {
        printf("%d ", printValue); // 출력될 값
        printValue = value2;       //두 번째 value 값을 출력하기 위해
        value2 += value1;          // 두 번째 값에 첫 번째 값을 더한다
        value1 = printValue;       // 첫 번째 값에 두 번째 값을 대입한다.
        cnt++;
    }
    printf("\n");

    return 0;
}