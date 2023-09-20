#include "noha_string.h"

/**
 * *noha_strncpy - copie the sring
 *
 * @destination: destination string to be copied
 * @source: source string
 * @num: number of caracthers to be copi
 *
 * Return: concatenated string
*/

char *noha_strncpy(char *destination, char *source, int num)
{
	int i, j;
	char *result = destination;

	i = 0;
	while (source[i] != '\0' && i < num - 1)
	{
		destination[i] = source[i];
		i++;
	}
	if (i < num)
	{
		j = i;
		while (j < num)
		{
			destination[j] = '\0'
				j++
		}
	}
	return (result);
}

/**
 * *noha_strncat - two strings concatenates
 *
 * @destination: first string
 * @source: second string
 * @num: max number of bytes to be used
 *
 * Return: concatenated string
*/

char *noha_strncat(char *destination, char *source, int num)
{
	int i, j;
	char *result = destination;

	i = 0;
	j = 0;
	while (destination[i] != '\0')
		i++;
	while (source[j] != '\0' && j < num)
	{
		destination[i] = source[j];
		i++;
		j++;
	}
	if (j < num)
		destination[i] = '\0';
	return (result);
}

/**
 * *noha_strchr - locate a character in string
 *
 * @string: pared string
 * @character: character to look for it
 *
 * Return: the pointer to the memory area is string
*/

char *noha_strchr(char *string, char character)
{
	do {
		if (*string == character)
			return (string);
	} while (*string++ != '\0');

	return (NULL);
}
