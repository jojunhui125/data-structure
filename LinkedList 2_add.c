#include <stdio.h> 
#include <stdlib.h>

struct node
{
	struct node* next;
	int data;
};

void add(struct node* target, int data)
{
	struct node* newnode = malloc(sizeof(struct node));
	newnode->next = target->next;
	newnode->data = data;
	target->next = newnode;
}

int main(void)
{
	struct node* head = malloc(sizeof(struct node));
	head->next = NULL;

	add(head, 10);
	add(head, 30);
	add(head, 50);

	struct node* cur = head->next;

	while (cur != NULL)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	cur = head->next;

	while (cur != NULL)
	{
		struct node* next = cur->next;
		free(cur);
		cur = next;
	}
	free(head);
	
	return 0;
}
