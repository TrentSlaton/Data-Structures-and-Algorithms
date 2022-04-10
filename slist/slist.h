#ifndef _SLIST_H_
#define _SLIST_H_

typedef struct node {
	int	value;
	struct	node *next;
} node;

typedef struct slist {
	struct	node *head;
} slist;

slist	*Initialize(void);
node	*MakeNode(int);
void	 Push(slist *, int);
void	 PushN(slist *, int, int);
void	 PushTail(slist *, int);
void	 Pop(slist *);
void	 PopN(slist *, int);
void	 PopTail(slist *);
void	 Clear(slist *);
int	 Size(slist *);
void	 Dump(slist *);
void	 FreeSList(slist *);

#endif /* _SLIST_H_ */
