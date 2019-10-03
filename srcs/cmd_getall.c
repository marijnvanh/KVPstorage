#include "KVPstorage.h"
#include <stdio.h>

/*
cmd_getall shows all settings currently in settings list
*/

void	cmd_getall(t_kvp *settings)
{
	while (settings != NULL)
	{
		printf("%s\t\t%s\n", settings->key, settings->value);
		settings = settings->next;
	}
}
