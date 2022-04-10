#ifndef _HT_H_
#define _HT_H_

#include <stdbool.h>

typedef struct node {
	char	*key;
	int	value;
	struct	node *next;
} node;

typedef struct ht {
	struct	node **entries;	
} ht;

ht	*Initialize(void);
node	*MakeNode(const char *, int);
uint64_t Hash(const char *);
void	 Insert(ht *, const char *, int);
bool	 Search(ht *, const char *);
void	 Delete(ht *, const char *);
void	 Clear(ht *);
void	 Dump(ht *);
void	 FreeNode(node *);
void	 FreeTable(ht *);

#endif /* _HT_H_ */
