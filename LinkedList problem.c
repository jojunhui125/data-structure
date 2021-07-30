#include <stdio.h> 
#include <stdlib.h>


struct node
{
	char data;
	struct node* next;
};

struct node *head = NULL;

void addnode(char a)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->data = a;
	struct node* tempnode = head;

	if (tempnode != NULL)
	{
		while (tempnode->next != NULL)
		{
			tempnode = tempnode->next;
		}
		tempnode->next = newnode;
	}
	else
	{
		head = newnode;
	}

	
}

void deletenode(char a)
{
	struct node* tempnode = head;
	struct node* prenode;

	while (tempnode != NULL)
	{
		if (a == tempnode->data)
		{
			if (tempnode == head)
			{
				head = tempnode->next;
			}
			else
			{
				prenode->next = tempnode->next;
			}
			free(tempnode);
			break;
		}
		prenode = tempnode;
		tempnode = tempnode->next;
	}
}

void printnode(void)
{
	struct node* tempnode = head;

	if (tempnode == NULL)
	{
		printf("empty\n");
		return;
	}
	if (tempnode->next == NULL)
	{
		printf("%cL\n", tempnode->data);
	}
	else
	{
		while (tempnode != NULL)
		{
			printf("%c  ", tempnode->data);
			tempnode = tempnode->next;
		}
		printf("\n");

	}
	
}


int main(void)
{
	addnode('A');
	addnode('B');
	addnode('C');
	addnode('D');
	addnode('E');
	addnode('F');
	printnode();


	deletenode('B');
	deletenode('D');
	deletenode('F');

	printnode();

	return 0;
}


