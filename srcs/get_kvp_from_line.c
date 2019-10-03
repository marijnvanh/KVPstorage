#include "KVPstorage.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Get_key receives a line starting with the key string
It copies the key string into key
A key cannot contain any blank spaces
If the key string is longer than KEYSIZE it prints an error 
*/

ssize_t	get_key_from_line(char *line, char key[KEYSIZE + 1])
{
	ssize_t i;
	size_t	j;

	i = 0;
	j = 0;
	while (isblank(line[i]) == 0 && line[i] != '\0' && j < KEYSIZE)
	{
		key[j] = line[i];
		j++;
		i++;
	}
	if (isblank(line[i]) == 0 && line[i] != '\0' && j == KEYSIZE)
	{
		fprintf(stderr, INVALID "Key length too long. Max key size is %d.\n", KEYSIZE);
		return (-1);
	}
	return (i);
}

/*
Get_value receives a line starting with the value string
It copies the value string into value
A value can contain blank space
If the value string is longer than VALUESIZE it prints an error 
*/

ssize_t	get_value_from_line(char *line, char value[VALUESIZE + 1])
{
	ssize_t i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] != '\0' && j < VALUESIZE)
	{
		value[j] = line[i];
		j++;
		i++;
	}
	if (line[i] != '\0' && j == VALUESIZE)
	{
		fprintf(stderr, INVALID "Value length too long. Max value size is %d.\n", VALUESIZE);
		return (-1);
	}
	return (i);
}
