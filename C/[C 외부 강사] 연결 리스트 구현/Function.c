#include "Header.h"

Node* addNode(Node *currentNode, int num)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->value = num;
	newNode->next = NULL;

	currentNode->next = newNode;	// 현재 노드가 새로운 노드를 가리킴
	return newNode;
}

void printList(Node *headNext)
{
	Node *tn = headNext;
	while (tn != NULL){
		printf("\t%d", tn->value);
		tn = tn->next;
	}
	puts("");
}

void insertNode(Node *currentNode, int num)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	newNode->value = num;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
}

void searchInsertNode(Node *headNext, int num)
{
	Node *node = headNext;

	while (node != NULL){
		if (node->value < num - 1)
			node = node->next;
		else{
			insertNode(node, num);
			break;
		}
	}
}