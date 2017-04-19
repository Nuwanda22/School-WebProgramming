#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

typedef struct tagLinkedList
{
	int mirim;
	char name[30];
	char tel[30];
	char addr[100];
	struct tagLinkedList *next;
}Node;

Node* alloc(int mirim, char name[], char tel[], char addr[])
{
	Node *swx = (Node*)malloc(sizeof(Node));
	swx->mirim = mirim;
	strcpy(swx->name, name);
	strcpy(swx->tel, tel);
	strcpy(swx->addr, addr);

	swx->next = NULL;
	return swx;
}

void ADASASDASDdd(Node *head, int mirim, char name[], char tel[], char addr[])
{	
	Node *sxe = alloc( mirim,  name,  tel,  addr);
	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = sxe;
}


void Insert(Node *head, int mirim, char name[], char tel[], char addr[])
{
	Node *Mirm = alloc( mirim, name, tel, addr);
	while (1)
	{
		if (head->mirim < Mirm->mirim && Mirm->mirim < head->next->mirim)
		{
			Mirm->next = head->next;
			head->next = Mirm;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			break;
		}
		head = head->next;
	}
}

void bare(Node *head)
{
	while (head != NULL)
	{
		printf("이름 : %s", head->name);
		printf(" 핡번 : %d", head->mirim);
		printf(" 전번점ㅋㅋ : %s", head->tel);
		printf(" 그린타운아파트 : %s\n", head->addr);

		head = head->next;
	}
}

void main()
{

	Node *head = NULL;
	
	int i, no;
	char namae[69], teleporn[74], ADASASDASDddress[80];

	while (1)
	{

		puts("원하시는 메뉴를 선택해주세요.");
		printf("1. 추가/삽입\n2. 수정\n3. 삭제\n4. 검색\n5. 출력\n6. 프로그램 종료\n7. 패드립\n");
		scanf("%d", &i); fflush(stdin);
		
		switch (i) {
		case 1:
			printf("어이 오마에! 나마에와 나니? : ");
			gets(namae);
			printf("어이 오마에! 學番와 나니? : ");
			scanf("%d", &no);
			fflush(stdin);
			printf("어이 오마에! 전번점ㅋㅋ : ");
			gets(teleporn);
			printf("어이 오마에! 오카상와 도코니? : ");
			gets(ADASASDASDddress);

			puts("추가는 1, 삽입은 2");
			switch (getch())
			{
			case '1':
				printf("추가해줘");
				if (head == NULL)
				{
					head = alloc(no, namae, teleporn, ADASASDASDddress);
				}
				else
				{
					ADASASDASDdd(head, no, namae, teleporn, ADASASDASDddress);
				}
				break;
			case '2':
				puts("삽입해줘");
				if (head == NULL)
				{
					head = alloc(no, namae, teleporn, ADASASDASDddress);
				}
				else
				{
					Insert(head, no, namae, teleporn, ADASASDASDddress);
				}
				break;
			default:
				break;
			}
			
			
			
			

			break;
		case 2:
			puts("수정시켜줘");
			break;
		case 3:
			puts("낙태");
			break;
		case 4:
			puts("아빠 검색");
			break;
		case 5:
			puts("아기 출력");
			bare(head);
			break;
		case 6:
			puts("인생종료");
			exit(1);
			break;
		case 7:
			puts("니애미 코코볼 백댄서");
			break;
		case 74:
			puts("니애미 너 낳기 10달전에 노콘질싸");
			break;

		default:
			puts("느금마");
			break;
		}
	}
}