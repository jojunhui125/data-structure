#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

typedef struct Stack
{
	Node* top;
}Stack;

void initStack(Stack* stack)
{
	stack->top = NULL;
}
int isEmpty(Stack* stack)
{
	return (stack->top == NULL);
}
void push(Stack* stack, int data)
{
	Node* now = (Node*)malloc(sizeof(Node));

	now->data = data;
	now->next = stack->top;
	stack->top = now;
}
int pop(Stack* stack)
{
	Node* now;
	int ret;

	if (isEmpty(stack))
	{
		return 0;
	}
	now = stack->top;
	ret = now->data;

	stack->top = now->next;
	free(now);

	return ret;
}

int main(void)
{
	int i;
	Stack stack;

	initStack(&stack);

	for (int i = 0; i <= 10; i++)
	{
		push(&stack, i);
	}

	while (!isEmpty(&stack))
	{
		printf("%d ", pop(&stack));
	}
	printf("\n");
	return 0;
}
