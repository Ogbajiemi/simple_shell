#include "shell.h"
/**
 * _puts - Writes string to std output
 * @str: string to be written
 *
 * Return: On success, the number of chars written.
 * On error, -1 is returned, and errno is set.
 */
int _puts(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	if (write(STDOUT_FILENO, str, len) == -1)
	{
		return (-1);
	}
	if (write(STDOUT_FILENO, "\n", 1) == -1)
	{
		return (-1);
	}
	return (len + 1);
}
