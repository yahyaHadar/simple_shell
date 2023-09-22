#include "shell.h"

/**
 * _getenv - get value of env variable
 *
 * @variable: variables
 *
 * Return: returne the value
*/

char *_getenv(char *variable)
{
	int i;
	char *env, *tmp, *key, *value;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
