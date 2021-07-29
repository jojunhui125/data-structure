#include <stdio.h> 
#include <stdlib.h>

typedef struct Node
{
	struct Node* link;
	int data;
}Node;

Node* Head = NULL;

void appendNode(int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	Node* tempnode = Head;
	newnode->data = data;
	newnode->link = NULL;

	if (tempnode != 0)
	{
		while (tempnode->link != 0)
		{
			tempnode = tempnode->link;
		}
		tempnode->link = newnode;
	}
	else
	{
		Head = newnode;
	}
}

void deleteNode(int data)
{
	Node* tempnode = Head;
	Node* prenode = NULL;

	while (tempnode != NULL)
	{
		if (data == tempnode->data)
		{
			if (tempnode == Head)
			{
				Head = tempnode->link;
			}
			else
			{
				prenode->link = tempnode->link;
			}
			free(tempnode);
			break;
		}
		prenode = tempnode;
		tempnode = tempnode->link;
	}
}

void printNode(void)
{
	Node* tempnode = Head;

	if (tempnode == NULL)
	{
		printf("empty\n");
		return;
	}
	if (tempnode->link == NULL)
	{
		printf("%d --> NULL \n", tempnode->data);
	}
	else
	{
		while (tempnode != NULL)
		{
			printf("%d --> ", tempnode->data);
			tempnode = tempnode->link;
		}
		printf("NULL\n");
	}
}


int main(void)
{
	appendNode(1);
	printNode();
	appendNode(2);
	printNode();
	appendNode(3);
	printNode();


	deleteNode(3);
	printNode();
	deleteNode(2);
	printNode();
	deleteNode(1);
	printNode();


	
	return 0;
}





