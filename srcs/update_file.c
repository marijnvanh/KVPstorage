#include "KVPstorage.h"
#include <stdlib.h>
#include <string.h>

/*
Each time anything changes in settings list all settings are written to file
*/

void	update_file(t_fileinfo *fileinfo, t_kvp *settings)
{
	fileinfo->stream = freopen(fileinfo->filepath, "r+", fileinfo->stream);
	if (fileinfo->stream == NULL)
	{
		perror("Error re-opening settings file");
		exit(EXIT_FAILURE);
	}
	while (settings != NULL)
	{
		if (fwrite(settings->key, sizeof(char), KEYSIZE, fileinfo->stream) != KEYSIZE)
		{
			perror("Error writing to settings file");
			exit(EXIT_FAILURE);
		}
		if (fwrite(settings->value, sizeof(char), VALUESIZE, fileinfo->stream) != VALUESIZE)
		{
			perror("Error writing to settings file");
			exit(EXIT_FAILURE);
		}
		settings = settings->next;
	}
}
