#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "q.h"

queue *
Initialize(void)
{
	queue *newQueue = (queue *)malloc(sizeof(queue));

	newQueue->front = NULL;
	newQueue->rear = NULL;

	return newQueue;
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
Enqueue(queue *q, int value)
{
	node *newNode = MakeNode(value);

	if (!q->front) {
		q->front = newNode;
		q->rear = newNode;
	} else {
		q->rear->next = newNode;
		q->rear = newNode;
	}
}

void
Dequeue(queue *q)
{
	if (!q->front)
		return;
	else {
		node *tmp = q->front;

		if (!q->front->next) {
			q->front = NULL;
			q->rear = NULL;
		} else
			q->front = q->front->next;

		free(tmp);
	}
}

void
Clear(queue *q)
{
	if (!q->front)
		return;
	else {
		while (q->front->next)
			Dequeue(q);

		free(q->front);
		q->front = NULL;
		q->rear = NULL;
	}
}

int
Size(queue *q)
{
	int count = 0;

	if (!q->front)
		return count;
	else {
		node *traverse = q->front;

		while (traverse) {
			count++;
			traverse = traverse->next;
		}
	}

	return count;
}

void
Dump(queue *q)
{
	int size = Size(q);

	if (!size)
		printf("[  *]<--[Front]<--[Rear]\n");
	else if (size == 1)
		printf("[%3d]<--[Front]<--[Rear]\n", q->front->value);
	else if (size < 10) {
		node *traverse = q->front;

		printf("[%3d]<--[Front]\n", traverse->value);
		traverse = traverse->next;

		while (traverse->next) {
			printf("[%3d]\n", traverse->value);
			traverse = traverse->next;
		}

		printf("[%3d]<--[Rear]\n", traverse->value);
	} else {
		node *lead = q->front;
		node *follow = q->front;
		size -= 4;

		for(; size; size--)
			lead = lead->next;

		printf("[%3d]<--[Front]\n", follow->value);
		follow = follow->next;

		for (int i = 0; i < 3; follow = follow->next, i++)
			printf("[%3d]\n", follow->value);

		for (int i = 0; i < 3; i++)
			printf("...\n");

		for (; lead->next; lead = lead->next)
			printf("[%3d]\n", lead->value);
		printf("[%3d]<--[Rear]\n", lead->value);
	}
}

void
FreeQueue(queue *q)
{
	Clear(q);
	free(q);
}
