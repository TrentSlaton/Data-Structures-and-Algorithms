#ifndef _Q_H_
#define _Q_H_

typedef struct node {
	int	value;
	struct	node *next;
} node;

typedef struct queue {
	struct	node *front;
	struct	node *rear;
} queue;

queue	*Initialize(void);
node	*MakeNode(int);
void	 Enqueue(queue *, int);
void	 Dequeue(queue *);
void	 Clear(queue *);
int	 Size(queue *);
void	 Dump(queue *);
void	 FreeQueue(queue *);

#endif /* _Q_H_ */
