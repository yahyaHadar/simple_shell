#include "shell.h"


/**
 * noha_main - entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Reurn: success means 0 or 1 on error
*/

int noha_main(int argc, char **argv)
{
	noha_info_t info[] = NOHA_INFO_INIT;
	int file_descriptor = 2;


	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (file_descriptor)
		: "r" (file_descriptor));

	if (argc == 2)
	{
		file_descriptor = open(argv[1], O_RDONLY);
		if (file_descriptor == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				noha_eputs(argv[0]);
				noha_eputs(": 0: this file can't open ");
				noha_eputs(argv[1]);
				noha_eputchar('\n');
				noha_eputchar(NOHA_BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = file_descriptor;
	}
	populate_env_list(info);
	read_history(info);
	noha_shell(info, argv);
	return (EXIT_SUCCESS);
}
