#define _CRT_SECURE_NO_WARNINGS #include ��stdio.h��
int getFibo(int n);
int main()
{
    int num, i;
    printf("�� �ױ��� ����ϴ°�(0�̻��� ��): ");
    scanf("%d", &num);
    for (i = 0; i <= num; i++)
        printf("%d ", getFibo(i));
    printf("\n");
    return 0;
}
int getFibo(int n)
{
    if (n < 2)
        return n;
    else
        return getFibo(n - 1) + getFibo(n - 2);
}