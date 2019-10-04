#include "KVPstorage.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
Exec_command compares the input with every possible cmd name
When a cmd name is found, it calls the appropriate cmd function
If no cmd is found it prints the USAGE of KVKstorage
*/

void	exec_command(t_kvp **settings, t_fileinfo *fileinfo, char *line)
{
	if (strncmp(line, "SET", 3) == 0 && isblank(line[3]) != 0)
		cmd_set(settings, fileinfo, line + 4);
	else if (strncmp(line, "GET", 3) == 0 && isblank(line[3]) != 0)
		cmd_get(*settings, line + 4);
	else if (strncmp(line, "DELETE", 6) == 0 && isblank(line[6]) != 0)
		cmd_delete(settings, fileinfo, line + 7);
	else if (strncmp(line, "GETALL", 6) == 0 && line[6] == '\0')
		cmd_getall(*settings);
	else if (strncmp(line, "exit", 4) == 0 && line[4] == '\0')
		exit(EXIT_SUCCESS);
	else
		printf(INVALID USAGE);
}
