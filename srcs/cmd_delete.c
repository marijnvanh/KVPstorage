/*
	could implement deleting multipe entries
*/

#include "KVPstorage.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

void		cmd_delete(t_kvp **settings, FILE **file_info, char *line)
{
	char	key[KEYSIZE + 1];
	ssize_t	key_index = 7;

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
	update_file(file_info, *settings);
}
