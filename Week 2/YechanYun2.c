#define _CRT_SECURE_NO_WARNINGS
#include “stdio.h”
int scoreReading(void);
char gradeDecision(int s1, int s2, int s3);
int main()
{
    int score1, score2, score3;
    score1 = scoreReading();
    score2 = scoreReading();
    score3 = scoreReading();
    printf("당신의 학점은 %c\n", gradeDecision(score1, score2, score3));
    return 0;
}

int scoreReading()
{
    int s;
    printf("점수를 입력하세요 : ");
    scanf("%d", &s);
    while (1)                       //0~100 사이의 점수만 입력 가능
    {
        if (s >= 0)
        {
            if (s <= 100)
                break;
        }
        printf("다시 입력하세요 : ");
        scanf("%d", &s);
    }
    return s;                       //사용자로부터 입력 받은 점수 값을 리턴
}

//과제 빈칸 부분
char gradeDecision(int s1, int s2, int s3)
{
    char grade;                     //등급을 저장할 캐릭터형 변수 선언
    int avg;                        //세 점수의 평균을 저장할 정수형 변수 선언

    avg = (s1 + s2 + s3) / 3.0;     //세 점수의 평균을 avg에 저장

    switch (avg / 10)               //점수를 10으로 나눠 각 점수에 맞는 등급 구분
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

    return grade;                   //매겨진 등급 문자를 리턴
}
//과제 빈칸 부분
