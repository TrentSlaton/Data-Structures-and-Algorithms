#ifndef _STACK_H_
#define _STACK_H_

typedef struct node {
	int	value;
	struct	node *next;
} node;

typedef struct stack {
	struct	node *top;
} stack;

stack	*Initialize();
node	*MakeNode(int);
void	 Push(stack *, int);
void	 Pop(stack *);
void	 Clear(stack *);
int	 Size(stack *);
void	 Dump(stack *);
void	 FreeStack(stack *);

#endif /* _STACK_H_ */
