/*
*/

#include "KVPstorage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	add_kvp_to_list(t_kvp **settings, char *kvp)
{
	char	key[KEYSIZE + 1];
	char	value[VALUESIZE + 1];

	memcpy(key, kvp, KEYSIZE);
	key[KEYSIZE] = 0;
	memcpy(value, &kvp[KEYSIZE], VALUESIZE);
	value[VALUESIZE] = 0;
	lst_add_setting(settings, lst_new_setting(key, value));
}
