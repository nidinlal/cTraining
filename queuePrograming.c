#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int val;
	struct Node *next;
	struct Node *previous;
};

void push(struct Node **tail, int val)
{
	struct Node *last = (*tail)->previous;
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->val = val;
	node->next = *tail;
	node->previous = last;
	last->next = node;
	(*tail)->previous = node;
}

int pop(struct Node **head)
{
	if ((*head)->next->next == NULL)
		return -1;
	struct Node *first = (*head)->next;
	struct Node *second = first->next;
	int val = first->val;
	(*head)->next = second;
	second->previous = *head;
	free(first);
	return val;
}

int main()
{
	struct Node *head = (struct Node*)malloc(sizeof(struct Node));
	struct Node *tail = (struct Node*)malloc(sizeof(struct Node));
	head->val = -1;
	head->next = tail;
	head->previous = NULL;
	tail->val = -1;
	tail->next = NULL;
	tail->previous = head;
	push(&tail,10);
	push(&tail,20);
	push(&tail,30);
	printf("pop %d\n",pop(&head));
	printf("pop %d\n",pop(&head));
}
