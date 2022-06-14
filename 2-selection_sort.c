#include "sort.h"

/**
* selection_sort - sort algorithm selection
* @array: array to sort
* @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int tmp;
	size_t s = size - 1;

	if (!array || !size)
		return;
	for (i = 0; i < s; i++)
	{
		for (j = s, k = i + 1; j > i; j--)
		{
			if (array[j] < array[k])
			{
				k = j;
			}
		}
		if (array[i] > array[k])
		{
			tmp = array[i];
			array[i] = array[k];
			array[k] = tmp;
			print_array(array, size);
		}
	}
}
