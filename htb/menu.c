#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "menu.h"

void
Help(void)
{
	printf("This program allows one command to be entered per line.\n"
	       "For example, if the command 'I' is entered, then the program\n"
	       "will ask for a name, an age, and then insert that pair into\n"
	       "the hash table.\n");
	printf("Valid commands are:\n"
	       "\tI - Insert an entry, given a name and age.\n"
	       "\tD - Delete an entry, given a name.\n"
	       "\tP - Print the hash table, showing collisions.\n"
	       "\tS - Search for a name in the hash table.\n"
	       "\tC - Clear the hash table, making it empty.\n"
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
	       "\n\t[S]earch\t[C]lear\t\t[K]clear screen"
	       "\n\t[H]elp\t\t[Q]uit"
	       "\nSelect command and press < ENTER >:");
	
	while (1) {
		while ((command = getchar()) == '\n')
			;
		command = tolower(command);
		if (command == 'i' || command == 'd' || command == 'p' ||
		    command == 's' || command == 'c' || command == 'k' ||
		    command == 'h' || command == 'q') {
			while (getchar() != '\n')
				;
			return command;
		}
		printf("Please enter a valid command or H for help:");
	}
}

void
DoCommand(char command, ht *table)
{
	char	key[32];
	int	value;

	switch (command) {
	case 'i':
		system("clear");
		memset(key, 0, 32);
		printf("Enter a name: ");
		scanf("%s", key);
		system("clear");
		printf("Enter an age: ");
		scanf("%d", &value);
		system("clear");
		Insert(table, key, value);
		printf("Inserted <\"%s\", %d>.\n", key, value);
		Dump(table);
		break;
	case 'd':
		system("clear");
		Dump(table);
		printf("Enter key to delete: ");
		scanf("%s", key);
		Delete(table, key);
		Dump(table);
		printf("Deleted <%s>\n.", key);
		break;
	case 'p':
		system("clear");
		Dump(table);
		break;
	case 's':
		system("clear");
		printf("Enter key to search: ");
		scanf("%s", key);
		if (Search(table, key))
			printf("%s found!\n", key);
		else
			printf("%s NOT found!\n", key);
		break;
	case 'c':
		system("clear");
		printf("Clearing table...\n");
		Clear(table);
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
		FreeTable(table);
		printf("Quitting simple hash table demo.\n");
		exit(0);
	}
}
