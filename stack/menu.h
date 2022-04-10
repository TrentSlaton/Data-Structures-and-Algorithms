#ifndef _MENU_H_
#define _MENU_H_

#include "stack.h"

void	Help(void);
char	GetCommand(void);
void	DoCommand(char, stack *);

#endif /* _MENU_H_ */
