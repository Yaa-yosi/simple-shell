#include "shell.h"
/**
 * main - entry point
 */
int main(void)
{
	pid_t child_pid;
	int status;
	char full_path[1024];
	char **array, **path_array;
	char *buff = NULL;
	char *token, *tok, *path_val;
	int i = 0, j = 0;
	size_t n = 0, k = 4;

	while (1)
	{
		kelm_prompt();
		getline(&buff, &n, stdin);
		token = strtok(buff, " \n");
		array = malloc(sizeof(char *) * 1024);
		if (!array)
			return (-1);
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}
		array[i] = NULL;
		if (strcmp((array[0]), "exit") == 0)
			break;
		if (strncmp(array[0], "/bin", k) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
			if (child_pid == 0)
			{
				if (execve(array[0], array, environ) == -1)
				{
					perror("error");
					exit(EXIT_FAILURE);
				}
			}
			else
				wait(&status);
			i = 0;
			free(array);
		}
		else
		{	
			path_val = getenv("PATH");
			tok = strtok(path_val, ":");
			path_array = malloc(sizeof(char *) * 1024);
			if (!path_array)
				exit(EXIT_FAILURE);
			while (tok)
			{
				path_array[j] = tok;
				tok = strtok(NULL, ":");
				j++;
			}
			path_array[j] = NULL;
			snprintf(full_path, sizeof(full_path), "%s/%s", path_array[5], array[0]);
			/*printf("%s\n", full_path);*/
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
			if (child_pid == 0)
			{
				if (execve(full_path, array, environ) == -1)
				{
					perror("error");
					exit(EXIT_FAILURE);
				}
			}
			else
				wait(&status);
			i = 0;
			free(array);
			free(path_array);
		}
	}
	return (0);
}
