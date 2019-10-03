/*

*/

#include "KVPstorage.h"
// #include <stdio.h>
// #include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

ssize_t	get_key_from_line(char *line, char *key)
{
	ssize_t i;
	size_t	j;

	i = 0;
	while (isblank(line[i]) != 0)
		i++;
	if (line[i] == '\0')
		return (-1); // error
	j = 0;
	while (isblank(line[i]) == 0 && line[i] != '\0' && j < KEYSIZE)
	{
		key[j] = line[i];
		j++;
		i++;
	}
	if (j == KEYSIZE)
		return (-1); // error
	return (i);
}

ssize_t	get_value_from_line(char *line, char *value)
{
	ssize_t i;
	size_t	j;

	i = 0;
	while (isblank(line[i]) != 0)
		i++;
	if (line[i] == '\0')
		return (-1); // error
	j = 0;
	while (line[i] != '\0' && j < VALUESIZE)
	{
		value[j] = line[i];
		j++;
		i++;
	}
	if (j == VALUESIZE)
		return (-1); // error
	return (i);
}

void	cmd_set(t_kvp **settings, FILE *file_info, char *line)
{
	char	key[KEYSIZE + 1];
	char	value[VALUESIZE + 1];
	ssize_t	value_index;

	bzero(key, KEYSIZE + 1);
	bzero(value, VALUESIZE + 1);
	value_index = get_key_from_line(&line[4], key);
	if (value_index == -1)
		return ;
	if (get_value_from_line(&line[value_index + 4], value) == -1)
		return ;
	printf("key: %s value: %s\n", key, value);
	lst_add_setting(settings, lst_new_setting(key, value));
	(void)file_info; // add to file function;
}
