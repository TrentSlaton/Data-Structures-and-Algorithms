#include <stdlib.h>

#include "menu.h"

int
main(void)
{
	system("clear");
	bst *tree1 = Initialize();

	while (1)
		DoCommand(GetCommand(), tree1);

	return 0;
}
