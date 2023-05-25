#include "shell.h"

/**
 * _strcspn - Finds length of initial segment of a str
 *             that contains chars not in the reject str.
 * @str: The str to search.
 * @rej: The str containing the chars to reject.
 *
 * Return: The no of chars in the initial segment of @str that do not
 *         appear in the @reject str.
 */

size_t _strcspn(const char *str, const char *rej)
{
	size_t count = 0;

	while (*str)
	{
		const char *ptr = rej;

		while (*ptr)
		{
			if (*ptr == *str)
				return (count);
			ptr++;
		}
		str++;
		count++;
	}

	return (count);
}
/**
 * _strcmp - Compares two strings.
 * @s1: first string.
 * @s2: second string.
 *
 * Return: 0 if the strings are equal, a (-) value if s1 < s2,
 *         or a (+) value if @s1 > @s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strchr - Locates first  occurrence of a character in a string.
 * @s: string to be searched
 * @c: character to be located.
 *
 * Return: pointer to the first occurrence of the char c in the string s,
 *         or NULL if the character is not found.
 */
char *_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/**
 * _strdup - Duplicates a str.
 * @str: str to duplicate.
 *
 * Return: pointer to the newly allocated dupl str,
 *         or NULL if insufficient memory is available.
 */
char *_strdup(const char *str)
{
	char *dup;
	size_t len, i;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len])
		len++;

	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[len] = '\0';

	return (dup);
}
/**
 * _strcpy - Copies string, including null-terminating character.
 * @dest: destination buffer.
 * @src: source string.
 *
 * Return: pointer to the destination buffer.
 */
char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (ptr);
}

