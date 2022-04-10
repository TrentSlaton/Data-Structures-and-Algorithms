#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

bst *
Initialize(void)
{
	bst *newBST  = (bst *)malloc(sizeof(bst));

	newBST->root = NULL;

	return newBST;
}

node *
MakeNode(int value)
{
	node *newNode  = (node *)malloc(sizeof(node));

	newNode->value = value;
	newNode->left  = NULL;
	newNode->right = NULL;

	return newNode;
}

void
Insert(node **root, int value)
{
	if (!(*root))
		*root = MakeNode(value);
	else if ((*root)->value > value)
		Insert(&((*root)->left), value);
	else if ((*root)->value < value)
		Insert(&((*root)->right), value);
}

void
Delete(node **root, int value)
{
	if (!(*root))
		return;
	else if ((*root)->value > value)
		Delete(&((*root)->left), value);
	else if ((*root)->value < value)
		Delete(&((*root)->right), value);
	else {
		if (!((*root)->left) && !((*root)->right)) {
			free(*root);
			(*root) = NULL;
		}
		else if (!((*root)->left)) {
			node *tmp = (*root)->right;
			free(*root);
			(*root) = tmp;
		} else if (!((*root)->right)) {
			node *tmp = (*root)->left;
			free(*root);
			(*root) = tmp;
		} else {
			int min = FindMin((*root)->right);
			(*root)->value = min;
			Delete(&((*root)->right), min);
		}
	}
}


int
FindMin(node *root)
{
	if (!root) {
		return INT_MIN;
	}

	while (root->left)
		root = root->left;

	return root->value;
}

int
FindMax(node *root)
{
	if (!root) {
		return INT_MAX;
	}

	while (root->right)
		root = root->right;

	return root->value;
}

bool
Find(node *root, int value)
{
	if (!root)
		return false;

	if (root->value > value)
		return Find(root->left, value);
	else if (root->value < value)
		return Find(root->right, value);
	else
		return true;
}

bool
isBST(node *root, int minValue, int maxValue)
{
	if (!root)
		return true;
	if (root->value < minValue || root->value > maxValue)
		return false;

	return (isBST(root->left, minValue, root->value - 1) &&
		isBST(root->right, root->value + 1, maxValue));
}

void
PreOrder(node *root)
{
	if (!root)
		return;
	else {
		printf("%d ", root->value);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void
InOrder(node *root)
{
	if (!root)
		return;
	else {
		InOrder(root->left);
		printf("%d ", root->value);
		InOrder(root->right);
	}
}

void
ReverseInOrder(node *root)
{
	if (!root)
		return;
	else {
		ReverseInOrder(root->right);
		printf("%d ", root->value);
		ReverseInOrder(root->left);
	}
}

void
PostOrder(node *root)
{
	if (!root)
		return;
	else {
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->value);
	}
}

void
LevelOrder(node *root)
{
	if (!root)
		return;
	else {
		int total = NumNodes(root);
		node **queue = calloc(total, sizeof(node *));

		int front = 0, rear = 1;

		queue[front] = root;

		while (front < total) {
			printf("%d ", queue[front]->value);

			if (queue[front]->left) {
				queue[rear] = queue[front]->left;
				rear++;
			}
			if (queue[front]->right) {
				queue[rear] = queue[front]->right;
				rear++;
			}
			front++;
		}
	}
}

int
NumNodes(node *root)
{
	if (!root)
		return 0;

	return (1 + NumNodes(root->left) + NumNodes(root->right));
}

void
Dump(node *root, int depth)
{
	if (NumNodes(root) > 15)
		printf("BST too large to print.\n");
	else if (!root) {
		Padding('\t', depth);
		puts("*");
	} else {
		Dump(root->right, depth + 1);
		Padding('\t', depth);
		printf("%d\n", root->value);
		Dump(root->left, depth + 1);
	}
}

void
Padding(char ch, int n)
{
	for (int i = 0; i < n; i++)
		putchar(ch);
}

void
Clear(node **root)
{
	if (!(*root))
		return;
	else {
		Clear(&(*root)->left);
		Clear(&(*root)->right);
		free(*root);
	}
	(*root) = NULL;
}

void
FreeTree(bst *tree)
{
	Clear(&tree->root);
	free(tree);
}

void
ToArr(node *root, int arr[], int *n)
{
	if (!root)
		return;

	ToArr(root->left, arr, n);
	arr[*n] = root->value;
	++*n;
	ToArr(root->right, arr, n);
}

node *
Build(int arr[], int left, int right)
{
	if (left > right)
		return NULL;
	int mid = (left + right) / 2;
	node *newRoot = MakeNode(arr[mid]);

	newRoot->left = Build(arr, left, mid - 1);
	newRoot->right = Build(arr, mid + 1, right);

	return newRoot;
}

void
Balance(bst *tree)
{
	int size = NumNodes(tree->root);
	int *arr = (int *)malloc(sizeof(int) * size);
	int idx = 0;

	ToArr(tree->root, arr, &idx);

	/*
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
	*/

	Clear(&tree->root);

	tree->root = Build(arr, 0, size - 1);
}
