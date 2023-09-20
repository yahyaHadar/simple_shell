#include "shell.h"

/**
 * noha_clear_info - initial noha_info_t struucture
 *
 * @shell_info: str address
*/

void noha_clear_info(noha_info_t *shell_info)
{
	shell_info->input_str = NULL;
	shell_info->args = NULL;
	shell_info->path = NULL;
	shell_info->arg_count = 0;
}

/**
 * noha_set_info - initial noha_info_t structure
 *
 * @shell_info: str address
 * @arg_vector: argument vec
*/

void noha_set_info(noha_info_t *shell_info, char **arg_vector)
{
	int index = 0;

	shell_info->progran_name = arg_vector[0];
	if (shell_info->input_str)
	{
		shell_info->args = noha_strtow(shell_info->input_str, " \t");
		if (!shell_info->args)
		{
			shell_info->args = malloc(sizeof(char *) * 2);
			if (shell_info->args)
			{
				shell_info->args[0] = noha_strdup
					(shell_info->input_str);
				shell_info->args[1] = NULL;
			}
		}

		for (index = 0;	shell_info->args && shell_info->args[index]; index++)
			;
		shell_info->arg_count = index;

		noha_replace_alias(shell_info);
		noha_replace_vars(shell_info);
	}
}

/**
 * noha_free_info - free noha_info_t field
 *
 * @shell_info: struct address
 * @all: true if it free all fields
*/

void noha_free_info(noha_info_t *shell_info, int all)
{
	noha_ffree(shell_info->args);
	shell_info->args = NULL;
	shell_info->path = NULL;
	if (all)
	{
		if (!shell_info->command_buffer)
			free(shell_info->input_str);
		if (shell_info->environment)
			noha_free_list(&(shell_info->environment));
		if (shell_info->history)
			noha_free_list(&(shell_info->history));
		if (shell_info->alias_list)
			noha_free_list(&(shell_info->alias_list));
		noha_ffree(shell_info->environ);
		shell_info->environ = NULL;
		noha_bfree((void **)shell_info->command_buffer);
		if (shell_info->read_fd > 2)
			close(shell_info->read_fd);
		noha_putchar(BUF_FLUSH);
	}
}
