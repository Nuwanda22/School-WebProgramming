// �迭�� �̿��� ���� ť ����
#include <stdio.h>
#include <conio.h>

#define MAX 10

int queue[MAX];
int front, rear;

// ť�� �ʱ����
void clear_queue()
{
	front = rear;
}

// ����
int put()
{
	int k;
	if ((rear + 1) == front)			 // rear+1 == front �̸� ť�� �� �� ����
	{
		printf("\n    Queue overflow."); // ť�� �� á��.
		return -1;                       // -1 �� ���� ť�� ���°� �� á���� �ǹ�
	}

	printf("\n\nEnter ITEM: ");
	scanf("%d", &k);

	queue[rear] = k;                     // rear��ġ�� k���� �ְ�
	++rear;								 // rear�� 1���� ��Ű�� ��ȯ�ǰ� �Ѵ�.
	return k;                            // ���� ���� �����Ѵ�.
}

// ����
int get()
{
	int i;
	if (front == rear)                    // ť�� ��� �ִ� ����
	{
		printf("\n    Queue underflow."); // ť�� �����.
		return -1;                        // -1 �� ���� ť�� ���°� ��� ������ �ǹ�
	}
	i = queue[front];                     // ���� ���� i�� �޾Ƶд�.
	++front;							  // front���� 1���� ��Ű�� ��ȯ�ǰ� �Ѵ�.
	return i;                             // �� ���� �����Ѵ�.
}


// ť ���
void print_queue()
{
	int i;
	//printf("ť ���� : Front -> Rear\n");  // ť�� ��� �ִ� ����(front���� rear������)
	for (i = front; i != rear; ++i)			// ���� ť������ front�� ���� rear���� Ŭ�� ����.
		printf("\n%-6d", queue[i]);           // �׷��� ������ rear�� ���� ���� ���� ����, �������� ��ȯ��Ŵ
}

void choice(char ch)
{
	switch (ch)
	{
	case '1':
		put();
		break;
	case '2':
		get();
		break;
	case '3':
		print_queue();
		break;
	case '4':
		exit(0);

	default:
		printf("\n\nInvalid choice. Pleasr try again...\n");
	}
}

int main()
{
	int i;
	char ch;

	front = rear = 0;

	while (1)
	{
		printf("\n\n");
		puts("1. put");
		puts("2. get");
		puts("3. print");
		puts("4. exit");
		ch = getch();
		choice(ch);
	}
	/*
	printf("\nPut 5, 4, 7, 8, 2, 1");
	getchar();
	put(5);
	put(4);
	put(7);
	put(8);
	put(2);
	put(1);

	print_queue();
	getchar();
	printf("\nGet");
	getchar();
	i = get();
	print_queue();
	getchar();
	printf("\n   getting value is %d", i);
	getchar();
	printf("\nPut 3, 2, 5, 7");
	getchar();
	put(3);
	put(2);
	put(5);
	put(7);
	print_queue();
	getchar();
	printf("\nNow queue is full, put 3");
	getchar();
	put(3);
	print_queue();
	getchar();
	printf("\nInitialize queue");
	getchar();
	clear_queue();
	print_queue();
	getchar();
	printf("\nNow queue is empty, get");
	getchar();
	i = get();
	print_queue();
	getchar();
	printf("\n   getting value is %d", i);
	getchar();
	*/
	return 0;
}