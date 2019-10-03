/*

*/

#include "KVPstorage.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

static void	update_settings(t_kvp **settings, FILE *file_info,
			char key[KEYSIZE + 1], char value[VALUESIZE + 1])
{
	t_kvp *key_match;

	key_match = get_kvp_from_list(*settings, key);
	if (key_match != NULL)
		memcpy(key_match->value, value, VALUESIZE + 1);
	else
		lst_add_setting(settings, lst_new_setting(key, value));
	(void)file_info; // add to file function;
}

void		cmd_set(t_kvp **settings, FILE *file_info, char *line)
{
	char	key[KEYSIZE + 1];
	char	value[VALUESIZE + 1];
	ssize_t	value_index;
	ssize_t	key_index = 4;

	bzero(key, KEYSIZE + 1);
	bzero(value, VALUESIZE + 1);
	while (isblank(line[key_index]) != 0)
		key_index++;
	if (line[key_index] == '\0')
	{
		fprintf(stderr, INVALID USAGE);
		return ;
	}
	value_index = get_key_from_line(&line[key_index], key);
	if (value_index == -1)
		return ;
	value_index += 4;
	while (isblank(line[value_index]) != 0)
		value_index++;
	if (line[value_index] != '\0' && get_value_from_line(&line[value_index], value) == -1)
		return ;
	update_settings(settings, file_info, key, value);
}
