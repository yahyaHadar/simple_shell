#include "shell.h"

/**
 * noha_eputs - print input string
 *
 * @string: string torpint
 *
 * Return: return nothing
*/

void noha_eputs(char *string)
{
	int index = 0;

	if (!string)
		return;

	while (string[index] != '\0')
	{
		noha_eputs(string[index]);
		index++;
	}
}

/**
 * noha_eputchar - write C to stderr
 *
 * @c: character to print
 *
 * Return: success 1 if error, -1
*/

int noha_eputchar(char c)
{
	static int i;
	static char buffer[NOHA_WRITE_BUF_SIZE];

	if (c == NOHA_BUF_FLUSH || i >= NOHA_WRITE_BUF_SIZE)
	{
		write(STDERR_FILENO, buffer, i);
		i = 0;
	}
	if (c != NOHA_BUF_FLUSH)
		buffer[i++] = c;
	return (1);
}

/**
 * noha_putfd - write character c to file desc that given
 *
 * @c: character to be printed
 * @fd: file descriptor to write to
 *
 * Return: Success 1 if not and it was a error -1
*/

int noha_putfd(char c, int fd)
{
	static int i;
	static char buffer[NOHA_WRITE_BUF_SIZE];

	if (c == NOHA_BUF_FLUSH || i >= NOHA_WRITE_BUF_SIZE)
	{
		write(fd, buffer, i);
		i = 0;
	}
	if (c != NOHA_BUF_FLUSH)
		buffer[i++] = c;
	return (1);
}

/**
 * noha_putsfd - print input string to file that given
 *
 * @string: string that will be printed
 * @fd: file desc to be writed to
 *
 * Return: number of characters put
*/

int noha_putsfd(char *str, int fd)
{
	int index = 0;

	if (!str)
		return (0);

	while (*str)
	{
		index += noha_putsfd(*str++, fd);
	}

	return (index);
}
