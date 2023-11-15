#include "shell.h"
/**
 * add_node_end - adds not at the end of list
 * @head: double pointer to list
 * @str: string to be duplicated
 * Return: address of node, else NULL
 */
list_t *add_node_end(list_t **head, const char *str, int n)
{
	list_t *newnode, *tmp;
	unsigned int i, count = 0;

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
		return (NULL);
	newnode->str = strdup(str);
	for (i = 0; str[i] != '\0'; i++)
		count++;
	newnode->num = n;
	newnode->next = NULL;
	tmp = *head;
	if (tmp == NULL)
		*head = newnode;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newnode;
	}
	return (*head);
}
