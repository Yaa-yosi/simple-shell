#include "shell.h"
/**
 * _getenviron - returns the string array copy of our environ
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
char **_getenviron(info_t *info)
{
	if (!info->environ || info->env_flag)
	{
		info->environ = list_to_array(info->env);
		info->env_flag = 0;
	}

	return (info->environ);
}
