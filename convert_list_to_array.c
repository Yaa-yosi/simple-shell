#include "shell.h"
/**
 * list_to_array - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_array(list_t *head)
{
        list_t *node = head;
        size_t k = list_len(head), i, j;
        char **array;
        char *string;

        if (!head || !k)
                return (NULL);
        array = malloc(sizeof(char *) * (k + 1));
        if (!array)
                return (NULL);
        for (i = 0; node; i++)
        {
                string = malloc(strlen(node->str) + 1);
                if (!string)
                {
                        for (j = 0; j < i; j++)
                                free(array[j]);
                        free(array);
                        return (NULL);
                }

                strcpy(string, node->str);
                array[i] = string;
                node = node->next;
        }
        array[i] = NULL;
        return (array);
}

/**
 * list_len - returns number of elements in list
 * @h: pointer to nodes
 * Return: number of list elements
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}
