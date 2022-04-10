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
	       "will push an entry to the stack.\n");
	printf("Valid commands are:\n"
	       "\tI - Insert (push) entry.\n"
	       "\tD - Delete (pop) entry.\n"
	       "\tP - Print the entire stack.\n"
	       "\tE - Peek top entry of the stack.\n"
	       "\tS - Prints number of entries in the stack.\n"
	       "\tC - Clear the stack, making it empty.\n"
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

	printf("\n\t[I]nsert\t[D]elete\t[P]rint"
	       "\n\tp[E]ek\t\t[S]ize\t\t[C]lear"
	       "\n\t[K]clear screen\t[H]elp\t\t[Q]uit"
	       "\nSelect command and press < ENTER >:");
	
	while (1) {
		while ((command = getchar()) == '\n')
			;
		command = tolower(command);
		if (command == 'i' || command == 'd' || command == 'p' ||
		    command == 'e' || command == 's' || command == 'c' ||
		    command == 'k' || command == 'h' || command == 'q') {
			while (getchar() != '\n')
				;
			return command;
		}
		printf("Please enter a valid command or H for help:");
	}
}

void
DoCommand(char command, stack *st)
{
	int	value;
	switch (command) {
	case 'i':
		system("clear");
		value = arc4random() % 100;
		Push(st, value);
		printf("Pushed [%3d].\n", value);
		Dump(st);
		break;
	case 'd':
		system("clear");
		if (st->top)
			printf("Popped [%3d]\n", st->top->value);
		Pop(st);
		Dump(st);
		break;
	case 'p':
		system("clear");
		Dump(st);
		break;
	case 'e':
		system("clear");
		if (st->top)
			printf("Peeking [%3d]\n", st->top->value);
		Dump(st);
		break;
	case 's':
		system("clear");
		printf("Size: %d\n", Size(st));
		Dump(st);
		break;
	case 'c':
		system("clear");
		Clear(st);
		printf("Stack cleared...\n");
		Dump(st);
		break;
	case 'h':
		system("clear");
		Help();
		break;
	case 'k':
		system("clear");
		break;
	case 'q':
		system("clear");
		printf("Freeing memory.\n");
		FreeStack(st);
		printf("Quitting simple stack demo.\n");
		exit(0);
	}
}
