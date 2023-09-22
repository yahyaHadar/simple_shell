#include "shell.h"

/**
 * _execute - execute the shell
 *
 * @command: array of strings
 * @argv: array of strings
 * @idx: argument
 *
 * Return: the status
*/

int _execute(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		printerror(argv[0], command[0], idx);
		freearay(command);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			freearay(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearay(command);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));

}
