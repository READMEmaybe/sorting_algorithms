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
 * selection_sort - Sorts an array using the selection sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest;

	for (i = 0 ; i < size; i++)
	{
		smallest = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[smallest])
				smallest = j;
		}
		if (smallest != i)
		{
			swap(array, i, smallest);
			print_array(array, size);
		}
	}
}
