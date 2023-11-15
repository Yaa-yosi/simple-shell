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

void kelm_prompt(void);
void kelmprint(const char *str);

#endif
