#ifndef _MENU_H_
#define _MENU_H_

#include "dlist.h"

void	Help(void);
char	GetCommand(void);
void	DoCommand(char, dlist *);

#endif /* _MENU_H_ */
