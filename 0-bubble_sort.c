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
 * bubble_sort - Sorts an array using the bubble sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int flag = 1;

	if (size < 2)
		return;

	while (flag)
	{
		flag = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array, i, i + 1);
				print_array(array, size);
				flag = 1;
			}
		}
	}
}
