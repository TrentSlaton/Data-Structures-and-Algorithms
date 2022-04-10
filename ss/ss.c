#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ss.h"

extern	char *__progname;

bool
checksorted(int arr[], int size)
{
	for (int i = 1; i < size; i++)
		if (arr[i] < arr[i - 1])
			return false;
	return true;
}

void
printarr(int arr[], int size)
{
	if (size < 15)
		for (int i = 0; i < size; i++)
			printf("(%2d)[%12d]\n", i + 1, arr[i]);
	else {
		for (int i = 0; i < 4; i++)
			printf("(%7d)[%12d]\n", i + 1, arr[i]);
		for (int i = 0; i < 4; i++)
			printf("...\n");
		for (int i = size -5; i < size; i++)
			printf("(%7d)[%12d]\n", i + 1, arr[i]);
	}
}

void
usage(void)
{
	fprintf(stderr, "usage: %s [-BLbimpqst] size target\n", __progname);
	exit(1);
}

bool
linsearch(int arr[], int size, int target)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == target)
			return true;
	return false;
}

bool
binsearch(int arr[], int size, int target)
{
	int left, mid, right;

	left = 0;
	right = size - 1;

	while (left <= right) {
		mid = left + (right - left) / 2;
		if (arr[mid] > target)
			right = mid - 1;
		else if (arr[mid] < target)
			left = mid + 1;
		else
			return true;
	}
	return false;
}

void
bubblesort(int arr[], int size)
{
	int i, range, tmp;

	range = size - 1;

	while (range > 0) {
		for (i = 0; i < range; i++)
			if (arr[i] > arr[i + 1]) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		range--;
	}
}

void
insertionsort(int arr[], int size)
{
	int i, j, key, space;

	for (i = 1; i < size; i++) {
		key = arr[i];
		space = i;

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > key) {
				arr[space] = arr[j];
				space = j;
				continue;
			}
			break;
		}
		arr[space] = key;
	}
}

void
mrgsort(int arr[], int left, int right)
{
	if (left < right) {
		int mid = left + (right - left) / 2;
		mrgsort(arr, left, mid);
		mrgsort(arr, mid + 1, right);
		mrg(arr, left, mid, right);
	}
}

void
mrg(int arr[], int left, int mid, int right)
{
	int	i, j, k;
	int	n1 = mid - left + 1;
	int	n2 = right - mid;
	int	*L = malloc(sizeof(int) * n1);
	int	*R = malloc(sizeof(int) * n2);

	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];

	for (j = 0; j < n2; j++)
		R[j] = arr[mid + j + 1];

	i = j = 0;
	k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
		k++;
	}

	while (i < n1)
		arr[k++] = L[i++];

	while (j < n2)
		arr[k++] = R[j++];

	free(L);
	free(R);
}

void
quicksort(int arr[], int left, int right)
{
	if (left < right) {
		int pi = partition(arr, left, right);
		quicksort(arr, left, pi - 1);
		quicksort(arr, pi + 1, right);
	}
}

int
partition(int arr[], int left, int right)
{
	int i, pi, tmp;

	for (i = pi = left; i < right; i++)
		if (arr[i] < arr[right]) {
			tmp = arr[i];
			arr[i] = arr[pi];
			arr[pi] = tmp;
			pi++;
		}

	tmp = arr[pi];
	arr[pi] = arr[right];
	arr[right] = tmp;

	return pi;
}

void
selectionsort(int arr[], int size)
{
	int i, j, min, tmp;

	for (i = 0; i < size - 1; i++) {
		min = i;

		for (j = i + 1; j < size; j++)
			if (arr[j] < arr[min])
				min = j;

		if (min != i) {
			tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}
