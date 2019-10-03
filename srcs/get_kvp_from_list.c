/*
*/

#include "KVPstorage.h"
#include <string.h>

t_kvp	*get_kvp_from_list(t_kvp *settings, char *key)
{
	while (settings != NULL)
	{
		if (strcmp(settings->key, key) == 0)
			return (settings);
		settings = settings->next;
	}
	return (NULL);
}
