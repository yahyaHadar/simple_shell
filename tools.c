#include "shell.h"

/**
 * freearay - free memory allocated
 *
 * @array: array of strings
*/

void freearay(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i]; i++)
	{
		free(array[i]), array[i] = NULL;
	}
	free(array), array = NULL;
}

/**
 * printerror - print an error
 *
 * @name: name
 * @cmd: command or input caused error
 * @idx: index
*/

void printerror(char *name, char *cmd, int idx)
{
	char *index, msg[] = ": not found pls check\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(index);
}

/**
 * _itoa - Conver an integer to string
 *
 * @n: integer to convert
 *
 * Return: allocated string containing the integer
*/

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}

/**
 * reverse_string - Reverse a string inplace
 *
 * @str: string to reverse
 * @len: length of the strin
*/

void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
