#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "htb.h"

int	TABLE_SIZE;

ht *
Initialize(void)
{
	ht *newHashTable = (ht *)malloc(sizeof(ht));

	newHashTable->entries = malloc(sizeof(node *) * TABLE_SIZE);

	for (int i = 0; i < TABLE_SIZE; i++)
		newHashTable->entries[i] = NULL;	

	return newHashTable;
}

node *
MakeNode(const char *key, int value)
{
	node *newNode = (node *)malloc(sizeof(node));	

	newNode->key = malloc(strlen(key) + 1);
	strcpy(newNode->key, key);
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

uint64_t
Hash(const char *key)
{
	uint64_t hash = 0;

	for (ulong i = 0; i < strlen(key); i++)
		hash = (hash * 420) + (key[i] * 69);

	return hash % TABLE_SIZE;
}

void
Insert(ht *table, const char *key, int value)
{
	node	*newNode = MakeNode(key, value);
	uint64_t hash = Hash(key);

	if (!table->entries[hash])
		table->entries[hash] = newNode;
	else {
		node *traverse = table->entries[hash];

		while (traverse->next)
			traverse = traverse->next;

		traverse->next = newNode;
	}
}

bool
Search(ht *table, const char *key)
{
	uint64_t hash = Hash(key);

	if (table->entries[hash]) {
		node *traverse = table->entries[hash];
		while (traverse) {
			if (strcmp(traverse->key, key))
				traverse = traverse->next;
			else
				return true;
		}
	}
	
	return false;
}

void
Delete(ht *table, const char *key)
{
	uint64_t hash = Hash(key);

	if (table->entries[hash]) {
		uint64_t idx = 0;
		node *lead = table->entries[hash];

		while (strcmp(lead->key, key) && lead) {
			lead = lead->next;
			idx++;
		}

		if (lead) {
			printf("HI\n");
			if (!idx) {
				table->entries[hash] = lead->next;
				free(lead->key);
				free(lead);
			} else {
				node *follow = table->entries[hash];

				while (follow->next != lead)
					follow = follow->next;

				follow->next = lead->next;
				free(lead->key);
				free(lead);
			}
		}
	}
}

void
Clear(ht *table)
{
	node *lead, *follow;
	
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (table->entries[i]) {
			lead = table->entries[i];

			while (lead) {
				follow = lead;
				lead = follow->next;
				free(follow->key);
				free(follow);
			}

			table->entries[i] = NULL;
		}
	}
}

void
Dump(ht *table)
{
	node *traverse;

	for (int i = 0; i < TABLE_SIZE; i++) {
		if (table->entries[i]) {
			traverse = table->entries[i];

			printf("Slot[%4d]: ", i);

			while (traverse) {
				printf("{%s %d}-->", traverse->key,
				                     traverse->value);
				traverse = traverse->next;
			}
		printf("\n");
		}
	}
}

void
FreeTable(ht *table)
{
	Clear(table);
	free(table);
}
