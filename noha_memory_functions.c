#include "shell.h"

/**
 * *noha_memset - fill memory with constant byte
 *
 * @destination: pointer to memory area
 * @value: byte o fill dest with
 * @length: amount of byte to be filled
 *
 * Return: dest a pointer to memory ares destination
*/

char *noha_memset(char *destination, char value, unsigned int length)
{
	unsigned int i;

	for (i = 0; i < length; i++)
		destination[i] = value;
	return (destination);
}

/**
 * noha_free_strings - free a string of strings
 *
 * @str_array: string of string
*/

void noha_free_strings(char **str_array)
{
	char **temp = str_array;

	if (!str_array)
		return;
	while (*str_array)
		free(*str_array++);
	free(temp);
}

/**
 * noha_realloc - reallocates the block of memory
 *
 * @prev_ptr: pointer to a previeous malloc
 * @old_size: bite size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to old or new block
*/

void *noha_realloc(void *prev_ptr, unsigned int old_size,
		unsigned int new_size)
{
	char *new_ptr;

	if (!prev_ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(prev_ptr), NULL);
	if (new_size == old_size)
		return (prev_ptr);

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		new_ptr[old_size] = ((char *)prev_ptr)[old_size];
	free(prev_ptr);
	return (new_ptr);
}
