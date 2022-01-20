#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void stackListPush(struct Node **stack, int val)
{
	struct Node* top = (struct Node*)malloc(sizeof(struct Node));
	top->data = val;
	top->next = *stack;
	*stack = top;
}

int stackListPop(struct Node **stack)
{
	if (!(*stack))
		return -1;
	struct Node *top = *stack;
	*stack = (*stack)->next;
	int val = top->data;
	free(top);
	return val;
}

int main()
{
	struct Node *stackList = NULL;
	stackListPush(&stackList, 10);
	stackListPush(&stackList, 20);
	stackListPush(&stackList, 30);
	printf("pop %d\n",stackListPop(&stackList));
	printf("pop %d\n",stackListPop(&stackList));
}
