#include "KVPstorage.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
del_kvp will go through the settings lst to find a match with key
If it finds a match it deletes the node, otherwise it does nothing
*/

static void	del_kvp_from_list(t_kvp **settings, char *key)
{
	t_kvp *probe;
	t_kvp *del;

	if (*settings == NULL)
		return ;
	probe = *settings;
	if (strcmp(probe->key, key) == 0)
	{
		*settings = probe->next;
		free(probe);
		return ;
	}
	while (probe->next != NULL)
	{
		if (strcmp(probe->next->key, key) == 0)
		{
			del = probe->next;
			probe->next = probe->next->next;
			free(del);
			return ;
		}
		probe = probe->next;
	}
}

/*
cmd_delete first tries to find a key and will return if no keys are found
It will then try to delete the setting matching the key
Any input after the key is ignored
It always returns OK even if the setting is not found
*/

void		cmd_delete(t_kvp **settings, t_fileinfo *fileinfo, char *line)
{
	char	key[KEYSIZE + 1];
	size_t	key_index;

	key_index = 0;
	bzero(key, KEYSIZE + 1);
	while (isblank(line[key_index]) != 0)
		key_index++;
	if (line[key_index] == '\0')
	{
		fprintf(stderr, INVALID USAGE);
		return ;
	}
	if (get_key_from_line(&line[key_index], key) == -1)
		return ;
	del_kvp_from_list(settings, key);
	update_file(fileinfo, *settings);
	printf("OK\n");
}
