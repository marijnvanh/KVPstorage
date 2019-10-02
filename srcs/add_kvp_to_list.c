/*
*/

#include "KVPstorage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	add_kvp_to_list(t_kvp **settings, char *kvp)
{
	char	*key;
	char	*value;

	(void)settings;
	key = strndup(kvp, KEYSIZE); // moet dit strdup of kan dit met memcpy
	value = strndup(&kvp[KEYSIZE], VALUESIZE);
	if (key == NULL || value == NULL)
	{
		perror("Could not allocate enough memmory\n");
		exit(EXIT_FAILURE);
	}
	printf("key: %s value: %s\n", key, value);
	lst_add_setting(settings, lst_new_setting(key, value));
}
