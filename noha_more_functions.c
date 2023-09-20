#include "shell.h"

/**
 * noha_interactive - return true if shell is interactive
 *
 * @info: adress struct
 *
 * Return: if interactive is 1 if not it's 0
*/

int noha_interactive(noha_info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * noha_delim - checks if the character is delimiter
 *
 * @c: carachter to check
 * @delim_str: delimiter string
 *
 * Return: 1 if true otherwise 0 if failed
*/

int noha_delim(char c, char *delim_str)
{
	while (*delim_str)
		if (*delim_str++ == c)
			return (1);
	return (0);
}

/**
 * noha_alpha - check for an alpjabet letter
 *
 * @c: charachter to check
 *
 * Return: c is alphabetic then it's 1 if not 0
*/

int noha_alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * noha_atoi - convert a strin to integer
 *
 * @str: string to be convert
 *
 * Return: if no nubers in string it's a 0 if not convert number
*/

int noha_atoi(char *str)
{
	int i, sign = 1, flag = 0, result;
	unsigned int num = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			num *= 10;
			num += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2l;
	}
	if (sign == -1)
		result = -num;
	else
		result = num;

	return (result);
}
