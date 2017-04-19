#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct node
{
	int data;
	struct node *link;
}Node;

int main()
{
	Node *head = NULL, *temp, *prev, *p;

	for (int i = 0; i < MAX; i++){
		// 임시 공간 생성
		temp = (Node *)malloc(sizeof(Node));
		// 임시 공간 초기화
		printf("%d번째 데이터 입력 : ", i + 1);
		scanf("%d", &temp->data);
		temp->link = NULL;
		// 만약 첫 노드이면 헤드에 임시 공간을 줌
		if (head == NULL) 
			head = temp;
		else { // 만약 임시 공간의 데이터가 헤드의 데이터보다 작을 때
			if (temp->data < head->data){
				temp->link = head;
				head = temp;
			}
			else{
				p = head;

				while (p != NULL&&temp->data > head->data){
					
					
				}
				

			}
		}
	}

	
}