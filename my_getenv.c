#include "shell.h"
/**
 * _printenv - prints the current environment
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _printenv(info_t *info)
{
	print_envList(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments.
 * @name: environment variable name
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *s;

	while (node)
	{
		s = check_prefix(node->str, name);
		if (s && *s)
			return (s);
		node = node->next;
	}
	return (NULL);
}

/**
 * print_list - prints all elements of a list
 * @h: pointer to the first node
 * Return: number of nodes
 */
size_t print_envList(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("(nil)\n");
		else
			printf("%s\n", h->str);
		h = h->next;
		count++;
	}
	return (count);
}
