#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * bitonic_merge - Merges two bitonic sequences.
 * @array: The array of integers.
 * @size: Size of the array.
 * @l: Starting index of the sequence to be merged.
 * @cnt: Number of elements in the sequence to be merged.
 * @dir: Direction for sorting (1 means ascending, 0 means descending).
 */
void bitonic_merge(int *array, size_t size, int l, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;
		for (int i = l; i < l + k; i++)
			if ((array[i] > array[i + k]) == dir)
			{
				swap(&array[i], &array[i + k]);
				print_array(array, size);
			}
		bitonic_merge(array, size, l, k, dir);
		bitonic_merge(array, size, l + k, k, dir);
	}
}

/**
 * recursive_sort - Helper recursive function to sort a
 * bitonic sequence.
 * @array: The array of integers.
 * @size: Size of the array.
 * @l: Starting index of the sequence to be merged.
 * @cnt: Number of elements in the sequence to be merged.
 * @dir: Direction for sorting (1 means ascending, 0 means descending).
 */
void recursive_sort(int *array, size_t size, int l, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;
		recursive_sort(array, size, l, k, 1);
		recursive_sort(array, size, l + k, k, 0);
		printf("Merging [%d/%lu] (%s):\n", cnt, size, dir ? "UP" : "DOWN");
		print_array(array + l, cnt);
		bitonic_merge(array, size, l, cnt, dir);
		printf("Result [%d/%lu] (%s):\n", cnt, size, dir ? "UP" : "DOWN");
		print_array(array + l, cnt);
	}
}

/**
 * bitonic_sort - Sorts an array of integers using the
 * Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursive_sort(array, size, 0, size, 1);
}
