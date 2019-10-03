/*

- filepath gets set, either with a path given as argument or the default file .settings
- in init_settings_list all existing settings are added to the settings list
- if the file does not exist a new file is created
- read loop is started

fsync
busybox

*/

#include "KVPstorage.h"
#include <stdlib.h>
#include <string.h>

static char	*init_filepath(char *argv_1)
{
	char *filepath;

	if (argv_1 != NULL)
		filepath = argv_1;
	else
		filepath = DFLT_FILE;
	return (filepath);
}

int			main(int argc, char **argv)
{
	t_kvp	*settings;
	char	*filepath;
	FILE	*file_info;

	(void)argc;
	settings = NULL;
	filepath = init_filepath(argv[1]);
	file_info = open_settings_file(filepath);
	settings = init_settings_list(file_info);
	input_loop(&settings, file_info);
	return (EXIT_SUCCESS);
}
