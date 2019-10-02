/*
*/

#include "KVPstorage.h"
#include <stdio.h>
#include <stdlib.h>

t_kvp	*init_settings_list(char *filepath)
{
	t_kvp	*settings;
	FILE	*file_info;
	char	kvp[KEYSIZE + VALUESIZE];
	size_t	ret;

	settings = NULL;
	file_info = open_settings_file(filepath);
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
	fclose(file_info);
	return (settings);
}
