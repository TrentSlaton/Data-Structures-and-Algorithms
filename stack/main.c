#include <stdlib.h>

#include "menu.h"

int
main(void)
{
	system("clear");
	stack *s1 = Initialize();

	while (1)
		DoCommand(GetCommand(), s1);

	return 0;
}
