#include "shell.h"

/**
 * strtok - A function that split a string
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: -1
 */

int main()
{
	char *tok;
	pid_t pid;
	char *args[MAX_ARGS];
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t numvalue;
	char *errmsg;
	int count = 0;

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

		/* to remove newlines that are trailing */
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

		pid = fork();
		if (pid < 0)
		{
			perror("failed");
			free(lineptr);
			exit(1);
	
		}
		else if (pid == 0)
		{
            		/* child */
			execvp(args[0], args);
			errmsg = "No such file of directory ";
			write(STDERR_FILENO, errmsg, strlen(errmsg));
			write(STDERR_FILENO, lineptr, strlen(lineptr));
			write(STDERR_FILENO, "\n", 1);
			free(lineptr);
			exit(1);
		}
		else
		{
			/* parent process
			 * waiting for the child process to be completed */
			wait(NULL);
		}
	
	}
	return 0;
}

