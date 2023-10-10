#include "search_algos.h"

/**
 * jump_search -  function that searches for a value in a
 * sorted array of integers using the Jump search algorithm
 *
 * @array: Array is a pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for in the array
 *
 * Return: The first index where value is located
 * or -1 if value is not found or if array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t the_under = 0;
	size_t the_apex = 0, v = 0;

	if (array != NULL)
	{
		while (the_apex < size && array[the_apex] < value)
		{
			the_under = the_apex;
			the_apex = the_apex + sqrt(size);
			printf("Value checked array[%lu] = [%d]\n",
			       the_under, array[the_under]);
		}
		printf("Value found between indexes [%lu] and [%lu]\n",
		       the_under, the_apex);
		for (v = the_under; v <= the_apex; v++)
		{
			if (v < size)
			{
				printf("Value checked array[%lu] = [%d]\n",
				       v, array[v]);
				if (array[v] == value)
					return (v);
			}
		}
	}
	return (-1);
}
