#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_compare - Compare two array elements and swap them
 *                   if necessary based on the bitonic sequence.
 * @array: The array of integers.
 * @i: Index of the first integer.
 * @j: Index of the second integer.
 * @dir: The direction of the bitonic sequence.
 * @size: The size of the array.
 */
void bitonic_compare(int *array, int i, int j, int dir, size_t size)
{
	if ((array[i] > array[j]) == dir)
	{
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * bitonic_merge - Recursively divide the array until two elements
 *                 are obtained and sorts them in bitonic order.
 * @array: The array of integers.
 * @l: The starting index of the sub-array.
 * @cnt: The count of elements in the sub-array.
 * @dir: The direction to sort in.
 * @size: The total size of the main array.
 */
void bitonic_merge(int *array, size_t size, int l, int cnt, int dir)
{
	int k = cnt / 2;
	int i;  /* Declaration moved out of the loop */

	if (cnt <= 1)
		return;

	for (i = l; i < l + k; i++)
		bitonic_compare(array, i, i + k, dir, size);

	bitonic_merge(array, size, l, k, dir);
	bitonic_merge(array, size, l + k, k, dir);
}


/**
 * bitonic_sort - Recursively split the array into two halves until
 *                base case is reached and then merge them in bitonic order.
 * @array: The array of integers.
 * @l: The starting index of the array (should initially be 0).
 * @cnt: The count of elements in the array.
 * @dir: The direction to sort in.
 * @size: The total size of the array.
 */
void bitonic_sequence(int *array, size_t size, int l, int cnt, int dir)
{
	int k = cnt / 2;

	if (cnt <= 1)
		return;

	bitonic_sequence(array, size, l, k, 1);
	bitonic_sequence(array, size, l + k, k, 0);

	bitonic_merge(array, size, l, cnt, dir);
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 *                using the bitonic sort algorithm.
 * @array: The array of integers.
 * @size: The number of elements in the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, 1);
}
