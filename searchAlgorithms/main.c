#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void binarySearch(int array[], int size, int c)
{
	int first, last, middle, iterations=0;
	first = 0;
	last = size - 1;
	middle = (first + last) / 2;

	while (first <= last) {
		if (array[middle] < c) {
			first = middle + 1;
			iterations = iterations + 1;
		}
		else if (array[middle] == c) {
			printf("%d found at location %d.\n", c, middle + 1);
			break;
		}
		else
			last = middle - 1;

		middle = (first + last) / 2;
	}
	if (first > last)
		printf("Not found! %d isn't present in the list.\n", c);
	printf("Number of iterations = %d", &iterations);
}

void displayArray(int array[], int size)
{
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d  ", array[i]);
		if (i % 9 == 0)
		{
			printf("\n");
		}
	}
}

void createRandomArray(int size) {
	int x[4096], c, d, swap;
	for (int i = 0; i < size; i++)
	{
		x[i] = rand() % 10001;
	}
	for (c = 0; c < size - 1; c++)
	{
		for (d = 0; d < size - c - 1; d++)
		{
			if (x[d] > x[d + 1])
			{
				swap = x[d];
				x[d] = x[d + 1];
				x[d + 1] = swap;
			}
		}
	}
	displayArray(x, size);
	printf("Choose a digit to search");
	scanf("%d", &c);
	binarySearch(x, size, c);
}



void main() {
	int size;
	do {
		printf("Enter the size of the array max(4096)");
		scanf("%d", &size);
		createRandomArray(size);
		
	} while (1);
}

