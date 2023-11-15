#include "shell.h"
/**
 * kelm_promt - function to display promt
 */
void kelm_prompt(void)
{
/*	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	setenv("LOGNAME", "Kelvin", 1);
	char *username = getlogin();
	char hostname[1024];
	gethostname(hostname, sizeof(hostname));*/
	kelmprint("WELCOME TO THE KELL SHELL ): ~ ");
	/*printf("%s@%s:%s$ ", username, hostname, cwd);*/
}
