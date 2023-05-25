#include "shell.h"

/**
 * _getenv - Retrieves values of an environ variable.
 * @name: name of the environ variable.
 *
 * Return: pointer to the value of the environ variable,
 *         or NULL if the variable is not found.
 */
char *_getenv(const char *name)
{
	char *value = NULL;
	int i;

	if (name == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		char *entry = environ[i];
		size_t name_len = 0;

		while (entry[name_len] != '=')
			name_len++;

		if (_strncmp(name, entry, name_len) == 0)
		{
			value = entry + name_len + 1;
			break;
		}
	}

	return (value);
}
