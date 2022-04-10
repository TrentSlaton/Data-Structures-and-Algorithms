#ifndef _MENU_H_
#define _MENU_H_

#include "clist.h"

void	Help(void);
char	GetCommand(void);
void	DoCommand(char, clist *);

#endif /* _MENU_H_ */
