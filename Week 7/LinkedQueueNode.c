#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
// ���� ť ����(element)�� �ڷ����� char�� ����
typedef char element;
// ���� ť�� ��带 ����ü�� ����
typedef struct QNode
{
    element data;
    struct QNode *link;
} QNode;
// ���� ť���� ����ϴ� ������ front�� rear�� ����ü�� ����
typedef struct
{
    QNode *front, *rear;
} LQueueType;
// ���� ���� ť�� �����ϴ� ����
LQueueType *createLinkedQueue()
{
    LQueueType *LQ;
    LQ = (LQueueType *)malloc(sizeof(LQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}
// ���� ť�� ���� �������� �˻��ϴ� ����
int isEmpty(LQueueType *LQ)
{
    if (LQ->front == NULL)
    {
        printf(" Linked Queue is empty! ");
        return 1;
    }
    else
        return 0;
}
// ���� ť�� ���Ҹ� �����ϴ� ����
void enQueue(LQueueType *LQ, element item)
{
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;
    if (LQ->front == NULL) // ���� ���� ť�� ���� ������ ���
    {
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    else // ���� ���� ť�� ���� ���°� �ƴ� ���
    {
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}
// ���� ť���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
element deQueue(LQueueType *LQ)
{
    QNode *old = LQ->front;
    element item;
    if (isEmpty(LQ))
        return 0;
    else
    {
        item = old->data;
        LQ->front = LQ->front->link;
        if (LQ->front == NULL)
            LQ->rear = NULL;
        free(old);
        return item;
    }
}
// ���� ť���� ���Ҹ� �˻��ϴ� ����
element peek(LQueueType *LQ)
{
    element item;
    if (isEmpty(LQ))
        return 0;
    else
    {
        item = LQ->front->data;
        return item;
    }
}
// ���� ť�� ���Ҹ� ����ϴ� ����
void printLQ(LQueueType *LQ)
{
    QNode *temp = LQ->front;
    printf(" Linked Queue : [");
    while (temp)
    {
        printf("%3c", temp->data);
        temp = temp->link;
    }
    printf(" ] ");
}
void main(void)
{
    LQueueType *LQ = createLinkedQueue(); // ���� ť ����
    element data;
    printf("\n ***** ���� ť ���� ***** \n");
    printf("\n ���� A>>");
    enQueue(LQ, 'A');
    printLQ(LQ);
    printf("\n ���� B>>");
    enQueue(LQ, 'B');
    printLQ(LQ);
    printf("\n ���� C>>");
    enQueue(LQ, 'C');
    printLQ(LQ);
    data = peek(LQ);
    printf(" peek item : %c \n", data);
    printf("\n ���� >>");
    data = deQueue(LQ);
    printLQ(LQ);
    printf("\t���� ������: %c", data);
    printf("\n ���� >>");
    data = deQueue(LQ);
    printLQ(LQ);
    printf("\t���� ������: %c", data);
    printf("\n ���� >>");
    data = deQueue(LQ);
    printLQ(LQ);
    printf("\t\t���� ������: %c", data);
    printf("\n ���� D>>");
    enQueue(LQ, 'D');
    printLQ(LQ);
    printf("\n ���� E>>");
    enQueue(LQ, 'E');
    printLQ(LQ);
    getchar();
}