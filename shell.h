#ifndef MAIN_H
#define MAIN_H

#define MAX_COMMAND 10
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>

extern char **environ;
int space_check(char *lineptr);
char *_getenv(const char *name);
size_t _strcspn(const char *str, const char *rej);
char *_strdup(const char *str);
char *_strchr(const char *s, int c);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
size_t _strlen(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);
int _puts(const char *str);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void print(char **av, char **env);
char *builtin_path(char *dir, char *command);
void handle_cmd(char **argv, char **env, char **path_parts, int path_index);
void print_envi(char **env);
char *pathfinder(char *command, char **path_parts, int path_index);
void exec_cmd(char *cmd_path, char **argv, char **env);
void _path(int *path_index, char *path_parts[]);


#endif
