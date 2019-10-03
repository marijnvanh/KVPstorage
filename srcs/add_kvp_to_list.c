#include "KVPstorage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
add_kvp gets a block from a file of the size of KEYSIZE + VALUESIZE
It copies the key into a key string and the value into a value str
A new setting node is created by lst_new_setting
It is then added to the settings list
*/

void	add_kvp_to_list(t_kvp **settings, char kvp[KEYSIZE + VALUESIZE])
{
	char	key[KEYSIZE + 1];
	char	value[VALUESIZE + 1];

	memcpy(key, kvp, KEYSIZE);
	key[KEYSIZE] = 0;
	memcpy(value, &kvp[KEYSIZE], VALUESIZE);
	value[VALUESIZE] = 0;
	lst_add_setting(settings, lst_new_setting(key, value));
}
