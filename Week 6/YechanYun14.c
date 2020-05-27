#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
// 스택 원소(element)의 자료형을 int로 정의
typedef char element;
// 스택의 노드를 구조체로 정의
typedef struct stackNode
{
    element data;
    struct stackNode *link;
} stackNode;
// 스택의 top 노드를 지정하기 위해 포인터 top 선언
stackNode *top;
// 스택이 공백 상태인지 확인하는 연산
int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
// 스택의 top에 원소를 삽입하는 연산
void push(element item)
{
    stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
    temp->data = item;
    temp->link = top; // 삽입 노드를 top의 위에 연결
    top = temp;       // top 위치를 삽입 노드로 이동
}
// 스택의 top에서 원소를 삭제하는 연산
element pop()
{
    element item;
    stackNode *temp = top;
    if (top == NULL) // 스택이 공백 리스트인 경우
    {
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else // 스택이 공백 리스트가 아닌 경우
    {
        item = temp->data;
        top = temp->link; // top 위치를 삭제 노드 아래로 이동
        free(temp);       // 삭제된 노드의 메모리 반환
        return item;      // 삭제된 원소 반환
    }
}
// 후위 표기법 수식을 계산하는 연산
void Infix2Postfix(char *exp)
{
    char symbol;
    int length = strlen(exp);
    int i=0;
    top = NULL;
    for (i = 0; i < length; i++)
    {
        symbol = exp[i];
        switch (symbol)
        {
            // 연산자 처리
            case '+':
            case '-':
            case '*':
            case '/':
                push(symbol);
                break;
            // 오른쪽괄호 처리
            case ')':
            case ']':
            case '}':
                printf("%c", pop());
                break;
            case '(':
            case '[':
            case '{':
                break;
            // 피연산자 처리
            default:
                printf("%c", symbol);
                break;
        }
    }
}
void main(void)
{
    int result;
    char *express = "{(A*B)-(C/D)}";
    printf("중위 표기식 : %s\n", express);
    printf("후위 표기식 : ");
    Infix2Postfix(express);
    getchar();
}
