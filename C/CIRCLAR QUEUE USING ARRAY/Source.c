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
		puts("\t1.����");
		puts("\t2.����");
		puts("\t3.���");
		puts("\t4.����");
		
		printf("\n���ϴ� �۾��� �Է��Ͻÿ�: ");
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
		printf("\n\n�߸��� �����Դϴ�. �ٽ� �Է��� �ּ���...\n");
	}
}

void insert()
{
	if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
		printf("\n\nť�� �� á���ϴ�. (Overflow)");
	else{
		printf("\n\n�Է��Ͻÿ�: ");
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
		printf("\n\n�Էµ� �ڷ�: %d\n", item);
	}
}

void delet()
{
	if (front == -1)
		printf("\n\nť�� ����ֽ��ϴ�.(Underflow)\n");
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

		printf("\n\n������ �ڷ�: %d", item);
	}
}

void display()
{
	int i;

	if ((front == -1)) //(front == rear + 1)
		printf("\n\nť�� ����ֽ��ϴ�.(Underflow)\n");
	else{
		printf("\n\n");

		for (i = front; i <= rear; i++)
			printf("\t%d", queue[i]);
	}
}