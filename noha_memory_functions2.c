#include "shell.h"

/**
 * noha_bfree - frees a pointer plus the adrees will be NULL
 *
 * @pointer: addres of ptr ro be free
 *
 * Return: free if 1 if nor is 0
*/

int noha_bfree(void **pointer)
{
	if (pointer && pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}
