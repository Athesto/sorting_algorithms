#include "sort.h"
/**
 * quick_sort - quick sort algoritm
 * @array: ?
 * @size: ?
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}
	method_quick_sort(array, size, 0, size - 1);
}
/**
 * swap - mehtod that swapping
 * @array: this is the  array
 * @size: size of array
 * @a: varieble
 * @b: variable
 */
void swap(int *array, size_t size, int a, int b)
{
	int tmp;

	if (array[a] != array[b])
	{
		tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
		print_array(array, size);
	}
}
/**
 * method_quick_sort - function that call tada sorting
 * @array: this is array
 * @size: this is the size of array
 * @left: this is the first element or data of array
 * @right: this is the last element or data of array
 */
void method_quick_sort(int *array, size_t size, int left, int right)
{
	int index_partision;

	if (left < right)
	{
		index_partision = lomuto_partision(array, size, left, right);
		method_quick_sort(array, size, left, index_partision - 1);
		method_quick_sort(array, size, index_partision + 1, right);
	}
}
/**
 * lomuto_partision - method that orders the  array
 * @array: this is array
 * @size: this is the size of array
 * @first_elmt: this is the first element or data of array
 * @last_elmt: this is the last or data of array
 * Return: ?
 */
int lomuto_partision(int *array, size_t size, int first_elmt, int last_elmt)
{
	int pivot = array[last_elmt];
	int left = first_elmt, right = last_elmt, iterator = left;

	while (iterator <= right)
	{
		if (array[iterator] < pivot)
		{
			swap(array, size, left, iterator);
			left++;
		}
		iterator++;
	}
	swap(array, size, left, right);
	return (left);
}
