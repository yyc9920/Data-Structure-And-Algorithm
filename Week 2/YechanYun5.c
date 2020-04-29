#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int algorithmA(int n);
int algorithmB(int n);
int algorithmC(int n);

int main()
{
    clock_t start, finish;
    long duration;
    int i, sum;
    start = clock();
    for (i = 0; i < 1500; i++)
        sum = algorithmA(1500);
    finish = clock();
    duration = (finish - start);
    printf("알고리즘 A: 합계: %d 소요시간: %ld\n", sum, duration);
    start = clock();
    for (i = 0; i < 1500; i++)
        sum = algorithmB(1500);
    finish = clock();
    duration = (finish - start);
    printf("알고리즘 B: 합계: %d 소요시간: %d\n", sum, duration);
    start = clock();
    for (i = 0; i < 1500; i++)
        sum = algorithmC(1500);
    finish = clock();
    duration = (finish - start);
    printf("알고리즘 C: 합계: %d 소요시간: %d\n", sum, duration);
    return 0;
}

int algorithmA(int n)
{
    int sum;
    sum = n * (n + 1) / 2;
    return sum;
}

int algorithmB(int n)
{
    int i, sum = 0;
    for (i = 1; i <= n; i++)
        sum = sum + i;
    return sum;
}

int algorithmC(int n)
{
    int i, k, sum = 0;
    for (i = 1; i <= n; i++)
        for (k = 0; k < i; k++)
            sum = sum + 1;
    return sum;
}