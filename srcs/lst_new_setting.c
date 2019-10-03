/*
*/

#include "KVPstorage.h"
#include <stdlib.h>
#include <string.h>

t_kvp	*lst_new_setting(char key[KEYSIZE + 1], char value[VALUESIZE + 1])
{
	t_kvp	*new_setting;

	new_setting = (t_kvp*)malloc(sizeof(t_kvp));
	if (new_setting == NULL)
	{
		perror("Could not allocate enough memmory\n");
		exit(EXIT_FAILURE); // maybe don't exit here
	}
	memcpy(new_setting->key, key, KEYSIZE + 1);
	memcpy(new_setting->value, value, VALUESIZE + 1);
	new_setting->next = NULL;
	return (new_setting);
}
