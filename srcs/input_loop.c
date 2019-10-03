/*
*/

#include "KVPstorage.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void	input_loop(t_kvp **settings, FILE *file_info)
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
		if (ret < 0) // add if no error happened continue
		{
			perror("Error reading stdin");
			exit (EXIT_FAILURE) ;
		}
		if (ret < 2)
			continue ;
		else
			line[ret - 1] = '\0';
		exec_command(settings, file_info, line);
	}
}
