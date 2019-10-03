/*
*/

#include "KVPstorage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_kvp	*init_settings_list(FILE *file_info)
{
	t_kvp	*settings;
	char	kvp[KEYSIZE + VALUESIZE];
	size_t	ret;

	settings = NULL;
	ret = 1;
	while (ret > 0)
	{
		ret = fread(kvp, sizeof(char), KEYSIZE + VALUESIZE, file_info); // maybe check for read error ?
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
