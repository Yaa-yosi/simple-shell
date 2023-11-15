#include "shell.h"
/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *info, char *envVar, char *envVal)
{
	char *buff = NULL;
	list_t *node;
	char *s;

	if (!envVar || !envVal)
		return (-1);

	buff = malloc(strlen(envVar) + strlen(envVal) + 2);
	if (!buff)
		return (-1);
	strcpy(buff, envVar);
	strcat(buff, "=");
	strcat(buff, envVal);
	node = info->env;
	while (node)
	{
		s = check_prefix(node->str, envVar);
		if (s && *s == '=')
		{
			free(node->str);
			node->str = buff;
			info->env_flag = 1;
			free(buff);
			return (0);

		}
		node = node->next;
	}	
	add_node_end(&(info->env), buff, 0);
	free(buff);
	info->env_flag = 1;
	return (0);
}
