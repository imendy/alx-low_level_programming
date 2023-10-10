#include "search_algos.h"

/**
 * binary_search - function that searches for a value in a sorted
 * array of integers using the Binary search algorithm
 *
 * @array: Array is a pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for in the array
 *
 * Return: The first index where value is located
 * or -1 if value is not found or if array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t the_left = 0;
	size_t the_right = size - 1;
	size_t the_middle = 0;
	size_t v = 0;

	if (array != NULL)
	{
		while (the_left <= the_right)
		{
			the_middle = (the_left + the_right) / 2;
			printf("Searching in array: ");
			for (v = the_left; v < the_right; v++)
			{
				printf("%d, ", array[v]);
			}
			printf("%d\n", array[v]);
			if (array[the_middle] < value)
			{
				the_left = the_middle + 1;
			}
			else if (array[the_middle] > value)
			{
				the_right = the_middle - 1;
			}
			else
			{
				return (the_middle);
			}
		}
	}
	return (-1);
}
