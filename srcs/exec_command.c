/*

*/

#include "KVPstorage.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void	exec_command(t_kvp **settings, FILE *file_info, char *line)
{
	if (strncmp(line, "SET", 3) == 0 && isblank(line[3]) != 0)
		cmd_set(settings, file_info, line);
	else if (strncmp(line, "GET", 3) == 0 && isblank(line[3]) != 0)
		cmd_get(*settings, line);
	else if (strncmp(line, "DELETE", 6) == 0 && isblank(line[6]) != 0)
		cmd_delete(settings, file_info, line);
	else if (strncmp(line, "exit", 4) == 0 && line[4] == '\0')
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf(INVALID USAGE);
	}	
}
