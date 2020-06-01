/*
2진 탐색 트리구조를 사용한 예약 시스템


필수 항목 3가지

예약자 번호 (년도, 날짜, 예약 순서를 적용. 자동으로 생성)
이름 (영문, 한글 모두 입력될 수 있게 적용)
결제 정보 (예약된 사항에 대한 결제 여부를 표시)


기능 필수 항목

삽입
예약 정보 입력하기
이름:
결제:

삭제: 이름으로 검색하여 삭제
출력: 출력은 전체정보 출력, 예약자 정보 출력
변경: 예약 변경이 발생시 처리기능 구현
*/
// TODO: reserveDate 데이터 쌓이는 오류 해결하기.
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#define MAX_WORD_LENGTH 20
#define MAX_MEAN_LENGTH 100
#define MAX_SEAT 20

typedef struct ListNode
{
    char data[40];
    int year;
    int seat;
} movies;

typedef struct
{
    char name[MAX_WORD_LENGTH];
    char reserveNum[MAX_MEAN_LENGTH];
    char reserveDate[MAX_WORD_LENGTH];
	movies *movie;
	char payInfo;
} element;

typedef struct treeNode
{
    element key;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

char tmpReserveDate[MAX_WORD_LENGTH];
char tmpReserveNum[MAX_MEAN_LENGTH];

movies *movie[10];

void initAll(){
	int i=0;

	while(i<10){
		movie[i] = (movies *)malloc(sizeof(movies));
        movie[i]->seat = 0;
		i++;
	}
	strcpy(movie[0]->data, "Harry Porter");
	strcpy(movie[1]->data, "Lord of the Ring");
	strcpy(movie[2]->data, "Darknight");
	strcpy(movie[3]->data, "Avengers");
	strcpy(movie[4]->data, "Interstellar");
	strcpy(movie[5]->data, "Conjuring");
	strcpy(movie[6]->data, "Star Wars");
	strcpy(movie[7]->data, "X-Men");
	strcpy(movie[8]->data, "Avatar");
	strcpy(movie[9]->data, "Terminator");

	movie[0]->year = 2001;
	movie[1]->year = 2002;
	movie[2]->year = 2008;
	movie[3]->year = 2012;
	movie[4]->year = 2014;
	movie[5]->year = 2013;
	movie[6]->year = 1977;
	movie[7]->year = 2000;
	movie[8]->year = 2009;
	movie[9]->year = 1984;
}

void displayMovies(){
	int k=0;
    printf("\n");
	while(k<5){
		printf("%d:%-16s(%d)\t", (k+1), movie[k]->data, movie[k]->year);
		k++;
	}
	printf("\n\n");
	while(k<10){
		printf("%d:%-16s(%d)\t", (k+1) ,movie[k]->data, movie[k]->year);
		k++;
	}
	printf("\n");
}

// 포인터 p가 가리키는 노드와 비교하여 항목 key를 삽입하는 연산
treeNode *insertKey(treeNode *p, element key)
{
    treeNode *newNode;
    int compare;
    // 삽입할 자리에 새 노드를 구성하여 연결
    if (p == NULL)
    {
        newNode = (treeNode *)malloc(sizeof(treeNode));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    // 이진 트리에서 삽입할 자리 탐색
    else
    {
        compare = strcmp(key.name, p->key.name);
        if (compare < 0)
            p->left = insertKey(p->left, key);
        else if (compare > 0)
            p->right = insertKey(p->right, key);
        else
            printf("\n 이미 예매 되어 있습니다! \n");
        return p; // 삽입한 자리 반환
    }
}

void insert(treeNode **root, element key)
{
    *root = insertKey(*root, key);
}

// root 노드부터 탐색하여 key와 같은 노드를 찾아 삭제하는 연산
// 이름으로 검색하여 삭제
void deleteNode(treeNode *root, element key)
{
    treeNode *parent, *p, *succ, *succ_parent;
    treeNode *child;
    parent = NULL;
    p = root;
    while ((p != NULL) && (strcmp(p->key.name, key.name) != 0))
    {
        parent = p;
        if (strcmp(key.name, p->key.name) < 0)
            p = p->left;
        else
            p = p->right;
    }
    // 삭제할 노드가 없는 경우
    if (p == NULL)
    {
        printf("\n 이 이름으로 된 예매 정보가 없습니다!!");
        return;
    }
    // 삭제할 노드가 단말 노드인 경우
    if ((p->left == NULL) && (p->right == NULL))
    {
        if (parent != NULL)
        {
            if (parent->left == p)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else
            root = NULL;
    }
    // 삭제할 노드가 자식 노드를 한 개 가진 경우
    else if ((p->left == NULL) || (p->right == NULL))
    {
        if (p->left != NULL)
            child = p->left;
        else
            child = p->right;
        if (parent != NULL)
        {
            if (parent->left == p)
                parent->left = child;
            else
                parent->right = child;
        }
        else
            root = child;
    }
    // 삭제할 노드가 자식 노드를 두 개 가진 경우
    else
    {
        succ_parent = p;
        succ = p->right;
        while (succ->left != NULL)
        {
            succ_parent = succ;
            succ = succ->left;
        }
        if (succ_parent->left == succ)
            succ_parent->left = succ->right;
        else
            succ_parent->right = succ->right;
        p->key = succ->key;
        p = succ;
    }
    printf("\n취소한 예매 번호는 %s 입니다\n", p->key.reserveNum);
    free(p);
    printf("\n예매가 취소되었습니다.\n");
}

// 이진 탐색 트리에서 키값이 key인 노드 위치를 탐색하는 연산
treeNode *searchBST(treeNode *root, element key)
{
    treeNode *p;
    int compare;
    p = root;
    while (p != NULL)
    {
        compare = strcmp(key.reserveNum, p->key.reserveNum);
        if (compare < 0)
            p = p->left;
        else if (compare > 0)
            p = p->right;
        else
        {
            return p;
        }
    }
    return p;
}

treeNode *searchBSTName(treeNode *root, element key)
{
    treeNode *p;
    int compare;
    p = root;
    while (p != NULL)
    {
        compare = strcmp(key.name, p->key.name);
        if (compare < 0)
            p = p->left;
        else if (compare > 0)
            p = p->right;
        else
        {
            printf("\n찾은 이름 : %s", p->key.name);
            return p;
        }
    }
    return p;
}

// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder()
{
	int k=0;
    printf("\n");
	while(k<5){
		printf("%d:%-16s(%d)\t", (k+1), movie[k]->data, movie[k]->year);
		k++;
	}
    k=0;
    printf("\n");
    while (k<5){
        printf("남은 좌석 수: %d\t\t", MAX_SEAT-movie[k]->seat);
        k++;
    }
	printf("\n\n");
	while(k<10){
		printf("%d:%-16s(%d)\t", (k+1) ,movie[k]->data, movie[k]->year);
		k++;
	}
    k=5;
    printf("\n");
    while (k<10){
        printf("남은 좌석 수: %d\t\t", MAX_SEAT-movie[k]->seat);
        k++;
    }
	printf("\n");
}

void selectReserveDate() {
    int m=0, d=0, t;
    int sum;
    char tmp[10];
    char tmp2[10];
    printf("\n*-------------------------------------------------*\n");
    while(m < 12) {
        m++;
        printf("%4d", m);
    }
    printf("\n*-------------------------------------------------*\n");
    do {
        printf("\n예매할 달을 선택하세요 : ");
        scanf("%d", &m);
        while (getchar() !=  '\n');
    } while (m < 1 || m > 12);
    
    printf("\n*-----------------------------------------*\n");
    switch (m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            while(d < 31) {
                d++;
                printf("%4d", d);
                if (d == 10 || d == 20 || d == 30)
                    printf("\n");
            }
            printf("\n*-----------------------------------------*\n");
            do {
                printf("\n예매할 날짜를 선택하세요 : ");
                scanf("%d", &d);
                while (getchar() !=  '\n');
            } while (d < 1 || d > 31);
            break;
            
        case 4:
        case 6:
        case 9:
        case 11:
            while(d < 30) {
                d++;
                printf("%4d", d);
                if (d == 10 || d == 20)
                    printf("\n");
            }
            printf("\n*-----------------------------------------*\n");
            do {
                printf("\n예매할 날짜를 선택하세요 : ");
                scanf("%d", &d);
                while (getchar() !=  '\n');
            } while (d < 1 || d > 30);
            break;

        case 2:
            while(d < 28) {
                d++;
                printf("%4d", d);
                if (d == 10 || d == 20)
                    printf("\n");
            }
            printf("\n*----------------------------------------*\n");
            do {
                printf("\n예매할 날짜를 선택하세요 : ");
                scanf("%d", &d);
                while (getchar() !=  '\n');
            } while (d < 1 || d > 28);
            break;

        default:
            break;
    }
    printf("\n상영 시간을 선택 해주세요.");
    printf("\n*---------------------------------------------------------------------*\n");
    printf("1: 조조 (07:00~10:00)\t");
    printf("2: 아침 (10:00~13:00)\t");
    printf("3: 정오 (13:00~16:00)\n");
    printf("4: 오후 (16:00~19:00)\t");
    printf("5: 저녁 (19:00~22:00)\t");
    printf("6: 심야 (22:00~01:00)");
    printf("\n*---------------------------------------------------------------------*\n");
    do {
        printf("상영 시간 : ");
        scanf("%d", &t);
        while (getchar() !=  '\n');
    } while (t < 1 || t > 6);

    sum = m*1000 + d*10 + t;

    if (m<10)
        tmp2[0] = '0';

    sprintf(tmp, "%d", sum);
    strcat(tmp2, tmp);
    strcpy(tmpReserveDate, tmp2);
}

char *initReserveNum(element e) {
    struct tm *date;
    const time_t t = time(NULL);
    date = localtime(&t);
    int y;
    char tmp[7];

    tmp[0] = e.name[0];
    tmp[1] = e.name[1];
    tmp[2] = e.name[2];
    tmp[3] = e.movie->seat + 48;
    tmp[4] = e.movie->data[0];
    tmp[5] = e.payInfo;

    y = 1900 + date->tm_year;

    sprintf(tmpReserveNum, "%d", y);
    strcat(tmpReserveNum, tmp);
    strcat(tmpReserveNum, e.reserveDate);

    return tmpReserveNum;
}

void changeReserve(treeNode *tmp){
    int c, mn;
    int pi;
    printf("\n[예매 정보]\n");
    printf("예매 번호 : %s\n", tmp->key.reserveNum);
    printf("예매자 이름 : %s\n", tmp->key.name);
    printf("예매한 영화 제목 : %s\n", tmp->key.movie->data);
    if (tmp->key.payInfo == 'Y' || tmp->key.payInfo == 'y')
        printf("결제 정보 : 결제 완료\n");
    else
        printf("결제 정보 : 미결제\n");
    printf("\n현재 예매 날짜 정보입니다.\n");
    printf("\n*-----------------------*\n");
    printf("  %c%c%c%c년 ", tmp->key.reserveNum[0], tmp->key.reserveNum[1], tmp->key.reserveNum[2], tmp->key.reserveNum[3]);
    printf("%c%c월 ", tmp->key.reserveNum[10], tmp->key.reserveNum[11]);
    printf("%c%c일 ", tmp->key.reserveNum[12], tmp->key.reserveNum[13]);
    switch(tmp->key.reserveNum[14] - 48) {
        case 1:
            printf("조조\n");
            break;
        case 2:
            printf("아침\n");
            break;
        case 3:
            printf("정오\n");
            break;
        case 4:
            printf("오후\n");
            break;
        case 5:
            printf("저녁\n");
            break;
        case 6:
            printf("심야\n");
            break;
    }
    printf("*-----------------------*\n");
    printf("[예매 정보 끝]\n");
    printf("\n변경하고싶은 예매 정보를 선택하세요!\n");
    printf("\n*---------------------------*");
    printf("\n\t1 : 영화 변경");
    printf("\n\t2 : 결제 변경");
    printf("\n\t3 : 예매 날짜 변경");
    printf("\n\t4 : 돌아가기");
    printf("\n*---------------------------*\n ");
    scanf("%d", &c);
    while (getchar() !=  '\n');

    switch (c)
    {
    case 1:
        displayMovies();
        do {
            printf("\n[영화 제목 입력] 제목 번호를 입력하시오 : ");
            scanf("%d", &mn);
            while (getchar() !=  '\n');
            if (mn < 1 || mn > 10)
                printf("\n잘못 입력하셨습니다.\n");
        } while(mn < 1 || mn > 10);
        if (movie[mn-1] == tmp->key.movie) {
            printf("\n이미 해당 영화로 예매 되어있습니다.\n");
            break;
        }
        tmp->key.movie = movie[mn-1];
        strcpy(tmp->key.reserveNum, initReserveNum(tmp->key));
        printf("\n해당 영화로 예매 정보가 변경되었습니다.\n");
        printf("\n예매 번호 : %s\n", tmp->key.reserveNum);
        printf("계속 하려면 엔터 키를 누르세요.");
        getchar();
        break;

    case 2:
        printf("\n현재 결제 정보입니다.\n");
        if (tmp->key.payInfo == 'Y' || tmp->key.payInfo == 'y')
            printf("결제 완료\n");
        else 
            printf("미결제\n");

        printf("\n결제 정보를 변경하려면 1을, 유지하려면 1 이외의 다른 숫자를 입력하세요 : ");
        scanf("%d", &pi);
        while (getchar() !=  '\n');
        if (pi == 1) {
            if (tmp->key.payInfo == 'Y' || tmp->key.payInfo == 'y')
                tmp->key.payInfo = 'N';
            else
                tmp->key.payInfo = 'Y';
            
            strcpy(tmp->key.reserveNum, initReserveNum(tmp->key));
            printf("\n결제 정보가 변경되었습니다.\n");
            printf("\n예매 번호 : %s\n", tmp->key.reserveNum);
            printf("계속 하려면 엔터 키를 누르세요.");
            getchar();
        } else {
            printf("\n결제 정보 변경이 취소되었습니다.\n");
        }
        break;

    case 3:
		selectReserveDate();
        strcpy(tmp->key.reserveDate, tmpReserveDate);
        tmpReserveDate[0] = '\0';
        strcpy(tmp->key.reserveNum, initReserveNum(tmp->key));
        printf("\n예매 날짜가 변경되었습니다.\n");
        printf("\n예매 번호 : %s\n", tmp->key.reserveNum);
        printf("계속 하려면 엔터 키를 누르세요.");
        getchar();
    
    default:
        break;
    }
}

// 예매 메뉴
void menu()
{
    printf("\n*---------------------------*");
    printf("\n\t1 : 예매 정보 출력");
    printf("\n\t2 : 예매하기");
    printf("\n\t3 : 예매 취소");
    printf("\n\t4 : 예매 확인");
    printf("\n\t5 : 예매 변경");
    printf("\n\t6 : 종료");
    printf("\n*---------------------------*\n ");
}

void main()
{
    element e;
    treeNode *root = NULL, *temp = NULL;
    int choice;
    int movieNum;
	initAll();
    // [6 :종료] 메뉴를 선택할 때까지 예약 시스템 반복.
    do
    {
        menu();
        scanf("%d", &choice);
        while (getchar() !=  '\n');
        switch (choice)
        {
        case 1:
            printf("\n[현재 예매 정보]");
            displayInorder();
            printf("[예매 정보 끝]\n");
            break;
        case 2:
            displayMovies();
            do {
                printf("\n[영화 제목 입력] 제목 번호를 입력하시오 : ");
                scanf("%d", &movieNum);
                while (getchar() !=  '\n');
                if (movieNum < 1 || movieNum > 10)
                    printf("\n잘못 입력하셨습니다.\n");

                else if (movie[movieNum-1]->seat >= MAX_SEAT) {
                    printf("\n해당 영화는 매진되었습니다.\n");
                    movieNum = 100;
                }
            } while(movieNum < 1 || movieNum > 10);


			selectReserveDate();
            strcpy(e.reserveDate, tmpReserveDate);
            tmpReserveDate[0] = '\0';
            do {
                printf("\n[예매자 이름 입력] 이름을 입력하세요 : ");
                scanf("%[^\n]", e.name);
                while (getchar() != '\n');
            } while(e.name[0] == '\0' || e.name[1] =='\0' || e.name[2] == '\0');
			
			temp = searchBSTName(root, e);
			
			if(temp != NULL) {
				if(strcmp(temp->key.name, e.name) == 0) {
					printf("\n해당 이름으로 된 예매 내역이 이미 있습니다.\n");
					printf("예매 번호 : %s\n", temp->key.reserveNum);
					break;
				}
			}

            do{
                while (getchar() !=  '\n');
                printf("\n[결제 정보 입력] 결제 하시겠습니까?[Y/N]: ");
                scanf("%c", &e.payInfo);
            } while (e.payInfo != 'y' && e.payInfo != 'Y' && e.payInfo != 'n' && e.payInfo != 'N');
            e.movie = movie[movieNum-1];
            e.movie->seat++;
            strcpy(e.reserveNum, initReserveNum(e));
            insert(&root, e);
            printf("\n예매 번호 : %s\n", e.reserveNum);
            printf("계속 하려면 엔터 키를 누르세요.");
            e.name[0] = '\0';
            e.reserveNum[0] = '\0';
            e.reserveDate[0] = '\0';
            getchar();
            break;
        case 3:
            printf("\n[예매자 이름 입력] 이름 : ");
            scanf("%[^\n]", e.name);
            temp = searchBSTName(root, e);
            if (temp != NULL){                
                temp->key.movie->seat--;
            }
            deleteNode(root, e);
            temp = NULL;
            e.name[0] = '\0';
            e.reserveNum[0] = '\0';
            break;
        case 4:
            printf("\n[예매자 이름 입력] 이름 : ");
            scanf("%[^\n]", e.name);
            temp = searchBSTName(root, e);
            if (temp != NULL){
                printf("\n[예매 정보]\n");
                printf("예매 번호 : %s\n", temp->key.reserveNum);
                printf("예매자 이름 : %s\n", temp->key.name);
                printf("예매한 영화 제목 : %s\n", temp->key.movie->data);
                if (temp->key.payInfo == 'Y' || temp->key.payInfo == 'y')
                    printf("결제 정보 : 결제 완료\n");
                else
                    printf("결제 정보 : 미결제\n");
                printf("\n현재 예매 날짜 정보입니다.\n");
                printf("\n*-----------------------*\n");
                printf("  %c%c%c%c년 ", temp->key.reserveNum[0], temp->key.reserveNum[1], temp->key.reserveNum[2], temp->key.reserveNum[3]);
                printf("%c%c월 ", temp->key.reserveNum[10], temp->key.reserveNum[11]);
                printf("%c%c일 ", temp->key.reserveNum[12], temp->key.reserveNum[13]);
                switch(temp->key.reserveNum[14] - 48) {
                    case 1:
                        printf("조조\n");
                        break;
                    case 2:
                        printf("아침\n");
                        break;
                    case 3:
                        printf("정오\n");
                        break;
                    case 4:
                        printf("오후\n");
                        break;
                    case 5:
                        printf("저녁\n");
                        break;
                    case 6:
                        printf("심야\n");
                        break;
                }
                printf("*-----------------------*\n");
                printf("\n[예매 정보 끝]\n");
            }else{
                printf("\n예매 내역을 찾을 수 없습니다.");
            }
            temp = NULL;
            e.name[0] = '\0';
            e.reserveNum[0] = '\0';
            break;
        case 5:
            printf("\n[예매자 이름 입력] 이름 : ");
            scanf("%[^\n]", e.name);
            temp = searchBSTName(root, e);
            changeReserve(temp);
            temp = NULL;
            e.name[0] = '\0';
            e.reserveNum[0] = '\0';
            e.reserveDate[0] = '\0';
            break;
        }
        while (getchar() != '\n')
            ;
    } while (choice != 6);

}
