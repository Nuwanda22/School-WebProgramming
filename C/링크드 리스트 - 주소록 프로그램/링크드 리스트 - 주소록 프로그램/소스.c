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
		printf("�̸� : %s", head->name);
		printf(" ���� : %d", head->mirim);
		printf(" ���������� : %s", head->tel);
		printf(" �׸�Ÿ�����Ʈ : %s\n", head->addr);

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

		puts("���Ͻô� �޴��� �������ּ���.");
		printf("1. �߰�/����\n2. ����\n3. ����\n4. �˻�\n5. ���\n6. ���α׷� ����\n7. �е帳\n");
		scanf("%d", &i); fflush(stdin);
		
		switch (i) {
		case 1:
			printf("���� ������! �������� ����? : ");
			gets(namae);
			printf("���� ������! ����� ����? : ");
			scanf("%d", &no);
			fflush(stdin);
			printf("���� ������! ���������� : ");
			gets(teleporn);
			printf("���� ������! ��ī��� ���ڴ�? : ");
			gets(ADASASDASDddress);

			puts("�߰��� 1, ������ 2");
			switch (getch())
			{
			case '1':
				printf("�߰�����");
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
				puts("��������");
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
			puts("����������");
			break;
		case 3:
			puts("����");
			break;
		case 4:
			puts("�ƺ� �˻�");
			break;
		case 5:
			puts("�Ʊ� ���");
			bare(head);
			break;
		case 6:
			puts("�λ�����");
			exit(1);
			break;
		case 7:
			puts("�Ͼֹ� ���ں� ���");
			break;
		case 74:
			puts("�Ͼֹ� �� ���� 10������ ��������");
			break;

		default:
			puts("���ݸ�");
			break;
		}
	}
}