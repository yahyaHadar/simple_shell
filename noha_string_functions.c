#include "shell.h"

/**
 * noha_strlen - returns lenght of string
 *
 * @strc: the string we wanna leaght to check
 *
 * Return: the lenght of string
*/

int noha_strlen(char *strc)
{
	int lenght = 0;

	if (!strc)
		return (0);

	while (*strc++)
		lenght++;

	return (lenght);
}

/**
 * noha_strcmp - caparison of 2 strings
 *
 * @strc1: first string
 * @strc2: second string
 *
 * Return:positive if strc1>strc2,negatice if strc1<strc2,zero if they're equal
*/

int noha_strcmp(char *strc1, char *strc2)
{
	while (*strc1 && *strc2)
	{
		if (*strc1 != *strc2)
			return (*strc1 - *strc2);
		strc1++;
		strc2++;
	}
	if (*strc1 == *strc2)
		return (0);
	else
		return (*strc1 < *strc2 ? -1 : 1);
}

/**
 * noha_starts_with - checks if a string starts with another string
 *
 * @haystack: string we're searching for
 * @needle: substring thwt we're trying to find
 *
 * Return: adrress of next character of haytack if not (NULL)
*/

char *noha_starts_with(const char *haystack, const char *needle)
{
	if (haystack == NULL || needle == NULL)
	{
		return (NULL);
	}

	while (*needle != '\0')
	{
		if (*haystack != *needle)
		{
			return (NULL);
		}
		haystack++;
		needle++;
	}

	return ((char *)haystack);
}

/**
 * noha_strcat - contane 2 strings
 *
 * @destination: distina buffer
 * @source: source buffer
 *
 * Return: pointer to dest buffer
*/

char *noha_strcat(char *destination, char *source)
{
	char *result = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (result);
}
