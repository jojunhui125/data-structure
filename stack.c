#include <stdio.h>
#define MAXSIZE 10
int stack[MAXSIZE];
int top;
void init_stack()
{
	top = -1;
}
int push(int val)
{
	if (top >= MAXSIZE - 1)
	{
		printf("\nStack OverFlow\n");
		return -1;
	}
	stack[++top] = val;
	return val;

}
int pop(void)
{
	if (top < 0)
	{
		printf("\nUnder Flow\n");
		return -1;
	}
	return stack[top--];
}
void print_stack()
{
	for (int i = 0; i <= top; i++)
	{
		printf("%d ", stack[i]);
	}
}
void main(void)
{
	int i;
	init_stack();

	printf("\nPush 5,4,7,8,3,2,1");

	push(5);
	push(4);
	push(7);
	push(8);
	push(3);
	push(2);
	push(1);
	print_stack();

	printf("\npop");
	i = pop();
	print_stack();
	printf("\npopped value is %d\n", i);

	printf("\nPush 3,2,5,7,2");
	
	push(3);
	push(2);
	push(5);
	push(7);
	push(2);
	print_stack();
	printf("\nNow stack is full,push 3");
	push(3);
	print_stack();

	printf("\nIni stack");
	init_stack();
	print_stack();

	printf("\nNow stacekasdad");
	i = pop();
	print_stack();
	printf("\n popped value is %d\n", i);
}
