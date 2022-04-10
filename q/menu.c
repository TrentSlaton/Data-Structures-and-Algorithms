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
	       "will enqueue an entry with a random value to the queue.\n");
	printf("Valid commands are:\n"
	       "\tI - Insert (enqueue) entry.\n"
	       "\tD - Delete (dequeue) entry.\n"
	       "\tP - Print the queue.\n"
	       "\tE - Peek front entry of the queue.\n"
	       "\tS - Prints number of entries in the queue.\n"
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
DoCommand(char command, queue *q)
{
	switch (command) {
	case 'i':
		system("clear");
		int val = arc4random() % 100;
		Enqueue(q, val);
		printf("Enqueue'd [%3d].\n", val);
		Dump(q);
		break;
	case 'd':
		system("clear");
		if (q->front)
			printf("Dequeue'd [%3d]\n", q->front->value);
		Dequeue(q);
		Dump(q);
		break;
	case 'p':
		system("clear");
		Dump(q);
		break;
	case 'e':
		system("clear");
		if (q->front)
			printf("Peeking: [%3d]\n", q->front->value);
		Dump(q);
		break;
	case 's':
		system("clear");
		printf("Size: %d\n", Size(q));
		Dump(q);
		break;
	case 'c':
		system("clear");
		Clear(q);
		printf("Queue cleared.\n");
		Dump(q);
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
		FreeQueue(q);
		printf("Quitting simple queue demo.\n");
		exit(0);
	}
}
