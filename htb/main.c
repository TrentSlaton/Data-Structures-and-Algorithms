#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

extern	int TABLE_SIZE;

int
main(void)
{
	system("clear");
	TABLE_SIZE = -1;

	do {
		printf("What size is your table? ");
		scanf("%d", &TABLE_SIZE);
		system("clear");
	} while (TABLE_SIZE < 1);

	ht *table1 = Initialize();

	while (1)
		DoCommand(GetCommand(), table1);

	return 0;
}
