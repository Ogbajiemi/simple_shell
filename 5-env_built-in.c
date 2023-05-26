#include "shell.h"

 /**
 * main - entry point to program
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
