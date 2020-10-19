#include "sort.h"
/**
 * bubble_sort - bubble sort algoritm
 * @array: ?
 * @size: ?
 */
void bubble_sort(int *array, size_t size)
{
	size_t count, index, tmp = 0;

	if (!array)
		return;

	for (count = 1; count < size; count++)
	{
		/*We start(count) at 1, in this way we will run the cycle only*/
		/*(n) times. This way we avoid running cycles unnecessarily.*/
		for (index = 0; index < size - count; index++)
		{
			/*we start(index)at 0, this allows us to evaluate each*/
			/*data of the array*/
			if (array[index] > array[index + 1])
			{
				tmp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
