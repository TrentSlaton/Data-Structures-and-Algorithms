#ifndef _DLIST_H_
#define _DLIST_H_

typedef struct node {
	int	value;
	struct	node *next;
	struct	node *prev;
} node;

typedef struct dlist {
	struct	node *head;
} dlist;

dlist	*Initialize(void);
node	*MakeNode(int);
void	 Push(dlist *, int);
void	 PushTail(dlist *, int);
void	 PushN(dlist *, int, int);
void	 Pop(dlist *);
void	 PopTail(dlist *);
void	 PopN(dlist *, int);
int	 Size(dlist *);
void	 Clear(dlist *);
void	 FreeList(dlist *);
void	 Dump(dlist *);

#endif /* _DLIST_H_ */
