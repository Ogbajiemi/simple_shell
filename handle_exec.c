#include "shell.h"

/**
 * exec_cmd - forks a child process and executes the cmd
 * @cmd_path: the full path of the cmd
 * @argv: array of cmnd arguments
 * @env: array of env vars
 *
 * function forks a child process and executes the command.
 */
void exec_cmd(char *cmd_path, char **argv, char **env)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: Fork failed");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(cmd_path, argv, env) == -1)
		{
			perror("Error: Command execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	free(cmd_path);
}
/**
 * handle_cmd - handles cmd execution
 * @argv: array of cmd arguments
 * @env: environment variables
 * @path_parts: array of PATH directories
 * @path_index: no of PATH directories
 */
void handle_cmd(char **argv, char **env, char **path_parts, int path_index)
{
	char *err_msg;

	if (_strcmp(argv[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		print_envi(env);
	}
	else
	{
		char *cmd_path = pathfinder(argv[0], path_parts, path_index);

		if (cmd_path == NULL)
		{
			size_t err_msg_len = _strlen(argv[0]) + _strlen(": No such file or directory") + 1;

			err_msg = malloc(err_msg_len);
			if (err_msg == NULL)
			{
				perror("Error: Memory allocation failed");
				exit(EXIT_FAILURE);
			}
			_strcpy(err_msg, argv[0]);
			_strcat(err_msg, ": No such file or directory");

			_puts(err_msg);
			free(err_msg);
		}
		else
		{
			exec_cmd(cmd_path, argv, env);
		}
	}
}

