// ������ ���

#include "Mirim.h"

// ��� �Ҵ� �Լ�
Node *alloc(Drink input)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->drink = input;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

// �߰� �Լ�
void add(Drink input)
{
	switch (input.name)
	{
	case Coke:
		cokeTmp++;
		break;
	case Juice:
		juiceTmp++;
		break;
	case Sprite:
		spriteTmp++;
		break;
	default:
		break;
	}

	Node *newNode = alloc(input);
	Node *head = Head;

	if (head == NULL){
		Head = newNode;
	}
	else{
		while (head->next != NULL){
			head = head->next;
		}
		head->next = newNode;
		newNode->prev = head;
	}
}

// ���� �Լ�
void delete_(DrinkName name)
{
	if (name == -1)
		return;
	Node *head = Head;	

	if (head == NULL){
		printf("\n���ǱⰡ �� �зȾ�� �ФФ�");
		getch();
		return;
	}


	if (head->prev == NULL && head->next == NULL){
		Head = NULL;
	}
	else if (head->drink.name == name){
		Head = head->next;
		Head->prev = NULL;
	}
	else{
		while (1){
			if (head->next == NULL){
				if (head->drink.name == name){
					head->prev->next = NULL;
				}
				else{
					printf("\nǰ���Դϴ�.");
					getch();
					return;
				}
				break;
			}
			else if (head->drink.name == name){
				head->prev->next = head->next;
				head->next->prev = head->prev;
				break;
			}
			head = head->next;
		}
	}
	free(head);
	
	switch (name)
	{
	case Coke:
		cokeTmp--;
		balance -= 700;
		stack += 700;
		puts("\n�ݶ� ���Ծ��~~~");
		break;
	case Sprite:
		spriteTmp--;
		balance -= 800;
		stack += 800;
		puts("\n���̴ٰ� ���Ծ��~~~");
		break;
	case Juice:
		juiceTmp--;
		balance -= 1000;
		stack += 1000;
		puts("\n�ֽ��� ���Ծ��~~~");
		break;
	default:
		break;
	}
	getch();
}

char *on(int num){
	static char *ch[2] = { "��", "ǰ��" };
	if (num > 0){
		return ch[0];
	}
	else{
		return ch[1];
	}
}

// ����Ʈ ��� �Լ�
void printList()
{
	int count[3] = { 0 };
	Node *head = Head;

	while (head != NULL){
		//printDrink(head->drink);
		switch (head->drink.name)
		{
		case Coke:
			count[0]++;
			break;
		case Sprite:
			count[1]++;
			break;
		case Juice:
			count[2]++;
			break;
		default:
			break;
		}
		head = head->next;
	}

	//printf("�ݶ� : %d | ���̴� : %d | �ֽ� : %d\n", count[0], count[1], count[2]);
	printf("�ݶ� : %-4s | ���̴� : %-4s | �ֽ� : %-4s\n", on(count[0]), on(count[1]), on(count[2]));
	printf("%+11s | %+13s | %+11s\n", "700��", "800��", "1000��");
	
	puts("");
}

DrinkName check()
{
	switch (getch() - 48)
	{
	case 1:
		if (balance < 700){
			printf("���� �����ϴ�...");
			getch();
			system("cls");
			return -1;
		}
		return Coke;
	case 2:
		if (balance < 800){
			printf("���� �����ϴ�...");
			getch();
			system("cls");
			return -1;
		}
		return Sprite;
	case 3:
		if (balance < 1000){
			printf("���� �����ϴ�...");
			getch();
			system("cls");
			return -1;
		}
		return Juice;
	default:
		return -1;
	}
}