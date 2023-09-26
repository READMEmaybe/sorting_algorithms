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
 * shell_sort - Sorts an array using the Shell sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1, i, j;

	if (array == NULL || size < 2)
		return;

	while (n < size / 3)
		n = n * 3 + 1;

	while (n >= 1)
	{
		for (i = n; i < size; i++)
		{
			for (j = i; j >= n && array[j] < array[j - n]; j -= n)
				swap(array, j, j - n);
		}
		n /= 3;
		print_array(array, size);
	}
}
