#include <stdio.h>
#include <stdlib.h>


struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};


struct Node* root;


void initTree(int data)
{
	struct Node* New;
	New = (struct Node*)malloc(sizeof(struct Node));

	root = New;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
}

struct Node* addchild(struct Node* parent, int data)
{
	if ((parent->left) != NULL && (parent->right) != NULL)
	{
		printf("FULL\n");
		return 0;
	}
	struct Node* New;
	New = (struct Node*)malloc(sizeof(struct Node));
	New->data = data;
	New->left = NULL;
	New->right = NULL;

	if (parent->left == NULL)
	{
		parent->left = New;
	}
	else if (parent->right == NULL)
	{
		parent->right == New;
	}
	return New;
}
void printorder(struct Node* r)
{
	printf("%d\n", r->data);
	if (r->left)
	{
		printforder(r->left);
	}
	if (r->right)
	{
		printorder(r->right);
	}




}
int main(void)
{
	struct Node* l;
	struct Node* r;

	initTree(1);

	l = addchild(root, 2);
	r = addchild(root, 3);

	addchild(l, 4);
	addchild(l, 5);
	addchild(r, 6);
	addchild(r, 7);

	printorder(root);
}
