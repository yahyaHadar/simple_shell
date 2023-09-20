#include "shell.h"

/**
 * noha_split_string - split a string into words
 *
 * @str: input string
 * @delimiter: delimiter string
 *
 * Return: pointer to an array of string or fail
*/

char **noha_split_string(char *str, char *delimiter)
{
	int i, j, k, m, numWords = 0;
	char **result;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!delimiter)
		delimiter = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!noha_is_delimiter(str[i]), delimiter)
			&&(noha_is_delimiter(str[i + 1]), delimiter) ||
				!str[i + 1]))
					numWords++;

	if (numWords == 0)
		return (NULL);
	result = malloc((1 + numWords) * sizeof(char *));
	if (!result)
		return (NULL);
	for (i = 0, j = 0; j < numWords; j++)
	{
		while (noha_is_delimiter(str[i], delimiter))
			i++;
		k = 0;
		while (!noha_is_delimiter(str[i + k], delimiter) && str[i + k])
			k++;
		result[j] = malloc((k + 1) * sizeof(char));
		if (!result[j])
		{
			for (k = 0; k < j; k++)
				free(result[k]);
			free(result);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			result[j][m] = str[i++];
		result[j][m] = 0;
	}

	result[j] = NULL;
	return (result);
}

/**
 * noha_split_string2 - split a string into words
 *
 * @str: input string
 * @delimiter: delimiter
 *
 * Return: pointer to an array of strings or null
*/

char **noha_split_string2(char *str, char delimiter)
{
	int i, j, WordCount = 0;
	char **result;

	if (!input || !inpute[0])
		return (NULL);
	for (i = 0; input[i];)
	{
		if (input[i] == delimiter)
			i++;
		else
		{
			WordCount++;
			while (input[i] && input[i] != delimiter)
				i++;
		}
	}
	if (WordCount == 0)
		return (NULL);
	result = malloc((1 + WordCount) * sizeof(char *));
	if (!tokens)
		return (NULL);
	for (i = 0, j = 0; j < WordCount; j++)
	{
		while (input[i] == delimiter)
			i++;
		k = 0;
		while (input[i + k] != delimiter && input[i + k])
			k++;
		result[j] = malloc((k + 1) * sizeoff(char));
		if (!result[j])
		{
			while (j-- >= 0)
				free(result[j]);
			free(result);
			return (NULL);
		}
		for (k = 0; input[i] && input[i] != delimiter; k++)
			result[j][k] = input[i++];
		result[j][k] = '\0';
	}
	result[j] = NULL;
	return (result);
}
