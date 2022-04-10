#include <stdio.h>
#include <stdlib.h>

#include "slist.h"

slist *
Initialize(void)
{
	slist *list = (slist *)malloc(sizeof(slist));	
	list->head = NULL;
	return list;
}

node *
MakeNode(int value)
{
	node *n = (node *)malloc(sizeof(node));	
	n->value = value;
	n->next = NULL;
	return n;
}

void
Push(slist *list, int value)
{
	node *n = MakeNode(value);
	n->next = list->head;
	list->head = n;
}

void
PushN(slist *list, int value, int n)
{
	node *newNode = MakeNode(value);
	node *lead = list->head;
	node *follow;

	if (!lead || n < 1) {
		newNode->next = list->head;
		list->head = newNode;
	} else {
		while (lead && n > 0) {
			follow = lead;
			lead = follow->next;
			n--;
		}

		newNode->next = lead;
		follow->next = newNode;
	}
}

void
PushTail(slist *list, int value)
{
	node *newNode = MakeNode(value);
	node *lead = list->head;
	node *follow;

	if (!lead) {
		newNode->next = list->head;
		list->head = newNode;
	} else {
		while (lead) {
			follow = lead;
			lead = follow->next;
		}

		newNode->next = lead;
		follow->next = newNode;
	}
}

void
Pop(slist *list)
{
	if (!list->head)
		return;
	else {
		node *tmp = list->head->next;
		free(list->head);
		list->head = tmp;
	}
}

void
PopN(slist *list, int n)
{
	if (!list->head)
		return;
	else if (!list->head->next || n < 1)
		Pop(list);
	else {
		node *lead = list->head;
		node *follow = list->head;

		for (int i = 0; i <= n && lead; i++)
			lead = lead->next;
		for (int i = 0; i <= n - 2 && follow; i++)
			follow = follow->next;

		if (!follow)
			PopTail(list);
		else {
			free(follow->next);
			follow->next = lead;
		}
	}
}

void
PopTail(slist *list)
{
	if (!list->head)
		return;
	else if (!list->head->next)
		Pop(list);
	else {
		node *lead = list->head;
		node *follow;

		while (lead->next) {
			follow = lead;
			lead = follow->next;
		}

		free(follow->next);
		follow->next = NULL;
	}
}

void
Clear(slist *list)
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

int
Size(slist *list)
{
	int count = 0;
	node *traverse = list->head;

	for (; traverse; count++, traverse = traverse->next)
		;

	return count;
}

void
Dump(slist *list)
{
	int size = Size(list);

	if (!size)
		return;
	else if (size < 10) {
		node *traverse = list->head;

		for (int i = 0; traverse; traverse = traverse->next, i++)
			printf("(%2d)[%3d]\n", i + 1, traverse->value);
	}
	else {
		node *lead = list->head;
		node *follow = list->head;
		size -= 4;

		for (; size; size--)
			lead = lead->next;
		size = Size(list) - 3;

		for (int i = 0; i < 4; follow = follow->next, i++)
			printf("(%2d)[%3d]\n", i + 1, follow->value);
		
		for (int i = 0; i < 3; i++)
			printf("...\n");

		for (;lead; lead = lead->next, size++)
			printf("(%2d)[%3d]\n", size, lead->value);
	}
}

void
FreeSList(slist *list)
{
	Clear(list);
	free(list);
}
