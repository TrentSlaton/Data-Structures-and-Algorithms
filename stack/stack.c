#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

stack *
Initialize(void)
{
	stack *newStack = (stack *)malloc(sizeof(stack));

	newStack->top = NULL;

	return newStack;
}

node *
MakeNode(int value)
{
	node *newNode = (node *)malloc(sizeof(node));

	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

void
Push(stack *st, int value)
{
	node *newNode = MakeNode(value);

	newNode->next = st->top;
	st->top = newNode;
}

void
Pop(stack *st)
{
	if (!st->top)
		return;
	else {
		node *tmp = st->top;

		st->top = st->top->next;
		free(tmp);
	}
}

void
Clear(stack *st)
{
	if (!st->top)
		return;
	else {
		while (st->top->next)
			Pop(st);

		node *tmp = st->top;
		st->top = NULL;
		free(tmp);
	}
}

int
Size(stack *st)
{
	int count = 0;

	if (!st->top)
		return count;
	else {
		node *traverse = st->top;

		while (traverse) {
			count++;
			traverse = traverse->next;
		}
	}

	return count;
}

void
Dump(stack *st)
{
	int size = Size(st);

	if (!size)
		printf("[  *]<--[Top]\n");	
	else if (size < 10) {
		node *traverse = st->top;

		printf("[%3d]<---[Top]\n", traverse->value);
		traverse = traverse->next;
		while (traverse) {
			printf("[%3d]\n", traverse->value);
			traverse = traverse->next;
		}
	} else {
		node *lead = st->top;
		node *follow = st->top;
		size -= 4;

		for (; size; size--)
			lead = lead->next;

		printf("[%3d]<---[Top]\n", follow->value);
		follow = follow->next;
		for (int i = 0; i < 3; follow = follow->next, i++)
			printf("[%3d]\n", follow->value);

		for (int i = 0; i < 3; i++)
			printf("...\n");

		for (; lead; lead = lead->next)
			printf("[%3d]\n", lead->value);
	}
}

void
FreeStack(stack *st)
{
	Clear(st);
	free(st);
}
