#define _CRT_SECURE_NO_WARNINGS #include ��stdio.h��
int main()
{
    int num;
    int value1 = 0, value2 = 1;
    int printValue = 0;
    int cnt = 0;
    printf("�� �ױ��� ����ϴ°�(0�̻��� ��) : ");
    scanf("%d", &num);
    while (cnt != num)
    {
        printf("%d ", printValue); // ��µ� ��
        printValue = value2;       //�� ��° value ���� ����ϱ� ����
        value2 += value1;          // �� ��° ���� ù ��° ���� ���Ѵ�
        value1 = printValue;       // ù ��° ���� �� ��° ���� �����Ѵ�.
        cnt++;
    }
    printf("\n");

    return 0;
}