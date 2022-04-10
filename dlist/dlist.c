#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

dlist *
Initialize(void)
{
	dlist *list = (dlist *)malloc(sizeof(dlist));
	list->head = NULL;
	return list;
}

node *
MakeNode(int value)
{
	node *newNode = (node *)malloc(sizeof(node));

	newNode->value = value;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void
Push(dlist *list, int value)
{
	node *newNode = MakeNode(value);

	newNode->next = list->head;
	list->head = newNode;
	if (list->head->next)
		newNode->next->prev = newNode;
}

void
PushTail(dlist *list, int value)
{
	if (!list->head)
		Push(list, value);
	else {
		node *newNode = MakeNode(value);
		node *lead = list->head;
		node *follow;

		while (lead) {
			follow = lead;
			lead = follow->next;
		}

		newNode->next = lead;
		newNode->prev = follow;
		follow->next = newNode;
	}
}

void
PushN(dlist *list, int value, int n)
{
	if (!list->head || n < 1)
		Push(list, value); 
	else {
		node *lead = list->head;
		node *follow = list->head;

		for (int i = 0; i < n && lead; i++)
			lead = lead->next;
		for (int i = 0; i < n - 1 && follow; i++)
			follow = follow->next;
		if (!follow)
			PushTail(list, value);
		else {
			node *newNode = MakeNode(value);

			newNode->next = lead;
			newNode->prev = follow;
			follow->next = newNode;
			if (lead)
				lead->prev = newNode;
		}
	}
}

void
Pop(dlist *list)
{
	if (!list->head)
		return;
	else {
		node *tmp = list->head;
		list->head = list->head->next;
		free(tmp);
		if (list->head)
			list->head->prev = NULL;
	}
}

void
PopTail(dlist *list)
{
	if (!list->head)
		return;
	else {
		node *lead = list->head;
		node *follow;

		while (lead) {
			follow = lead;
			lead = follow->next;
		}

		if (follow->prev)
			follow->prev->next = NULL;
		else
			list->head = NULL;

		free(follow);
	}
}

void
PopN(dlist *list, int n)
{
	if (!list->head)
		return;
	else if (n < 1)
		Pop(list);
	else {
		node *lead = list->head;
		node *follow = list->head;

		for (int i = 0; i <= n && lead; i++)
			lead = lead->next;
		for (int i = 0; i <= n - 2 && follow; i++)
			follow = follow->next;

		if (!follow || !follow->next)
			PopTail(list);
		else {
			free(follow->next);
			follow->next = lead;
			if (lead)
				lead->prev = follow;
		}
	}
}

int
Size(dlist *list)
{
	int count = 0;
	node *traverse = list->head;

	for (; traverse; count++, traverse = traverse->next)
		;

	return count;
}

void
Clear(dlist *list)
{
	if (!list->head)
		return;
	else {
		while (list->head->next)
			Pop(list);
		free(list->head);
		list->head = NULL;
	}
}

void
FreeList(dlist *list)
{
	Clear(list);
	free(list);
}

void
Dump(dlist *list)
{
	int	size = Size(list);

	if (!size)
		return;
	else if (size == 1)
		printf("[%3d]<--[Head]\n", list->head->value);
	else if (size < 10) {
		node *traverse = list->head;
		node *boing;

		printf("[%3d]<---[Head]\n", traverse->value);
		traverse = traverse->next;
		while (traverse->next) {
			printf("[%3d]\n", traverse->value);
			traverse = traverse->next;
		}

		boing = traverse;
		printf("[%3d]<---[Boing!!!]\n", traverse->value);
		traverse = boing->prev;

		while (traverse->prev) {
			printf("[%3d]\n", traverse->value);
			traverse = traverse->prev;
		}
		printf("[%3d]<---[Head]\n", traverse->value);
	} else {
		node *first = list->head;
		node *last = list->head;
		node *firstrev = list->head;
		int space = size - 4;

		for (; space; space--)
			last = last->next;

		for (int i = 0; i < 4; i++)
			firstrev = firstrev->next;

		printf("[%3d]<--[Head]\n", first->value);

		first = first->next;

		for (int i = 0; i < 4; first = first->next, i++)
			printf("[%3d]\n", first->value);

		for (int i = 0; i < 3; i++)
			printf("...\n");

		for (; last->next; last = last->next)
			printf("[%3d]\n", last->value);

		printf("[%3d]<--[Boing!!!]\n", last->value);
		last = last->prev;

		for (int i = 0; i < 3; last = last->prev, i++)
			printf("[%3d]\n", last->value);

		for (int i = 0; i < 3; i++)
			printf("...\n");

		for (; firstrev->prev; firstrev = firstrev->prev)
			printf("[%3d]\n", firstrev->value);
		printf("[%3d]<--[Head]\n", firstrev->value);
	}
}
