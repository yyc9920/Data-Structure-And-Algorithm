#define _CRT_SECURE_NO_WARNINGS
#include ��stdio.h��
int scoreReading(void);
char gradeDecision(int s1, int s2, int s3);
int main()
{
    int score1, score2, score3;
    score1 = scoreReading();
    score2 = scoreReading();
    score3 = scoreReading();
    printf("����� ������ %c\n", gradeDecision(score1, score2, score3));
    return 0;
}

int scoreReading()
{
    int s;
    printf("������ �Է��ϼ��� : ");
    scanf("%d", &s);
    while (1)                       //0~100 ������ ������ �Է� ����
    {
        if (s >= 0)
        {
            if (s <= 100)
                break;
        }
        printf("�ٽ� �Է��ϼ��� : ");
        scanf("%d", &s);
    }
    return s;                       //����ڷκ��� �Է� ���� ���� ���� ����
}

//���� ��ĭ �κ�
char gradeDecision(int s1, int s2, int s3)
{
    char grade;                     //����� ������ ĳ������ ���� ����
    int avg;                        //�� ������ ����� ������ ������ ���� ����

    avg = (s1 + s2 + s3) / 3.0;     //�� ������ ����� avg�� ����

    switch (avg / 10)               //������ 10���� ���� �� ������ �´� ��� ����
    {
    case 10:
        grade = 'A';
        break;

    case 9:
        grade = 'A';
        break;

    case 8:
        grade = 'B';
        break;

    case 7:
        grade = 'C';
        break;

    default:
        grade = 'F';
        break;
    }

    return grade;                   //�Ű��� ��� ���ڸ� ����
}
//���� ��ĭ �κ�
