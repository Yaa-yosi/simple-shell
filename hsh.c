#include "shell.h"
/**
 * main - entry point
 */
int main(void)
{
	pid_t child_pid;
	int status;
	char **array;
	char *buff = NULL;
	char *token;
	int i = 0;
	size_t n = 0;

	while (1)
	{
		kelm_prompt();
		getline(&buff, &n, stdin);
		token = strtok(buff, "\t\n");
		array = malloc(sizeof(char *) * 1024);
		if (!array)
			return (-1);
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, "\t\n");
			i++;
		}
		if (strcmp((array[0]), "exit") == 0)
		       break;	
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
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
	return (0);
}
