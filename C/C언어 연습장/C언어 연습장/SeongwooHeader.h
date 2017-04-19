// 전성우 헤드

#include "Mirim.h"

// 노드 할당 함수
Node *alloc(Drink input)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->drink = input;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

// 추가 함수
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

// 삭제 함수
void delete_(DrinkName name)
{
	if (name == -1)
		return;
	Node *head = Head;	

	if (head == NULL){
		printf("\n자판기가 다 털렸어요 ㅠㅠㅠ");
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
					printf("\n품절입니다.");
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
		puts("\n콜라가 나왔어용~~~");
		break;
	case Sprite:
		spriteTmp--;
		balance -= 800;
		stack += 800;
		puts("\n사이다가 나왔어용~~~");
		break;
	case Juice:
		juiceTmp--;
		balance -= 1000;
		stack += 1000;
		puts("\n주스가 나왔어용~~~");
		break;
	default:
		break;
	}
	getch();
}

char *on(int num){
	static char *ch[2] = { "●", "품절" };
	if (num > 0){
		return ch[0];
	}
	else{
		return ch[1];
	}
}

// 리스트 출력 함수
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

	//printf("콜라 : %d | 사이다 : %d | 주스 : %d\n", count[0], count[1], count[2]);
	printf("콜라 : %-4s | 사이다 : %-4s | 주스 : %-4s\n", on(count[0]), on(count[1]), on(count[2]));
	printf("%+11s | %+13s | %+11s\n", "700원", "800원", "1000원");
	
	puts("");
}

DrinkName check()
{
	switch (getch() - 48)
	{
	case 1:
		if (balance < 700){
			printf("돈이 부족하다...");
			getch();
			system("cls");
			return -1;
		}
		return Coke;
	case 2:
		if (balance < 800){
			printf("돈이 부족하다...");
			getch();
			system("cls");
			return -1;
		}
		return Sprite;
	case 3:
		if (balance < 1000){
			printf("돈이 부족하다...");
			getch();
			system("cls");
			return -1;
		}
		return Juice;
	default:
		return -1;
	}
}