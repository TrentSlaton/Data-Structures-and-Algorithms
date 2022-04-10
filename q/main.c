#include <stdlib.h>

#include "menu.h"

int
main(void)
{
	system("clear");
	queue *q1 = Initialize();

	while (1)
		DoCommand(GetCommand(), q1);

	return 0;
}
