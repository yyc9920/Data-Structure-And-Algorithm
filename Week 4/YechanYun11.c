#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIZE 40

// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode
{
    char data[SIZE];
    int year;
    struct ListNode *link;
} listNode;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct
{
    listNode *head;
} linkedList_h;

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
    int Num = 0;
    listNode *p; // = NULL;
    p = L->head;
    while (p != NULL)
    {
        Num++;
        printf(" %d ����: %s\t", Num, p->data);
        printf(" �⵵: %d\n", p->year);
        p = p->link;
    }
}

void insertNode(linkedList_h *L, char *s, int y)
{
    listNode *newNode;
    newNode = (listNode *)malloc(sizeof(listNode));
    strcpy(newNode->data, s);
    newNode->year = y;
    // ���� ����Ʈ�� ���
    // �� ��带 ù ��°���� ������ ���� ����
    if (L->head == NULL)
    {
        newNode->link = NULL;
        L->head = newNode;
    }
    // ���� ��尡 ������ �� ���� ��忡 ���Եǰ� �Ѵ�.
    else if (newNode == NULL)
    {
        newNode->link = L->head; // �� ��带 ù ��° ���� ����
        L->head = newNode;
    }
    else //����Ʈ �߰��� ���Եǰ� �Ѵ�.
    {
        newNode->link = L->head->link;
        L->head->link = newNode;
    }
}

int menu()
{
    int men = 0;
    printf(" --------------------\n");
    printf(" 1. ��ȭ ���� �߰�\n");
    printf(" 2. ��ȭ ���� ���\n");
    printf(" 3. ����\n");
    printf(" --------------------\n");
    printf(" ��ȣ�� �����ϼ��� : ");
    scanf("%d", &men);
    return men;
}

int main()
{
    int cho = 0, y;
    char s[40];
    linkedList_h *L;
    L = createLinkedList_h();
    while ((cho = menu()) < 4)
    {
        getchar();
        if (cho == 1)
        {
            printf(" ��ȭ�� ������ �Է��ϼ��� : ");
            scanf("%[^\n]s", &s);
            printf(" ��ȭ�� ���� ������ �Է��ϼ��� : ");
            scanf("%d", &y);
            insertNode(L, s, y);
        }
        else if (cho == 2)
        {
            printList(L);
            getchar();
        }
        else if (cho == 3)
        {
            freeLinkedList_h(L);
            break;
        }
        system("cls");
    }
    return 0;
}