#include <stdio.h>
#include <stdlib.h>

typedef struct intNode
{
	int data;
	struct intNode* nextNode;
}IntNode;

IntNode* nodeMalloc()
{
	return (IntNode *)malloc(sizeof(IntNode));
}

void nodeInit(IntNode* node, int data)
{
	node->data = data;
	node->nextNode = NULL;
}

int main()
{
	IntNode *node = nodeMalloc();
}