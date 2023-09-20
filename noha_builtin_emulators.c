#include "shell.h"

/**
 * noha_myexit - exit shell
 *
 * @info: Structure can have arguments
 *
 * Return: wxit if statuts exit is 0
*/

int noha_myexit(noha_info_t *info)
{
	int exit_check;

	if (info->argv[1])
	{
		exit_check = noha_erratoi(info->argv[1]);
		if (exit_check == -1)
		{
			info->status = 2;
			noha_print_error(info, "the number is ILLEGAL: ");
			noha_eputs(info->argv[1]);
			noha_eputchar('\n');
			return (1);
		}
		info->err_num = noha_erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * noha_mycd - change current directory of process
 *
 * @info: Structure can have arguments
 *
 * Return: 0 alwys
*/

int noha_mycd(noha_info_t *info)
{
	char *current_dir, *new_dir, buffer[1024];
	int chd_ret;

	current_dir = getcwd(buffer, 1024);
	if (!current_dir)
		noha_puts("TODO: >>getcwd fail emsg <<\n");
	if (!info->argv[1])
	{
		new_dir = noha_getline(info, "HOME=");
		if (!new_dir)
			chd_ret = /* TODO: what do you mean by this? */
				chdir((new_dir = noha_getline(info, "PWD="))
						? new_dir : "/");
		else
			chd_ret = chdir(new_dir);
	}
	else if (noha_strcmp(info->argv[1], "-") == 0)
	{
		if (!noha_getenv(info, "OLDPWD="))
		{
			noha_puts(current_dir);
			noha_putchar('\n');
			return (1);
		}
		noha_puts(noha_getenv(info, "OLDPWD=")), noha_putchar('\n');
		chd_dir = /* TODO: what do you mean by this? */
			chdir((new_dir = noha_getenv(info, "OLDPWD="))
					? new_dir : "/");
	}
	else
		chd_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		noha_print_error(info, "fail cd to ");
		noha_eputs(info->argv[1]), noha_eputchar('\n');
	}
	else
	{
		noha_setenv(info, "OLDPWD", noha_getenv(info, "PWD="));
		noha_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * noha_myhelp - help info
 *
 * @info: structute can have arguments
 *
 * Return: 0 alwys
*/

int noha_myhelp(noha_info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	noha_puts("help call this function is still not implemented \n");
	if (0)
		noha_puts(*arg_array);
	return (0);
}
