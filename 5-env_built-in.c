#include "shell.h"
#include <stdio.h>
 /**
 * @main:  entry point of the program
 * main - the entry point
 * @ac: No of cmd-line arguments
 * @av: Array of cmd-line arguments
 * @env: Array of environ variables
 *
 * Return: Always 0
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
		print(av, env);
	return (0);
}
