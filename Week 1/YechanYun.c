#include <stdio.h>

int main()
{
    int num[9]; //9���� �ڿ����� �ޱ� ���� ������ �迭 ����
    int i, j, temp, loc;
    for (i = 0; i < 9; i++)
    {
        printf("100���� ���� �ڿ����� �Է��ϼ��� : ");
        scanf("%d", &num[i]);
        while (1)
        {
            if (num[i] > 0)
            {
                if (num[i] < 100)
                    break;
            }
            printf("�ٽ� �Է��ϼ��� : ");
            scanf("%d", &num[i]);
        }
        for (j = 0; j < i; j++)
        {
            while (num[i] == num[j])
            {
                printf("�ٽ� �Է��ϼ��� : ");
                scanf("%d", &num[i]);
                while (1)
                {
                    if (num[i] > 0)
                    {
                        if (num[i] < 100)
                            break;
                    }
                    printf("�ٽ� �Է��ϼ��� : ");
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
            temp = num[i]; //num[0]~num[8]���� ���θ� ���ؼ� ���� ū ���� temp�� ����
            loc = i + 1;   //�ش� ������ ��ġ�� loc�� ����
        }
        else
            ;
    }

    for (i = 0; i < 9; i++) //���
    {
        printf("%d  ", num[i]);
    }
    printf("\n");
    printf("���� ū �ڿ����� ��ġ�� : %d��° ��, ���� ū �ڿ����� : %d", loc, temp);
    return 0;
}