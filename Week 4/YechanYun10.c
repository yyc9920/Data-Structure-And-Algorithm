#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode
{
    char data[4];
    struct ListNode *link;
} listNode;
// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct
{
    listNode *head;
} linkedList_h;

//ù ��° ���� �����ϴ� ����
void insertFirstNode(linkedList_h *L, char *x)
{
    listNode *newNode;
    //������ �� ��� �Ҵ�
    newNode = (listNode *)malloc(sizeof(listNode));
    strcpy(newNode->data, x); // �� ����� ������ �ʵ忡 x ����
    newNode->link = L->head;
    L->head = newNode;
}

// ������ ���� �����ϴ� ����
void insertLastNode(linkedList_h *L, char *x)
{
    listNode *newNode;
    listNode *temp;
    newNode = (listNode *)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = NULL;
    if (L->head == NULL) // ���� ����Ʈ�� ������ ���
    {
        L->head = newNode; // �� ��带 ����Ʈ�� ���� ���� ����
        return;
    }
    // ���� ����Ʈ�� ������ �ƴ� ���
    temp = L->head;
    while (temp->link != NULL)
        temp = temp->link; // ���� ����Ʈ�� ������ ��带 ã��
    temp->link = newNode;  // �� ��带 ������ ���(temp)�� ���� ���� ����
}

// ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h *createLinkedList_h(void)
{
    linkedList_h *L;
    L = (linkedList_h *)malloc(sizeof(linkedList_h));
    L->head = NULL;
    return L;
}

// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(linkedList_h *L)
{
    listNode *p;
    while (L->head != NULL)
    {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}

void printList(linkedList_h *L)
{
    listNode *p;
    printf("L=(");
    p = L->head;
    while (p != NULL)
    {
        printf("%s", p->data);
        p = p->link;
        if (p != NULL)
            printf(", ");
    }
    printf(") \n");
}

int main()
{
    linkedList_h *L;
    L = createLinkedList_h();
    printf("(1) ���� ����Ʈ �����ϱ�! \n");
    printList(L);
    getchar();
    printf("(2) ����Ʈ�� [��] ��� �����ϱ�! \n");
    insertFirstNode(L, "��");
    printList(L);
    getchar();
    printf("(3) ����Ʈ �������� [��] ��� �����ϱ�! \n");
    insertLastNode(L, "��");
    printList(L);
    getchar();
    printf("(4) ����Ʈ ù ��°�� [��] ��� �����ϱ�! \n");
    insertFirstNode(L, "��");
    printList(L);
    getchar();
    printf("(5) ����Ʈ ������ �����Ͽ� ���� ����Ʈ�� �����! \n");
    freeLinkedList_h(L);
    printList(L);
    getchar();
    return 0;
}