#include "search_algos.h"

/**
 * linear_search - Function that searches for a value in an
 * array of integers using the Linear search algorithm
 *
 * @array: Array is a pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for in the array
 *
 * Return: The first index where value is located
 * or -1 if value is not found or if array is NULL
 */
int linear_search(int *array, size_t size, int value)
{
	size_t v = 0;

	if (array != NULL)
	{
		for (v = 0; v < size; v++)
		{
			printf("Value checked array[%lu] = [%d]\n", v, array[v]);
			if (array[v] == value)
			{
				return (v);
			}
		}
	}
	return (-1);
}
