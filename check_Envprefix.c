#include "shell.h"
/**
 * check_prefix - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */

char *check_prefix(const char *haystack, const char *needle)
{
	while (*needle != '\0')
		{
		if (*needle++ != *haystack++)
		return (NULL);
		}
		haystack++;
		return ((char *)haystack);

}
