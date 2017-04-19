// 배열을 이용한 원형 큐 구현
#include <stdio.h>
#include <conio.h>

#define MAX 10

int queue[MAX];
int front, rear;

// 큐의 초기상태
void clear_queue()
{
	front = rear;
}

// 삽입
int put()
{
	int k;
	if ((rear + 1) == front)			 // rear+1 == front 이면 큐가 꽉 찬 상태
	{
		printf("\n    Queue overflow."); // 큐가 꽉 찼다.
		return -1;                       // -1 의 값은 큐의 상태가 꽉 찼음을 의미
	}

	printf("\n\nEnter ITEM: ");
	scanf("%d", &k);

	queue[rear] = k;                     // rear위치에 k값을 넣고
	++rear;								 // rear를 1증가 시키되 순환되게 한다.
	return k;                            // 넣은 값을 리턴한다.
}

// 삭제
int get()
{
	int i;
	if (front == rear)                    // 큐가 비어 있는 상태
	{
		printf("\n    Queue underflow."); // 큐가 비었다.
		return -1;                        // -1 의 값은 큐의 상태가 비어 있음을 의미
	}
	i = queue[front];                     // 빼는 값을 i에 받아둔다.
	++front;							  // front값을 1증가 시키되 순환되게 한다.
	return i;                             // 뺀 값을 리턴한다.
}


// 큐 출력
void print_queue()
{
	int i;
	//printf("큐 내용 : Front -> Rear\n");  // 큐에 들어 있는 내용(front에서 rear전까지)
	for (i = front; i != rear; ++i)			// 원형 큐에서는 front의 값이 rear보다 클수 있음.
		printf("\n%-6d", queue[i]);           // 그렇기 때문에 rear와 같지 않을 동안 수행, 증가값도 순환시킴
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