#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

typedef struct  //Sprsmtrx��� ����Ÿ�� ����
{
    int row;
    int col;
    int value;
} SprsMtrx;

SprsMtrx *smCreate(int A[][7], int row, int col, int *cnt)
{
    int i, j;
    SprsMtrx *S;
    for (j = 0; j < row; j++)
    {
        for (i = 0; i < col; i++)
        {
            if (A[j][i]) // 0�̾ƴ� ������ ���� ���ϱ�;
                (*cnt)++;
        }
    }
    // �ʱⰪ ������ ������ 1�� �� �ʿ���
    S = (SprsMtrx *)malloc(sizeof(SprsMtrx) * ((*cnt) + 1));
    // ���� �� ��, ��, ������ ���� �ֱ�
    S[0].row = row;
    S[0].col = col;
    S[0].value = *cnt;
    // �������� �� ���ҿ� �� �Ҵ��ϱ�
    *cnt = 1;
    for (j = 0; j < row; j++)
    {
        for (i = 0; i < col; i++)
        {
            if (A[j][i])
            {
                S[*cnt].row = j;
                S[*cnt].col = i;
                S[(*cnt)++].value = A[j][i];
            }
        }
    }
    return S;
}

int main()
{
    int i, j, cnt = 0;
    // ���� �� ��� ��
    int A[][7] = {{0, 0, 2, 0, 0, 0, 12},
                  {0, 0, 0, 0, 7, 0, 0},
                  {23, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 31, 0, 0, 0},
                  {0, 14, 0, 0, 0, 25, 0},
                  {0, 0, 0, 0, 0, 0, 6},
                  {52, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 11, 0, 0}};
    for (j = 0; j < 8; j++)
    {
        for (i = 0; i < 7; i++)
        {
            printf("%4d", A[j][i]);
        }
        printf("\n");
    }
    SprsMtrx *S = smCreate(A, sizeof(A) / (sizeof(int) * 7), 7, &cnt);
    printf("=======��� ��� ���=======\n"); // ��� �ϱ�
    for (i = 0; i < cnt; i++)
    {
        printf("%4d %4d %4d\n", S[i].row, S[i].col, S[i].value);
    }
    return 0;
}
