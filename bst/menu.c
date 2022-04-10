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
	       "will ask for an entry and then push it to the stack.\n");
	printf("Valid commands are:\n"
	       "\tI - Insert.\n"
	       "\tD - Delete, given a value.\n"
	       "\tM - Print the minimum value in the tree.\n"
	       "\tX - Print the maximum value in the tree.\n"
	       "\tF - Find, given a value.\n"
	       "\tB - Balances the tree.\n"
	       "\tP - Prints the tree\n"
	       "\tW - Prints a Pre-Order traversal.\n"
	       "\tE - Prints an In-Order traversal.\n"
	       "\tR - Prints a Post-Order traversal.\n"
	       "\tT - Prints a Reverse In-Order traversal.\n"
	       "\tY - Prints a Level-Order (breadth-first) traversal.\n"
	       "\tS - Prints the size of the tree.\n"
	       "\tC - Clear the tree, making it empty.\n"
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

	printf("\n\t[I]nsert\t\t[D]elete"
	       "\n\t[M]inimun\t\t[X]maximum\t[F]ind"
	       "\n\t[B]alance\t\t[P]rint\t\t[W]Pre-Order"
	       "\n\t[E]In-Order\t\t[R]Post-Order\t[T]Reverse In-Order"
	       "\n\t[Y]Level-Order\t\t[S]Size\t\t[C]Clear"
	       "\n\t[K]clear screen\t\t[H]elp\t\t[Q]uit"
	       "\nSelect command and press < ENTER >:");
	
	while (1) {
		while ((command = getchar()) == '\n')
			;
		command = tolower(command);
		if (command == 'i' || command == 'd' || command == 'm' ||
		    command == 'x' || command == 'f' || command == 'b' ||
		    command == 'p' || command == 'w' || command == 'e' ||
		    command == 'r' || command == 't' || command == 'y' ||
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
DoCommand(char command, bst *tree)
{
	int	n, value;
	switch (command) {
	case 'i':
		system("clear");
		value = arc4random() % 100;
		Insert(&tree->root, value);
		printf("Inserted [%3d]\n", value);
		Dump(tree->root, 0);
		break;
	case 'd':
		system("clear");
		Dump(tree->root, 0);
		printf("Enter value to delete: ");
		scanf("%d", &n);
		system("clear");
		if (Find(tree->root, n))
			printf("Deleted [%d]\n", n);
		Delete(&tree->root, n);
		Dump(tree->root, 0);
		break;
	case 'm':
		system("clear");
		if (tree->root)
			printf("Minimum value: [%3d]\n", FindMin(tree->root));
		Dump(tree->root, 0);
		break;
	case 'x':
		system("clear");
		if (tree->root)
			printf("Maximum value: [%3d]\n", FindMax(tree->root));
		Dump(tree->root, 0);
		break;
	case 'f':
		system("clear");
		Dump(tree->root, 0);
		printf("Search for value: ");
		scanf("%d", &n);
		if (Find(tree->root, n))
			printf("[%3d] Found!\n", n);
		else
			printf("[%3d] Not found!\n", n);
		Dump(tree->root, 0);
		break;
	case 'b':
		system("clear");
		if (tree->root)
			printf("Balanced.\n");
		Balance(tree);
		Dump(tree->root, 0);
		break;
	case 'p':
		system("clear");
		Dump(tree->root, 0);
		break;
	case 'w':
		system("clear");
		if (tree->root)
			printf("Pre-Order traversal: ");
		PreOrder(tree->root);
		printf("\n");
		Dump(tree->root, 0);
		break;
	case 'e':
		system("clear");
		if (tree->root)
			printf("In-Order traversal: ");
		InOrder(tree->root);
		printf("\n");
		Dump(tree->root, 0);
		break;
	case 'r':
		system("clear");
		if (tree->root)
			printf("Post-Order traversal: ");
		PostOrder(tree->root);
		printf("\n");
		Dump(tree->root, 0);
		break;
	case 't':
		system("clear");
		if (tree->root)
			printf("Reverse In-Order traversal: ");
		ReverseInOrder(tree->root);
		printf("\n");
		Dump(tree->root, 0);
		break;
	case 'y':
		system("clear");
		if (tree->root)
			printf("Level-Order (breadth first) traversal: ");
		LevelOrder(tree->root);
		printf("\n");
		Dump(tree->root, 0);
		break;
	case 's':
		system("clear");
		printf("Size: %d\n", NumNodes(tree->root));
		Dump(tree->root, 0);
		break;
	case 'c':
		system("clear");
		Clear(&tree->root);
		Dump(tree->root, 0);
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
		FreeTree(tree);
		printf("Quitting simple bst demo.\n");
		exit(0);
	}
}
