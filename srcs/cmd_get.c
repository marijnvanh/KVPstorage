#include "KVPstorage.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
Cmd_get first retrieves the key from line
It then tries the find the key in settings list
It will print the value if it's found, else it will print error
*/

void	cmd_get(t_kvp *settings, char *line)
{
	char	key[KEYSIZE + 1];
	size_t	key_index;
	t_kvp	*setting;

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
	setting = get_kvp_from_list(settings, key);
	if (setting == NULL)
		fprintf(stderr, "%s not found.\n", key);
	else
		printf("%s\n", setting->value);
}
