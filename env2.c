#include "shell.h"

/**
 * noha_get_environ - return the string array copy
 *
 * @info: struct containning argms
 *
 * Return: 0 alwys
*/

char **noha_get_environ(noha_info_t *info)
{
	if (!info->noha_environ || info->noha_env_changed)
	{
		info->noha_environ = noha_list_to_strings(info->noha_env);
		info->noha_env_changed = 0;
	}
	return (info->noha_environ);
}

/**
 * noha_unstenv - remove envirment
 *
 * @info: struct containning argms
 * @var: string env var
 *
 * Return: delete on 1 if not 0
*/

int noha_unsetenv(noha_info_t *info, char *var)
{
	list_t *node = info->noha_env;
	size_t i = 0;
	char *e;

	if (!node || !var)
		return 0;

	while (node)
	{
		e = noha_starts_with(node->str, var);
		if (e && *e == '=')
		{
			info->noha_env_changed = noha_delete_node_at_index(&(info->noha_env), i);
			i = 0;
			node = info->noha_env;
			continue;
		}
		node = node->next;
		i++;
	}
	return info->noha_env_changed;
}
