/*
*/

#include "KVPstorage.h"
#include <stdlib.h>
#include <string.h>

void	lst_add_setting(t_kvp **settings, t_kvp *new)
{
	t_kvp	*probe;

	probe = *settings;
	if (*settings == NULL)
		*settings = new;
	else
	{
		while (probe->next != NULL)
			probe = probe->next;
		probe->next = new;
	}
}
