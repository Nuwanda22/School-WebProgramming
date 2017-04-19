#include <stdio.h>
#include <stdlib.h>

#define CONSTARRAYSIZE 5

typedef struct tagLinkedList
{
	char *name;
	char *tel;
	char *addr;
	struct tagLinkedList *next;
}ADDR;

void addNode(int num);
void printNode();

int main()
{
	/*int i, *parr[CONSTARRAYSIZE];

	for (i = 0; i < CONSTARRAYSIZE; i++)
		parr[i] = malloc(sizeof(int));

	for (i = 0; i < CONSTARRAYSIZE; i++)
		printf("%d\n", parr[i]);

	for (i = 0; i < CONSTARRAYSIZE; i++)
		free(parr[i]);*/

	ADDR *newNode, *currentNode;
	ADDR node = { "전성우", "010-4842-9365", "대전" };

	currentNode = &node;

	newNode = malloc(sizeof(ADDR));
	if (newNode == NULL){
		return 0;
	}

	currentNode->next = newNode;
	currentNode = newNode;
	currentNode->next = NULL;

	return 0;
}

void addNode(int num)
{

}

void printNode()
{

}