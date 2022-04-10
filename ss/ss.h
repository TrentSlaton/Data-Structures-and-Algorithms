#ifndef _SS_H_
#define _SS_H_

#include <stdbool.h>

/* Utility functions. */
bool	checksorted(int [], int);
void	printarr(int [], int);
void	usage(void);

/* Searching functions. */
bool	linsearch(int [], int, int);
bool	binsearch(int [], int, int);

/* Sorting functions. */
void	bubblesort(int [], int);
void	insertionsort(int [], int);
void	mrgsort(int [], int, int);
void	mrg(int [], int, int, int);
void	quicksort(int [], int, int);
int	partition(int [], int, int);
void	selectionsort(int [], int);

#endif /* _SS_H_ */
