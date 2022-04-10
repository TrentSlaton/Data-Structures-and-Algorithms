#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "menu.h"

void
Help(void)
{
	printf("\nThis program allows one command to be entered per line.\n"
	       "For example, if the command 'I' is entered, then the program\n"
	       "will push an entry with a random value to the list.\n");
	printf("Valid commands are:\n"
	       "\tW - Insert (push) entry.\n"
	       "\tE - Insert N entry.\n"
	       "\tR - Insert TAIL entry.\n"
	       "\tT - Delete (pop) entry.\n"
	       "\tY - Delete N entry.\n"
	       "\tU - Delete TAIL entry.\n"
	       "\tP - Print the list.\n"
	       "\tS - Print size of the list.\n"
	       "\tC - Clear the queue, making it empty.\n"
	       "\tK - Clear screen.\n"
	       "\tH - This help screen.\n"
	       "\tQ - Quit.\n"
	       "Press < ENTER > to continue.");
	while (getchar() != '\n')
		;
	system("clear");
}

char
GetCommand(void)
{
	char	command;

	printf("\n\t[W]Insert\t[E]Insert N\t[R]Insert Tail\t"
	       "\n\t[T]Delete\t[Y]Delete N\t[U]Delete Tail\t"
	       "\n\t[P]rint\t\t[S]ize\t\t[C]lear"
	       "\n\t[K]clear screen\t[H]elp\t\t[Q]uit"
	       "\nSelect command and press < ENTER >:");
	
	while (1) {
		while ((command = getchar()) == '\n')
			;
		command = tolower(command);
		if (command == 'w' || command == 'e' || command == 'r' ||
		    command == 't' || command == 'y' || command == 'u' ||
		    command == 'p' || command == 's' || command == 'c' ||
		    command == 'k' || command == 'h' || command == 'q') {
			while (getchar() != '\n')
				;
			return command;
		}
		printf("Please enter a valid command or H for help:");
	}
}

void
DoCommand(char command, clist *list)
{
	int	n, value;
	switch (command) {
	case 'w':
		system("clear");
		value = arc4random() % 100;
		Push(list, value);
		printf("Pushed [%3d]\n", value);
		Dump(list);
		break;
	case 'e':
		system("clear");
		Dump(list);
		value = arc4random() % 100;
		printf("Insert [%3d] after position: ", value);
		scanf("%d", &n);
		system("clear");
		PushN(list, value, n);
		printf("Pushed [%3d] into position %d.\n", value, n + 1);
		Dump(list);
		break;
	case 'r':
		system("clear");
		value = arc4random() % 100;
		PushTail(list, value);
		printf("Pushed [%3d] to the tail.\n", value);
		Dump(list);
		break;
	case 't':
		system("clear");
		if (list->head)
			printf("Popped [%3d]\n", list->head->value);
		Pop(list);
		Dump(list);
		break;
	case 'y':
		system("clear");
		Dump(list);
		printf("Delete AFTER position: ");
		scanf("%d", &n);
		system("clear");
		PopN(list, n);
		if (n >=0 && n < Size(list))
			printf("Deleted element %d.\n", n + 1);
		Dump(list);
		break;
	case 'u':
		system("clear");
		if (list->head)
			printf("Deleted from the tail.\n");
		PopTail(list);
		Dump(list);
		break;
	case 'p':
		system("clear");
		Dump(list);
		break;
	case 's':
		system("clear");
		printf("Size: %d\n", Size(list));
		Dump(list);
		break;
	case 'c':
		system("clear");
		Clear(list);
		Dump(list);
		break;
	case 'k':
		system("clear");
		break;
	case 'h':
		system("clear");
		Help();
		break;
	case 'q':
		system("clear");
		printf("Freeing memory.\n");
		FreeList(list);
		printf("Quitting simple queue demo.\n");
		exit(0);
	}
}
