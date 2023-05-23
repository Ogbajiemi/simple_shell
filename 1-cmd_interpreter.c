#include "shell.h"

/**
 * main -nterpretes command line 
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: -1
 */
int main()
{
	char *args[256];
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t numvalue;
	char *errmsg;
	pid_t pid;
	args[0] = lineptr;
	args[1] = NULL;
	
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

		/* to remove trailing new lines */
		if (lineptr[numvalue - 1] == '\n')
		{
			lineptr[numvalue - 1] = '\0';
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
			/* child */
			execve(lineptr, args, NULL);
			errmsg = "No such file of directory ";
			write(STDERR_FILENO, errmsg, strlen(errmsg));
			write(STDERR_FILENO, lineptr, strlen(lineptr));
			write(STDERR_FILENO, "\n", 1);
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
	return (0);
}
