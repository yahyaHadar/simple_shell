#include "shell.h"

/**
 * noha_myenv - prints current envir
 *
 * @info: struct containing argum
 *
 * Return: 0 alws
*/

int noha_myenv(noha_info_t *info)
{
	noha_print_list_str(info->noha_env);
	return 0;
}

/**
 * noha_getenv - gets value of env variable
 *
 * @info: Strct containing argum
 * @name: name
 *
 * Return: return the value
*/

char *noha_getenv(noha_info_t *info, const char *name)
{
	list_t *node = info->noha_env;
	char *p;

	while (node)
	{
		p = noha_starts_with(node->str, name);
		if (p && *p)
			return p;
		node = node->next;
	}
	return NULL;
}

/**
 * noha_mysetenv - initialize the new envi or modofy it 
 *
 * @info: struct containing argum
 *
 * Return: 0 alws
*/

int noha_mysetenv(noha_info_t *info)
{
	if (info->argc != 3)
	{
		noha_eputs("the number of argument is Incorrect\n");
		return 1;
	}
	if (noha_setenv(info, info->argv[1], info->argv[2]))
		return 0;
	return 1;
}

/**
 * noha_myunsetenv - remove an envir variab
 *
 * @info: Struct containg argums
 *
 * Return: 0 alwys
*/

int noha_myunsetenv(noha_info_t *info)
{
	int i;
	if (info->argc == 1)
	{
		noha_eputs("theres just few arguments\n");
		return 1;
	}
	for (i = 1; i <= info->argc; i++)
		noha_unstenv(info, info->argv[i]);

	return 0;
}

/**
 * noha_populate_env_list - populates env list
 *
 * @info: struct containg argums
 *
 * Return: 0 always
*/

int noha_populate_env_list(noha_info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; noha_environ[i]; i++)
		 noha_add_node_end(&node, noha_environ[i], 0);
	info->noha_env = node;
	return 0;
}
