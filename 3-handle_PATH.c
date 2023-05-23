#include "shell.h"

/**
 * getenv - A function that retrieve the value of an environment variable
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: -1
 */

int main()
{
	char *tok;
	char *args[MAX_ARGS];
	char *lineptr = NULL;
	int command_exists = 0;
	char command_path[256];
	char *error_message;
	size_t n = 0;
	char *path;
	char *path_token;
	ssize_t numvalue;
	int count = 0;
	pid_t pid;

	while (1)
	{
		write(STDOUT_FILENO, "Ogbaji&Pearlie$ ", 16);

		numvalue = getline(&lineptr, &n, stdin);
		if (numvalue == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(lineptr);
			exit(0);
		}

		/* to remove trailing newlines */
		if (lineptr[numvalue - 1] == '\n')
		{
			lineptr[numvalue - 1] = '\0';
		}

		/* Tokenization of command line */
		tok = strtok(lineptr, " ");
		while (tok != NULL && count < MAX_ARGS - 1)
		{
			args[count] = tok;
			count++;
			tok = strtok(NULL, " ");
		}
		
		args[count] = NULL;

		/* To Check if the command exists in PATH */
		path = getenv("PATH");
		path_token = strtok(path, ":");
		while (path_token != NULL)
		{
			snprintf(command_path, sizeof(command_path), "%s/%s", path_token, args[0]);
			if (access(command_path, X_OK) == 0)
			{
				/* Command exists */
				command_exists = 1;
				args[0] = command_path;
				break;
			}
			path_token = strtok(NULL, ":");
		}
		
		if (!command_exists)
		{
			error_message = "Command not found: ";
			write(STDERR_FILENO, error_message, strlen(error_message));
			write(STDERR_FILENO, args[0], strlen(args[0]));
			write(STDERR_FILENO, "\n", 1);
			continue;
		}

		pid = fork();
		if (pid < 0)
		{
			perror("failed");
			free(lineptr);
			exit(1);
	
		}
		else if (pid == 0)
		{
			/* child parent */
			execve(args[0], args, NULL);
			perror("execvp failed");
			free(lineptr);
			exit(1);
		}
		else
		{
			/* parent
			 * waiting for the child process to be completed */
			wait(NULL);
		}
	
	}
	return 0;
}
