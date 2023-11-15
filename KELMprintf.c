#include "shell.h"
/**
 * kelmprintf - function to print stringd
 * @str: string to print
 */
void kelmprint(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
