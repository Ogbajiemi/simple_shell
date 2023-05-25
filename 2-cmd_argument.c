#include "shell.h"
/**
 * builtin_path - full path of a command
 * @dir: the directory path
 * @command: the command name
 *
 * Return: a pointer to the constructed full path
 */

char *builtin_path(char *dir, char *command)
{
	char *_path;

	_path = malloc(_strlen(dir) + _strlen(command) + 2); /* 1=/n & 1="/"*/
	_strcpy(_path, dir);
	_strcat(_path, "/");
	_strcat(_path, command);

	return (_path);
}

/**
 * print_envi - corrent environ
 * @env: array of envir vars
 *
 * function prints each env var in the array.
 */

void print_envi(char **env)
{
	char **envp = env;

	for (; *envp; envp++)
	{
		_puts(*envp);
	}
}

/**
 * pathfinder - path construct command
 * @command: the command name
 * @path_parts: array of path dirs
 * @path_index: number of path dirs
 *
 * Return: pointer to full path, or NULL if not found
 */

char *pathfinder(char *command, char **path_parts, int path_index)
{
	int j;
	char *cmd_path = NULL;

	if (_strchr(command, '/'))
	{
		if (access(command, F_OK) == 0)
		{
			cmd_path = _strdup(command);
		}
	}
	else
	{

		for (j = 0; j < path_index; j++)
		{
			char *temp_path = builtin_path(path_parts[j], command);

			if (access(temp_path, F_OK) == 0)
			{
				cmd_path = temp_path;
				break;
			}
			else
			{
				free(temp_path);
			}
		}
	}

	return (cmd_path);
}
