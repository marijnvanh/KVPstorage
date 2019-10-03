/*
	it ignores more values, could implement gettting multipe keys / values
*/

#include "KVPstorage.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void	cmd_get(t_kvp *settings, char *line)
{
	char	key[KEYSIZE + 1];
	ssize_t	key_index = 4;
	t_kvp	*setting;

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