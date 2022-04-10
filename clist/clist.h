#ifndef _CLIST_H_
#define _CLIST_H_

typedef struct node {
	int	value;
	struct	node *next;
} node;

typedef struct clist {
	struct	node *head;
	struct	node *tail;
} clist;

clist	*Initialize(void);
node	*MakeNode(int);
void	 Push(clist *, int);
void	 PushTail(clist *, int);
void	 PushN(clist *, int, int);
void	 Pop(clist *);
void	 PopTail(clist *);
void	 PopN(clist *, int);
int	 Size(clist *);
void	 Clear(clist *);
void	 Dump(clist *);
void	 FreeList(clist *);

#endif /* _CLIST_H_ */
