#include <stdio.h> 

void hanoi(int n, char from, char by, char to)
{
	
	if (n == 1)
	{
		printf("%c ->%c\n", from, to);
		return 0;
	}
	else
	{
		hanoi(n - 1, from, to, by);
		printf("%c ->%c\n", from, to);
		hanoi(n - 1, by, from, to);
	}
}

int main(void)
{
	hanoi(8, 'A', 'B', 'C');
	return 0;
}
