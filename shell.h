#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>

void non_interact(char *prg_path);
char **get_input(char **cmd_buff, int *counter);
extern char **environ;
char **parse_line(char *line);
void hsh_loop(char *prg_path);
ssize_t read_line(char **cmd_buff);
void print_prompt(char *prompt);
char *find_exe(char *cmd);
char *_strcat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);
char *get_env(char *name);
int cmd_exec(char **input, int *hsh_status);
void hsh_env(char **input, int *status);
int is_a_path(const char *cmd);
int check_builtin(char **input, char *prg_path, int *count, int flag, int *status, int *hsh_status);
int _putchar(int c);
int _puts(char *str);
void hsh_exit(char **input, char *prg_path, int flag, int *hsh_status);
void free_block(char **input);

#endif
