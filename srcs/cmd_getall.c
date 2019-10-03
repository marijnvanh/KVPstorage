/*
	it ignores more values, could implement gettting multipe keys / values
*/

#include "KVPstorage.h"
#include <stdio.h>

void	cmd_getall(t_kvp *settings)
{
	while (settings != NULL)
	{
		printf("Key: %*s\tValue: %*s\n", KEYSIZE, settings->key, VALUESIZE, settings->value);
		settings = settings->next;
	}
}
