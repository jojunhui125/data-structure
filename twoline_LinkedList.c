#include <stdio.h> 
#include <stdlib.h>

typedef struct node
{
	struct node* pre;
	struct node* next;
	int data;
}Node;

void insertnode(Node**node, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	Node* tempnode = *node;

	newnode->next = NULL;
	newnode->pre = NULL;
	newnode->data = data;
	printf("INSERT: %d\n", data);

	if (tempnode == NULL)
	{
		*node = newnode;
		return;
	}
	while (tempnode->next != NULL)
	{
		tempnode = tempnode->next;
	}
	tempnode->next = newnode;
	newnode->pre = tempnode;
	
		
}

int deletenode(Node** node, int data)
{
	Node* tempnode = *node;
	Node* delnode = NULL;

	printf("DELETE: %d\n", data);

	if ((*node)->data == data)
	{
		if ((*node)->next != NULL)
		{
			*node = (*node)->next;
			(*node)->pre = NULL;
		}
		else
		{
			*node = NULL;
		}
		free(tempnode);
		return 0;
	}
	while (tempnode->next != NULL)
	{
		if ((tempnode->next)->data == data)
		{
			delnode = tempnode->next;
			tempnode->next = (tempnode->next)->next;
			(tempnode->next)->pre = tempnode;
			free(delnode);
			return 0;
		}
		tempnode = tempnode->next;
	}
	printf("데이터 발견 못함\n");
	return -1;
}
void displaynode(Node* node)
{
	Node* tempnode = node;
	Node* prenode = NULL;
	printf("Node list:");
	while (tempnode != NULL)
	{
		printf("%3d", tempnode->data);
		prenode = tempnode;
		tempnode = tempnode->next;
	}
	printf("||");

	while (prenode != NULL)
	{
		printf("%3d", prenode->data);
		prenode = prenode->pre;
	}
	printf("END\n");
}


int main(void)
{
	Node* Head = NULL;

	insertnode(&Head, 10);
	insertnode(&Head, 30);
	insertnode(&Head, 20);
	insertnode(&Head, 50);
	displaynode(Head);

	deletenode(&Head, 10);
	displaynode(Head);
	deletenode(&Head, 20);
	displaynode(Head);
	deletenode(&Head, 30);
	displaynode(Head);
	deletenode(&Head, 50);
	displaynode(Head);
	
	return 0;
}





