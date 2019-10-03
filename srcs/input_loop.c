#include "KVPstorage.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

/*
Input loop keeps requesting input from stdin
Each line is validated and executed in exec_command
If line is empty the read loop continues with a new prompt
The '\n' is removed from line before exec_command
*/

void	input_loop(t_kvp **settings, t_fileinfo *fileinfo)
{
	char	*line;
	size_t	linecap;
	ssize_t	ret;

	while (1)
	{
		printf("> ");
		line = NULL;
		linecap = 0;
		ret = getline(&line, &linecap, stdin);
		if (ret < 0)
		{
			perror("Error reading stdin");
			exit (EXIT_FAILURE) ;
		}
		if (ret < 2)
		{
			free(line);
			continue ;
		}
		else
			line[ret - 1] = '\0';
		exec_command(settings, fileinfo, line);
		free(line);
	}
}
