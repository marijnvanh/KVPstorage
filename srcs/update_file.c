/*
*/

#include "KVPstorage.h"
#include <stdlib.h>
#include <string.h>

void	update_file(FILE **file_info, t_kvp *settings)
{
	*file_info = freopen(NULL, "w", *file_info);
	if (*file_info == NULL)
	{
		perror("Error re-opening settings file");
		exit (EXIT_FAILURE);
	}
	while (settings)
	{
		fwrite(settings->key, sizeof(char), KEYSIZE, *file_info);
		fwrite(settings->value, sizeof(char), VALUESIZE, *file_info);
		settings = settings->next;
	}
}
