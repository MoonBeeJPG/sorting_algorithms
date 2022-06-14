#include "sort.h"

/**
* swap - swap values
* @array: to swap
* @size: of the array
* @a: index
* @b: second index
*/
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
* lomuto_partition - partitions the array
* @array: array to sort
* @size: size of the array
* @low: lower index
* @hig: higher index
*
* Return: void
*/
size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t hig)
{
	int i, j, pivot = array[hig];

	for (i = j = low; j < hig; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[hig]);

	return (i);
}

/**
* quicksort - quicksort
* @array: of integers
* @size: of the array
* @low: lower index
* @hig: higher index
*/
void quicksort(int *array, size_t size, ssize_t low, ssize_t hig)
{
	if (low < hig)
	{
		size_t k = lomuto_partition(array, size, low, hig);

		quicksort(array, size, low, k - 1);
		quicksort(array, size, k + 1, hig);
	}
}

/**
* quick_sort - calls fuction quicksort using lomuto
* @array: of integers
* @size: of the array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
