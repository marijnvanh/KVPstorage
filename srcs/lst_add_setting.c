#include "KVPstorage.h"
#include <stdlib.h>
#include <string.h>

/*
Adds new kvp to the beginning of the settings list
*/

void	lst_add_setting(t_kvp **settings, t_kvp *new)
{
	if (*settings == NULL)
		*settings = new;
	else
	{
		new->next = *settings;
		*settings = new;
	}
}
