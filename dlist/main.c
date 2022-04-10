#include <stdlib.h>

#include "menu.h"

int
main(void)
{
	system("clear");
	dlist *l1 = Initialize();

	while (1)
		DoCommand(GetCommand(), l1);

	return 0;
}
