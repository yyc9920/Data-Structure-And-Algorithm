//�����̵�9~14
//�迭 ���� ��ġ�� 90�� �̵� ��Ű�� �ڵ�

#include <stdio.h>
int A[5][5]; //�迭 ����
int B[5][5];
int rotate;
int x, y, k, h; //���� ����

int main()
{
    k = 0;
    //�迭 �ʱ�ȭ(1�� 1�� 2, 2�� 4, 3�� 6, ...), ���
    for (y = 0; y < 5; y++) //��
    {
        for (x = 0; x < 5; x++) //��
        {
            k = k + 2;
            A[y][x] = k;
            printf("%3d ", A[y][x]);
        }
        printf("\n");
    }

    //�迭 90�� �̵���Ű��
    for (rotate = 1; rotate < 3; rotate++)
    {
        for (y = 0; y < 5; y++)
        {
            for (x = 0; x < 5; x++)
            {
                h = 4 - x; //�迭�� ũ�� 5�� [0]~[4] ����
                if (rotate == 1)
                    B[y][x] = A[h][y];  //90��
                else
                    A[y][x] = B[h][y];  //180��
            }
        }
    }

    //ȸ����Ų �迭 ���
    printf("======= 90�� 1��°=======\n");
    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 5; x++)
        {
            printf("%3d ", B[y][x]);
        }
        printf("\n");
    }

    printf("======= 90�� 2��°=======\n");
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