#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * main - main function
 * Return: return 0 on success else -1
 */
int main(void)
{
	size_t n = 0;
	char *buff = NULL;
	char *token = NULL;
	char **array = NULL;
	char full_path[1024];
	pid_t pid;
	char *path_array = NULL;
	char *path = NULL;
	char *path_value = NULL;
	int token_count;
	char *envVar = NULL;
	info_t *info;

	info = malloc(sizeof(info_t));
	if (info == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	info->env = NULL;
	info->env_flag = 0;
	while (1)
	{
		_setenv(info, "TERM", "xterm-256color");
		kelm_prompt();
		if (getline(&buff, &n, stdin) == -1)
		{
			free(buff);
			exit(EXIT_FAILURE);
		}

		token = strtok(buff, " \n");
		token_count = 0;
		while (token)
		{
			array = realloc(array, (token_count + 1) * sizeof(char *));
			array[token_count++] = token;
			token = strtok(NULL, " \n");
		}
		array = realloc(array, (token_count + 1) * sizeof(char *));
		if (array == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		array[token_count] = NULL;

		if (strcmp(array[0], "exit") == 0)
		{
			free(buff);
			free(array);
			break;
		}
		envVar = "PATH";
		path_value = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
		if (_setenv(info, envVar, path_value) != 0)
			perror("_setenv");

		path = _getenv(info, envVar);
		if (path == NULL)
			perror("_getenv");

		path_array = strdup(path);
		if (path_array == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(path_array, ":");
		while (token)
		{
			snprintf(full_path, sizeof(full_path), "%s/%s", token, array[0]);
			if (access(full_path, F_OK) != -1)
			{
				if ((pid = fork()) == -1)
				{
					perror("error");
					exit(EXIT_FAILURE);
				}
				if (pid == 0)
				{

					if (execve(full_path, array, _getenviron(info)) == -1)
						perror("error");
					exit(EXIT_FAILURE);
				} else
				{
					wait(NULL);
					break;
				}
			}
			token = strtok(NULL, ":");
		}

		free(path_array);
		free(array);
		free(buff);
		buff = NULL;
		array = NULL;
	}
	free_info(info);
	return (0);
}

