#include "shell.h"

/**
 * noha_is_cmd - determines if a file is exu command
 *
 * @shell_info: shell_info struct
 * @file_path: path to file
 *
 * Return: 1 if true or 0
*/

int noha_is_cmd(noha_info_t *shell_info, char *file_path)
{
	struct stat file_stat;

	(void)shell_info;
	if (!file_path || stat(file_path, &file_stat))
		return (0);

	if (file_stat.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * noha_dup_chars - duplicates charac
 *
 * @path_string: path string
 * @start_index: start index
 * @stop_index: stop index
 *
 * Return: pointer to the new buffer
*/

char *noha_dup_chars(char *path_string, int start_index, int stop_index)
{
	static char buffer[1024];
	int i = 0, k = 0;

	for (k = 0, i = start_index; i < stop_index; i++)
		if (path_string[i] != ':')
			buffer[k++] = path_string[i];
	buffer[k] = 0;

	return (buffer);
}

/**
 * noha_find_path - finds cmd in path string
 *
 * @shell_info: shell_info struct
 * @path_string: path string
 * @command: cmd to find
 *
 * Return: cmd full path or null
*/

char *noha_find_path(noha_info_t *shell_info, char *path_string, char *command)
{
	int i = 0, current_pos = 0;
	char *path;

	if (!path_string)
		return (NULL);
	if ((_strlen(command) > 2) && starts_with(command, "./"))
	{
		if (noha_is_cmd(shell_info, command))
			return (command);
	}

	while (1)
	{
		if (!path_string[i] || path_string[i] == ':')
		{
			path = noha_dup_chars(path_string, current_pos, i);
			if (!*path)
				_strcat(path, command);
			else
			{
				_strcat(path, "/");
				_strcat(path, command);
			}
			if (noha_is_cmd(shell_info, path))
				return (path);
			if (!path_string[i])
				break;
			current_pos = i;
		}
		i++;
	}
	return (NULL);
}
