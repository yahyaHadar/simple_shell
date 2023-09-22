#include "shell.h"

/**
 * is_positive_number - checking that string given if postive
 *
 * @str: string the check
 *
 * Return: if postive return 1 if not 0
*/

int is_positive_number(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - convert a strin to integer
 *
 * @str: string to be convert
 *
 * Return: if no nubers in string it's a 0 if not convert number
*/

int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i] ; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
