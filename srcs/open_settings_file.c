#include "KVPstorage.h"
#include <stdio.h>
#include <stdlib.h>

/*
The file at filepath is openend 
If it does not exist it is created
The file stream is set to the beginning with rewind
*/

FILE	*open_settings_file(char *filepath)
{
	FILE	*file_info;

	file_info = fopen(filepath, "a+");
	if (file_info == NULL)
	{
		perror("Error opening settings file");
		exit (EXIT_FAILURE);
	}
	rewind(file_info);
	return (file_info);
}
