#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "ss.h"

#define	TICK(x) clock_t x = clock()
#define	TOCK(x) (double)(clock() - (x)) / CLOCKS_PER_SEC

extern	char *__progname;
int	Bflag, Lflag, bflag, iflag, mflag, pflag, qflag, sflag, tflag;
float	search, sort;

int
main(int argc, char *argv[])
{
	int	ch;

	while ((ch = getopt(argc, argv, "BLbimpqst")) != -1)
		switch (ch) {
		case 'B':
			Bflag = 1;
			Lflag = 0;
			break;
		case 'L':
			Lflag = 1;
			Bflag = 0;
			break;
		case 'b':
			bflag = 1;
			iflag = 0;
			sflag = 0;
			qflag = 0;
			mflag = 0;
			break;
		case 'i':
			iflag = 1;
			bflag = 0;
			sflag = 0;
			qflag = 0;
			mflag = 0;
			break;
		case 'm':
			mflag = 1;
			qflag = 0;
			sflag = 0;
			iflag = 0;
			bflag = 0;
			break;
		case 'q':
			qflag = 1;
			sflag = 0;
			iflag = 0;
			bflag = 0;
			mflag = 0;
			break;
		case 'p':
			pflag = 1;
			break;
		case 's':
			sflag = 1;
			iflag = 0;
			bflag = 0;
			qflag = 0;
			mflag = 0;
			break;
		case 't':
			tflag = 1;
			break;
		default:
			usage();
		}

	argc -= optind;
	argv += optind;

	if (argc < 1 || argc > 2)
		usage();

	int	SIZE = atoi(argv[0]);
	int	*arr = (int *)malloc(sizeof(int) * SIZE);
	int	target = 0;

	if (argv[1])
		target = atoi(argv[1]);

	for (int i = 0; i < SIZE; i++)
		arr[i] = arc4random();

	if (bflag) {
		TICK(x);
		bubblesort(arr, SIZE);
		sort = TOCK(x);
	} else if (iflag) {
		TICK(x);
		insertionsort(arr, SIZE);
		sort = TOCK(x);
	} else if (mflag) {
		TICK(x);
		mrgsort(arr, 0, SIZE - 1);
		sort = TOCK(x);
	} else if (qflag) {
		TICK(x);
		quicksort(arr, 0, SIZE - 1);
		sort = TOCK(x);
	} else if (sflag) {
		TICK(x);
		selectionsort(arr, SIZE);
		sort = TOCK(x);
	}

	if (pflag)
		printarr(arr, SIZE);	
	if (Lflag && argv[1]) {
		TICK(x);
		bool found = linsearch(arr, SIZE, target);
		search = TOCK(x);
		if (found)
			printf("[%d] FOUND\n", target);
		else
			printf("[%d] NOT FOUND\n", target);
	} else if (Bflag && argv[1]) {
		if (!checksorted(arr, SIZE)) {
			printf("List is not sorted, cannot Binary Search.\n");
			exit(1);
		}
		else {
			TICK(x);
			bool found = binsearch(arr, SIZE, target);
			search = TOCK(x);
			if (found)
				printf("[%d] FOUND\n", target);
			else
				printf("[%d] NOT FOUND\n", target);
		}
	}

	if (tflag) {
		if (bflag || iflag || mflag || qflag || sflag)
			printf("Sort time: %g\n", sort);
		if (Bflag || Lflag)
			printf("Search time: %g\n", search);
	}

	free(arr);

	return 0;
}
