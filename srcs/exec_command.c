/*

*/

#include "KVPstorage.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void	exec_command(char *line)
{
	if (strncmp(line, "SET ", 4) == 0)
	{
		printf("SET");
	}
	else if (strncmp(line, "GET ", 4) == 0)
	{
		printf("GET");
		;
	}
	else if (strncmp(line, "DELETE ", 7) == 0)
	{
		printf("DELTE");
	}
	else if (strncmp(line, "exit", 4) == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf(USAGE);
	}	
}
