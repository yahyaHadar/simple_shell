#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*read and write buffers*/
#define NOHA_READ_BUF_SIZE 1024
#define NOHA_WRITE_BUF_SIZE 1024
#define NOHA_BUF_FLUSH -1

/*command chining*/
#define NOHA_CMD_NORM	0
#define NOHA_CMD_OR	1
#define NOHA_CMD_AND	2
#define NOHA_CMD_CHAIN	3

/*convert_number()*/
#define NOHA_CONVERT_LOWERCASE	1
#define NOHA_CONVERT_UNSIGNED	2

/*it's using system getline() so 1*/
#define NOHA_USE_GETLINE 0
#define NOHA_USE_STRTOK 0

#define NOHA_HIST_FILE	".noha_shell_history"
#define NOHA_HIST_MAX	4096

extern char **environ;

/**
 * struct noha_liststrc - singl linked lists
 *
 * @num: number field
 * @strc: string
 * @next: points to next node
*/

typedef struct noha_liststrc
{
	int number;
	char *str_value;
	struct noha_liststrc *next;
} list_t;


/**
 * struct noha_passinfo - contains pseudo-arguments to pass into a function
 *		allowing uniform prototype for function pointer struct
 *
 * @arg: a string generated from getline containing arguments
 * @argv: an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @history: the history node
 * @alias: the alias node
 * @environ: the eviron
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
*/

typedef struct noha_passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} noha_info_t;

/*function main*/
void populate_env_list(noha_info_t *);
void read_history(noha_info_t *);

#define NOHA_INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

/**
 * struct noha_builtin - contains a builting string
 *
 * @type: builtin command flag
 * @func: fuction
*/

typedef struct noha_builtin
{
	char *type;
	int (*func)(noha_info_t *);
} noha_builtin_table;

/* shell.c*/
int noha_shell(noha_info_t *, char **);
int noha_find_builtin(noha_info_t *);
void noha_find_cmd(noha_info_t *);
void noha_fork_cmd(noha_info_t *);

/* noha_path.c*/
int noha_is_cmd(noha_info_t *, char *);
char *noha_dup_chars(char *, int, int);
char *noha_find_path(noha_info_t *, char *, char *);

/* noha_loophsh.c*/
int noha_loophsh(char **);

/* noha_err_string_functions.c */
void noha_eputs(char *);
int noha_eputchar(char);
int noha_putfd(char c, int fd);
int noha_putsfd(char *str, int fd);

/* noha_string_functions.c*/
int noha_strlen(char *);
int noha_strcmp(char *, char *);
char *noha_starts_with(const char *, const char *);
char *noha_strcat(char *, char *);

/* noha_string_functions2.c */
char *noha_strcpy(char *, char *);
char *noha_strdup(const char *);
void noha_puts(char *);
int noha_putchar(char);

/* noha_string_functions3.c */
char *noha_strncpy(char *, char *, int);
char *noha_strncat(char *, char *, int);
char *noha_strchr(char *, char);

/* noha_string_functions4.c */
char **noha_strtow(char *, char *);
char **noha_strtow2(char *, char);

/* noha_memory_functions */
char *noha_memset(char *, char, unsigned int);
void noha_ffree(char **);
void *noha_realloc(void *, unsigned int, unsigned int);

/* noha_memory_functions2.c */
int noha_bfree(void **);

/* noha_more_functions.c */
int noha_interactive(noha_info_t *);
int noha_is_delim(char, char *);
int noha_isalpha(int);
int noha_atoi(char *);

/* noha_more_functions2.c */
int noha_erratoi(char *);
void noha_print_error(noha_info_t *, char *);
int noha_print_d(int, int);
char *noha_convert_number(long int, int, int);
void noha_remove_comments(char *);

/* noha_builtin_emulators.c */
int noha_myexit(noha_info_t *);
int noha_mycd(noha_info_t *);
int noha_myhelp(noha_info_t *);

/* noha_builtin_emulators2.c */
int noha_myhistory(noha_info_t *);
int noha_myalias(noha_info_t *);

/* noha_getline.c module */
ssize_t noha_get_input(noha_info_t *);
int noha_getline(noha_info_t *, char **, size_t *);
void noha_sigintHandler(int);

/* noha_info.c module */
void noha_clear_info(noha_info_t *);
void noha_set_info(noha_info_t *, char **);
void noha_free_info(noha_info_t *, int);

/* noha_liststr.c module */
list_t *noha_add_node(list_t **, const char *, int);
list_t *noha_add_node_end(list_t **, const char *, int);
size_t noha_print_list_str(const list_t *);
int noha_delete_node_at_index(list_t **, unsigned int);
void noha_free_list(list_t **);

/* noha_liststr2.c module */
size_t noha_list_len(const list_t *);
char **noha_list_to_strings(list_t *);
size_t noha_print_list(const list_t *);
list_t *noha_node_starts_with(list_t *, char *, char);
ssize_t noha_get_node_index(list_t *, list_t *);

/* noha_info.c module */
void noha_clear_info(noha_info_t *);
void noha_set_info(noha_info_t *, char **);
void noha_free_info(noha_info_t *, int);

#endif
