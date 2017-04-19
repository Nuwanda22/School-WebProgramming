/**** Program to Implement Circular Queue using Array ****/

#include <stdio.h>
#include <Windows.h>
#define SIZE 5

void choice(char);
void insert();
void delet();
void display();

int queue[SIZE], rear = -1, front = -1, item;

main()
{
	int ch;
	do
	{
		printf("\n\n");
		puts("\t1.삽입");
		puts("\t2.삭제");
		puts("\t3.출력");
		puts("\t4.종료");
		
		printf("\n원하는 작업을 입력하시오: ");
		scanf("%d", &ch);
		choice(ch);
	} while (1);
	getch();
}

void choice(char ch)
{
	switch (ch)
	{
	case 1:
		insert();
		break;
	case 2:
		delet();
		break;
	case 3:
		display();
		break;
	case 4:
		exit(0);
	default:
		printf("\n\n잘못된 선택입니다. 다시 입력해 주세요...\n");
	}
}

void insert()
{
	if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
		printf("\n\n큐가 꽉 찼습니다. (Overflow)");
	else{
		printf("\n\n입력하시오: ");
		scanf("%d", &item);

		if (rear == -1){
			rear = 0;
			front = 0;
		}
		else if (rear == SIZE - 1)
			rear = 0;
		else
			rear++;

		queue[rear] = item;
		printf("\n\n입력된 자료: %d\n", item);
	}
}

void delet()
{
	if (front == -1)
		printf("\n\n큐가 비어있습니다.(Underflow)\n");
	else{
		item = queue[front];

		if (front == rear){
			front = -1;
			rear = -1;
		}
		else if (front == SIZE - 1)
			front = 0;
		else
			front++;

		printf("\n\n삭제된 자료: %d", item);
	}
}

void display()
{
	int i;

	if ((front == -1)) //(front == rear + 1)
		printf("\n\n큐가 비어있습니다.(Underflow)\n");
	else{
		printf("\n\n");

		for (i = front; i <= rear; i++)
			printf("\t%d", queue[i]);
	}
}