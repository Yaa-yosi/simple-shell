#ifndef SHELL_H
#define SHELL_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **environ;

/**
 * struct list_str - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct list_str
{
        int num;
        char *str;
        struct list_str *next;
} list_t;

/**
 * parseinfo - structure containing command arguments for shell
 * @env:linked list local copy of environ
 * @environ:custom modified copy of environ from LL env
 * @env_flag:on if environ was changed
 */
typedef struct parseinfo
{
        list_t *env;
        char **environ;
        int env_flag;
} info_t;


void kelm_prompt(void);
void kelmprint(const char *str);
char *check_prefix(const char *haystack, const char *needle);
list_t *add_node_end(list_t **head, const char *str, int n);
char *_getenv(info_t *info, const char *name);
int _printenv(info_t *info);
size_t print_envList(const list_t *h);
char **list_to_array(list_t *head);
size_t list_len(const list_t *h);
char **_getenviron(info_t *info);
int _setenv(info_t *info, char *envVar, char *envVal);
void free_info(info_t *info);

#endif
