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
		// �ӽ� ���� ����
		temp = (Node *)malloc(sizeof(Node));
		// �ӽ� ���� �ʱ�ȭ
		printf("%d��° ������ �Է� : ", i + 1);
		scanf("%d", &temp->data);
		temp->link = NULL;
		// ���� ù ����̸� ��忡 �ӽ� ������ ��
		if (head == NULL) 
			head = temp;
		else { // ���� �ӽ� ������ �����Ͱ� ����� �����ͺ��� ���� ��
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