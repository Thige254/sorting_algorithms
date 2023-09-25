#include "sort.h"

/**
 * lomuto_partition - partition the array using the Lomuto scheme
 * @array: array to sort
 * @low: low index of the subarray
 * @high: high index of the subarray
 * @size: size of the original array
 * Return: final index position for the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > pivot)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * lomuto_sort - sorts using Lomuto partition scheme
 * @array: array to sort
 * @low: low index of the subarray
 * @high: high index of the subarray
 * @size: size of the array
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);

		lomuto_sort(array, low, pi - 1, size);
		lomuto_sort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sort an array using quicksort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}
