#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
// ���� ����(element)�� �ڷ����� int�� ����
typedef char element;
// ������ ��带 ����ü�� ����
typedef struct stackNode
{
    element data;
    struct stackNode *link;
} stackNode;
// ������ top ��带 �����ϱ� ���� ������ top ����
stackNode *top;
// ������ ���� �������� Ȯ���ϴ� ����
int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
// ������ top�� ���Ҹ� �����ϴ� ����
void push(element item)
{
    stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
    temp->data = item;
    temp->link = top; // ���� ��带 top�� ���� ����
    top = temp;       // top ��ġ�� ���� ���� �̵�
}
// ������ top���� ���Ҹ� �����ϴ� ����
element pop()
{
    element item;
    stackNode *temp = top;
    if (top == NULL) // ������ ���� ����Ʈ�� ���
    {
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else // ������ ���� ����Ʈ�� �ƴ� ���
    {
        item = temp->data;
        top = temp->link; // top ��ġ�� ���� ��� �Ʒ��� �̵�
        free(temp);       // ������ ����� �޸� ��ȯ
        return item;      // ������ ���� ��ȯ
    }
}
// ���� ǥ��� ������ ����ϴ� ����
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
            // ������ ó��
            case '+':
            case '-':
            case '*':
            case '/':
                push(symbol);
                break;
            // �����ʰ�ȣ ó��
            case ')':
            case ']':
            case '}':
                printf("%c", pop());
                break;
            case '(':
            case '[':
            case '{':
                break;
            // �ǿ����� ó��
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
    printf("���� ǥ��� : %s\n", express);
    printf("���� ǥ��� : ");
    Infix2Postfix(express);
    getchar();
}
