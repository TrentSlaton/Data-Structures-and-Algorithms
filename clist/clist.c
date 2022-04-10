#include <stdio.h>
#include <stdlib.h>

#include "clist.h"

clist *
Initialize(void)
{
	clist *list = (clist *)malloc(sizeof(clist));
	list->head = NULL;
	list->tail = NULL;
	return list;
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
Push(clist *list, int value)
{
	node *newNode = MakeNode(value);
	
	if (!list->head) {
		newNode->next = newNode;
		list->head = newNode;
		list->tail = newNode;
	}
	else {
		newNode->next = list->head;
		list->head = newNode;
		list->tail->next = list->head;
	}
}

void
PushTail(clist *list, int value)
{
	node *newNode = MakeNode(value);

	if (!list->head)
		Push(list, value);
	else {
		newNode->next = list->head;
		list->tail->next = newNode;
	}
}

void
PushN(clist *list, int value, int n)
{
	int size = n % Size(list);
	if (!list->head || n < 1 || !size)
		Push(list, value);
	else {
		node *newNode = MakeNode(value);
		node *lead = list->head;
		node *follow = list->head;

		for (int i = 0; i < size; i++)
			lead = lead->next;
		for (int i = 0; i <= size- 2; i++)
			follow = follow->next;

		follow->next = newNode;
		newNode->next = lead;
	}
}

void
Pop(clist *list)
{
	if (!list->head)
		return;
	else if (list->head == list->tail) {
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else {
		node *tmp = list->head;
		list->head = list->head->next;
		list->tail->next = list->head;
		free(tmp);
	}
}

void
PopTail(clist *list)
{
	if (!list->head)
		return;
	else if (list->head == list->tail) {
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else {
		node *lead = list->head;
		node *follow;

		while (lead != list->tail) {
			follow = lead;
			lead = follow->next;
		}
		list->tail = follow;
		list->tail->next = list->head;
		free(lead);
	}
}

void
PopN(clist *list, int n)
{
	int size = n % Size(list);

	if (!list->head)
		return;
	else if (!size)
		Pop(list);
	else {
		node *lead = list->head;
		node *follow = list->head;

		for (int i = 0; i <= size; i++)
			lead = lead->next;
		for (int i = 0; i <= size - 2; i++)
			follow = follow->next;

		free(follow->next);
		follow->next = lead;
	}
}

int
Size(clist *list)
{
	int count = 0;
	if (!list->head)
		return count;
	else {
		node *traverse = list->head;

		do {
			count++;
			traverse = traverse->next;
		} while (traverse != list->head);
	}

	return count;
}

void
Clear(clist *list)
{
	if (!list->head)
		return;
	else {
		while (list->head != list->tail)
			Pop(list);
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
}

void
FreeList(clist *list)
{
	Clear(list);
	free(list);
}

void
Dump(clist *list)
{
	int size = Size(list);

	if (!size)
		printf("[  *]<--[Head]<--[Tail]\n");
	else if (size == 1)
		printf("[%3d]<--[Head]<--[Tail]\n", list->head->value);	
	else if (size < 10) {
		node *traverse = list->head;
		printf("[%3d]<--[Head]\n", traverse->value);
		traverse = traverse->next;
		while (traverse->next != list->head) {
			printf("[%3d]\n", traverse->value);
			traverse = traverse->next;
		}
		printf("[%3d]<--[Tail]\n", traverse->value);
	} else {
		node *lead = list->head;
		node *follow = list->head;
		size -= 4;

		for (; size; size--)
			lead = lead->next;

		size = Size(list) - 3;

		printf("[%3d]<---[Head]\n", follow->value);
		follow = follow->next;
		for (int i = 0; i < 3; follow = follow->next, i++)
			printf("[%3d]\n", follow->value);

		for (int i = 0; i < 3; i++)
			printf("...\n");

		for (; lead->next != list->head; lead = lead->next)
			printf("[%3d]\n", lead->value);
		printf("[%3d]<---[Tail]\n", lead->value);
	}
}
