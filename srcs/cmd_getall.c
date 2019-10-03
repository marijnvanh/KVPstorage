/*
	it ignores more values, could implement gettting multipe keys / values
*/

#include "KVPstorage.h"
#include <stdio.h>

void	cmd_getall(t_kvp *settings)
{
	while (settings != NULL)
	{
		printf("%s\t\t%s\n", settings->key, settings->value);
		settings = settings->next;
	}
}
