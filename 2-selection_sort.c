#include "sort.h"
/**
 * selection_sort - algoritm
 * @array: ?
 * @size: ?
 */
void selection_sort(int *array, size_t size)
{
	size_t a_idx; /* array index */
	size_t runner; /* array index */
	size_t selector;
	int value;
	int found = 0;

	if (!array)
		return;
	for (a_idx = 0; a_idx < size; a_idx++)
	{
		selector = a_idx;
		for (runner = a_idx; runner < size; runner++)
		{
			if (array[selector] > array[runner])
			{
				selector = runner;
				found = 1;
			}
		}
		if (found)
		{
			value = array[a_idx];
			array[a_idx] = array[selector];
			array[selector] = value;
			print_array(array, size);
		}
		found = 0;
	}
}
