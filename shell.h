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

#define DELIM " \t\n"

extern char **environ;

/*execute*/
int _execute(char **command, char **argv, int idx);

/*readline.c*/
char *read_line(void);

/* tokenizer.c*/
char **tokenizer(char *line);

/*strings.c*/
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/*tools.c*/
void freearay(char **array);
void printerror(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_string(char *str, int len);

/*tools2.c*/
int is_positive_number(char *str);
int _atoi(char *str);

/*getenv.c*/
char *_getenv(char *variable);

/*handle_path.c*/
char *_getpath(char *command);

/*handle_builtin*/
int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int idx);
void exit_shell(char **command, char **argv, int *status, int idx);
void print_env(char **command, int *status);

#endif /* SHELL_H */
