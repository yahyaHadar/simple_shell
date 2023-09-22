#include "shell.h"


/**
 * main - entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: success means 0 or 1 on error
*/

int main(int argc, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, idx = 0;
	(void)argc;
	
	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n ", 1);
			}
			return (status);
		}
		idx++;
		command = tokenizer(line);

		if (!command)
		{
			continue;
		}
		if (is_builtin(command[0]))
		{
			handle_builtin(command, argv, &status, idx);
		}
		else
		{
			status = _execute(command, argv, idx);
		}
	}
}
