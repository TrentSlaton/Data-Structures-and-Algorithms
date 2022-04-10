#ifndef _BST_H_
#define _BST_H_

#include <stdbool.h>

typedef struct node {
	int	value;
	struct	node *left;
	struct	node *right;
} node;

typedef struct bst {
	struct	node *root;
} bst;

/* Setup functions. */
bst	*Initialize(void);
node	*MakeNode(int);

/* Manipulation functions. */
void	 Insert(node **, int);
void	 Delete(node **, int);
void	 Clear(node **);
void	 FreeTree(bst *);
int	 FindMin(node *);
int	 FindMax(node *);
bool	 Find(node *, int);
bool	 isBST(node *, int, int);
int	 NumNodes(node *);
void	 ToArr(node *, int [], int *);
node	*Build(int [], int, int);
void	 Balance(bst *);

/* Printing functions. */
void	 PreOrder(node *);
void	 InOrder(node *);
void	 ReverseInOrder(node *);
void	 PostOrder(node *);
void	 LevelOrder(node *);
void	 Dump(node *, int);
void	 Padding(char, int);

#endif /* _BST_H_ */
