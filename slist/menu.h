#ifndef _MENU_H_
#define _MENU_H_

#include "slist.h"

void	Help(void);
char	GetCommand(void);
void	DoCommand(char, slist *);

#endif /* _MENU_H_ */
