#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
}Node;

Node* addNode(Node *currentNode, int num);
void printList(Node *tn);
void insertNode(Node *tn, int num);
void searchInsertNode(Node *headNext, int num);

#endif HEADER_H