#include "shell.h"
#include <stdio.h>
#include <string.h>

/**
 * _strlen - Calculates length of a str.
 * @str: str whose length is to be calculated.
 *
 * Return: length of str.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str)
	{
		len++;
		str++;
	}

	return (len);
}

/**
 * _strcat - concatenates a str to the end of other str.
 * @dest: destination str.
 * @src: source str to be appended.
 *
 * Return: pointer to the destination str.
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest;

	while (*dest)
		dest++;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (ptr);
}

/**
 * _strncmp - Compares strings up to a specific no of chars.
 * @str1: first str to compare.
 * @str2: second str to compare.
 * @n: maximum number of chars to compare.
 *
 * Return: 0 if the strings are equal up to a specific no of chars,
 *         negative value if str1 < str2, or positive value if str1 > str2.
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i = 0;

	while (i < n && str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;
	}

	if (i == n)
	{
		return (0);
	}
	else
	{
		return (str1[i] - str2[i]);
	}
}


