#include "KVPstorage.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
Update settings first checks if there is a matching setting in settings list
If there is a match the value is updated 
Otherwise, a new settings node is added to the settings list
Update_file updates the file on disk
*/

static void	update_settings(t_kvp **settings, t_fileinfo *fileinfo,
			char key[KEYSIZE + 1], char value[VALUESIZE + 1])
{
	t_kvp *key_match;

	key_match = get_kvp_from_list(*settings, key);
	if (key_match != NULL)
		memcpy(key_match->value, value, VALUESIZE + 1);
	else
		lst_add_setting(settings, lst_new_setting(key, value));
	update_file(fileinfo, *settings);
	printf("OK\n");
}

/*
Cmd_set first finds the key and value in line
It ignores blank spaces in between cmd and key and in between key and value
If no key is found it will return an error and print USAGE
If no value is found it will still set a kvp with an empty value
*/

void		cmd_set(t_kvp **settings, t_fileinfo *fileinfo, char *line)
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
	value_index += key_index;
	while (isblank(line[value_index]) != 0)
		value_index++;
	if (line[value_index] != '\0' && get_value_from_line(&line[value_index], value) == -1)
		return ;
	update_settings(settings, fileinfo, key, value);
}
