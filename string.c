#include "shell.h"

/**
 * _strdup - duplicates input
 *
 * @str: string
 *
 * Return: return the value ptr
*/

char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}

/**
 * _strcmp - caparison of 2 strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return:positive if strc1>strc2,negatice if strc1<strc2,zero if they're equal
*/

int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}

/**
 * _strlen - returns lenght of string
 *
 * @s: the string we wanna leaght to check
 *
 * Return: the lenght of string
*/

int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _strcat - contane 2 strings
 *
 * @dest: distina buffer
 * @src: source buffer
 *
 * Return: pointer to dest buffer
*/

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;
	return (dest);
}

/**
 * _strcpy - copies string
 *
 * @dest: destination
 * @src: source
 *
 * Return: pointet to the destination
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
