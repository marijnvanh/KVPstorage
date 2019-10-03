#include "KVPstorage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
The settings list is initialized with any existings settings from file.
It reads blocks of KEYSIZE + VALUESIZE = KVP size
The only validation of the file is done by checking if ret == KVP size or 0
*/

t_kvp	*init_settings_list(FILE *file_info)
{
	t_kvp	*settings;
	char	kvp[KEYSIZE + VALUESIZE];
	size_t	ret;

	settings = NULL;
	ret = 1;
	while (ret > 0)
	{
		ret = fread(kvp, sizeof(char), KEYSIZE + VALUESIZE, file_info);
		if (ferror(file_info) != 0)
		{
			perror("Error reading settings file");
			exit(EXIT_FAILURE);
		}
		if (ret == 0)
			break ;
		if (ret != KEYSIZE + VALUESIZE)
		{
			fprintf(stderr, "Corrupted settings file\n");
			exit(EXIT_FAILURE);
		}
		add_kvp_to_list(&settings, kvp);
	}
	return (settings);
}
