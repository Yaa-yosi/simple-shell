#include "shell.h"

void free_info(info_t *info) {
    list_t *current = info->env;
    list_t *next;
    int i;

    while (current != NULL) {
        next = current->next;
        free(current->str);  
        free(current);
        current = next;
    }

    if (info->environ != NULL) {
        for (i = 0; info->environ[i] != NULL; i++) {
            free(info->environ[i]);
        }
        free(info->environ);
    }

    free(info);
}

