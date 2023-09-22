#include "shell.h"

/**
 * is_builtin - where the function is built
 *
 * @command: the command
 *
 * Return: if succses 1 if not 0
*/

int is_builtin(char *command)
{
	char *builtins[] = {
		"exit", "env", "setenv", "cd", NULL
	};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtin - a function to handle the builting
 *
 * @command: the command
 * @argv: argument
 * @status: pointur
 * @idx: index
*/

void handle_builtin(char **command, char **argv, int *status, int idx)
{
	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, argv, status, idx);

	else if (_strcmp(command[0], "env") == 0)
		print_env(command, status);
}

/**
 * exit_shell - exit shell
 *
 * @command: the command
 * @argv: argument
 * @status: pointur
 * @idx: index
 *
 * Return: exit if status is 0
*/

void exit_shell(char **command, char **argv, int *status, int idx)
{
	int exit_value = (*status);
	char *index, msg[] = ": exit: the number is illegal: ";

	if (command[1])
	{
		if (is_positive_number(command[1]))
		{
			exit_value = _atoi(command[1]);
		}
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			freearay(command);
			(*status) = 2;
			return;
		}
	}
	freearay(command);
	exit(exit_value);
}

/**
 * print_env - printer of env
 *
 * @command: the command
 * @status: pointur
*/

void print_env(char **command, int *status)
{
	int i;
	(void) status;


	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearay(command);
	(*status) = 0;
}
