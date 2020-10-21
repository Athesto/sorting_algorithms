#include "sort.h"
#include <stdlib.h>

int getgap(int **gap, size_t size);
void _swap(int *a, int *b);
/**
 * shell_sort - shell sort algoritm
 * @array: input array
 * @size: size of the input array
 */
void shell_sort(int *array, size_t size)
{
	int g_len;
	int g_idx;
	int *gap;
	int a_idx;
	int b_idx;
	int i, *a, *b;

	g_len = getgap(&gap, size);
	for (g_idx = 0; g_idx < g_len; g_idx++)
	{
		for (i = 0; i < gap[g_idx]; i++)
		{
			for (a_idx = 0; i + a_idx * gap[g_idx] < (int)size; a_idx++)
			{
				for (b_idx = a_idx; (b_idx - 1) >= 0; b_idx--)
				{
					a = &array[i + b_idx * gap[g_idx]];
					b = &array[i + (b_idx - 1) * gap[g_idx]];
					if (*a < *b)
						_swap(a, b);
				}
			}
		}
		print_array(array, size);
	}

	free(gap);
	(void) array;
	(void) size;
}
/**
 * getgap - ?
 * @gap: refernce to array
 * @size: input len
 * Return: size of gap array
 */
int getgap(int **gap, size_t size)
{
	int i, len;
	size_t gapVal;

	for (len = 0,  gapVal = 1; gapVal < size; len++)
		gapVal = 3 * gapVal + 1;
	*gap = malloc(len * sizeof(**gap));

	for (i = gapVal = 0; i < len; i++)
	{
		gapVal = 3 * gapVal + 1;
		(*gap)[len - 1 - i] = (int)gapVal;
	}
	return (len);
}

/**
 * _swap - swap inputs
 * @a: input 1
 * @b: input 2
 */
void _swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}


