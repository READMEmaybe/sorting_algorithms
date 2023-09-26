#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @array: The array in which elements should be swapped
 * @i: The index of the first element to be swapped
 * @j: The index of the second element to be swapped
 */
void swap(int *array, int i, int j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}


/**
 * lomuto_partition - Partitions an array using Lomuto partition scheme
 * @array: The array to be partitioned
 * @size: Number of elements in the array
 * @start: The starting index of the subarray to be partitioned
 * @end: The ending index of the subarray to be partitioned
 *
 * Return: The index of the pivot element after partitioning
 */
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int j, i;

	for (j = start, i = j - 1; j != end; j++)
	{
		if (array[j] < array[end])
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	i++;
	if (array[i] != array[end])
	{
		swap(array, end, i);
		print_array(array, size);
	}
	return (i);
}

/**
 * lomuto_quickSort - Sorts a subarray using the Lomuto QuickSort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @start: The starting index of the subarray to be sorted
 * @end: The ending index of the subarray to be sorted
 */
void lomuto_quickSort(int *array, size_t size, int start, int end)
{
	int pivot;

	if (end > start)
	{
		pivot = lomuto_partition(array, size, start, end);
		lomuto_quickSort(array, size, start, pivot - 1);
		lomuto_quickSort(array, size, pivot + 1, end);
	}
}

/**
 * quick_sort - Sorts an array using the QuickSort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	lomuto_quickSort(array, size, 0, size - 1);
}
