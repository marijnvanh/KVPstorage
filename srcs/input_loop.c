/*
*/

#include "KVPstorage.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void	input_loop(void)
{
	char	*line;
	size_t	len;
	ssize_t	ret;

	while (1)
	{
		printf("> ");
		line = NULL;
		ret = getline(&line, &len, stdin);
		if (ret < 0)
		{
			perror("Error reading stdin");
			exit (EXIT_FAILURE) ;
		}
		exec_command(line);
		putchar('\n');
	}
}
