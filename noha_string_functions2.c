#include "shell.h"

/**
 * noha_copy_string - copies string
 *
 * @dest: destination
 * @src: source
 *
 * Return: pointet to the destination
*/

char *noha_copy_string(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * noha_duplicate_string - to duplicates a string
 *
 * @str: string to duplicate
 *
 * Return: pointer to duplicate strings
*/

char *noha_duplicate_string(const char *str)
{
	int lenght = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		lenght++;
	ret = malloc(sizeof(char) * (lenght + 1));
	if (!ret)
		return (NULL);
	for (lenght++; lenght--;)
		ret[lenght] = *--str;
	return (ret);
}

/**
 * noha_print_string - prints is the input string
 *
 * @str: string to be printed
 *
 * Return: Nothing
*/

void noha_print_string(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		niha_put_char(str[i]);
		i++;
	}
}

/**
 * noha_put_char - write character c to stdout
 *
 * @c: character tp be printed
 *
 * Return: on succes 1. error -1
*/

int noha_put_char(char c)
{
	static int i;
	static char buf[WRITE_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= WRITE_BUFFER_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUFFER_FLUSH)
		buf[i++] = c;
	return (1);
}
