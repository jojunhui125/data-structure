#include <stdio.h> 
#include <stdlib.h>

struct node
{
	struct node* next;
	int data;
};

int main(void)
{
	struct node* head = malloc(sizeof(struct node));

	struct node* node1 = malloc(sizeof(struct node));
	head->next=node1;
	node1->data = 10;

	struct node* node2 = malloc(sizeof(struct node));
	node1->next=node2;
	node2->data = 20;

	node2->next = NULL;

	struct node* cur = head->next;

	while (cur != 0)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}

	free(node2);
	free(node1);
	free(head);


	return 0;
}
