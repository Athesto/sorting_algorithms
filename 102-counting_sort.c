#include "sort.h"
/**
 * max_element - Finding the maximum element
 * @array: this is the array
 * @size: this is the size of array
 * Return: maximum
 */
int max_element(int *array, size_t size)
{
	int maximum = -1;
	unsigned int i;

	for (i = 0; i < size; i++)
	{
		if (maximum < array[i])
			maximum = array[i];
	}
	return (maximum);
}
/**
 * max_length - Initialize a count array of length
 * @array: this is the array
 * @size: this is the size of the array
 * Return: array
 */
int *max_length(int *array, unsigned int size)
{
	unsigned int i;

	for (i = 0; i <= size + 1; i++)
	{
		array[i] = 0;
	}
	return (array);
}
/**
 * counting_sort - sorting algorithm
 * @array: this is the array
 * @size: this is the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *arr_count, *sorted_arr;
	unsigned int maximum, i, j, cal_cumulative, tmp;

	if (size == 0 || size == 1)
		return;

	maximum = max_element(array, size);
	arr_count = malloc((maximum * sizeof(int)) + 1);
	if (arr_count == NULL)
		return;
	sorted_arr = malloc(size * sizeof(int));
	if (sorted_arr == NULL)
	{
		free(arr_count);
		return;
	}
	for (i = 0; i < size; i++)
		sorted_arr[i] = array[i];
	max_length(arr_count, maximum);
	for (j = 0; j < size; j++)
	{
		arr_count[array[j]]++;
	}

	for (cal_cumulative = 1; cal_cumulative <= maximum; cal_cumulative++)
	{
		arr_count[cal_cumulative] += arr_count[cal_cumulative - 1];
	}
	print_array(arr_count, maximum + 1);
	for (i = 0; i < size; i++)
	{
		tmp = sorted_arr[i];
		array[arr_count[tmp] - 1] = tmp;
		arr_count[tmp]--;
	}
	free(arr_count);
	free(sorted_arr);
}
