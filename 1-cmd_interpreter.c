#include "shell.h"

/**
 * print - print the prompt
 * @av: command-line arguments
 * @env: environment variables
 */

void print(char **av, char **env)
{
	char *line_ptr = NULL, *tok;
	size_t k = 0;
	ssize_t char_count;
	char *argv[MAX_COMMAND];
	int path_index = 0, argc;
	char *path_parts[MAX_COMMAND];
	(void) av;

	_path(&path_index, path_parts);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Shell$ ", 7);
		fflush(stdout);
		char_count = getline(&line_ptr, &k, stdin);
		if (char_count == EOF)
		{
			free(line_ptr);
			break;
		}
		line_ptr[_strcspn(line_ptr, "\n")] = '\0';

		argc = 0;
		tok = strtok(line_ptr, " ");
		while (tok != NULL && argc < MAX_COMMAND - 1)
		{
			argv[argc++] = tok;
			tok = strtok(NULL, " ");
		}
		argv[argc] = NULL;
		if (argc > 0)
		handle_cmd(argv, env, path_parts, path_index);
	}
}

/**
 * init_path - Initializes/populates the array of PATH dirs by extracting the
 *             the dirs from "PATH" ENVIRON VAR
 * @path_index: Pointer to the variable storing the number of PATH directories
 * @path_parts: Array to store the PATH directories
 *
 */

void _path(int *path_index, char *path_parts[])
{
	char *path = _getenv("PATH");
	char *part = strtok(path, ":");

	while (part != NULL && *path_index < MAX_COMMAND)
	{
		path_parts[(*path_index)++] = part;
		part = strtok(NULL, ":");
	}
}
