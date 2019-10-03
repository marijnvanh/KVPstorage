#include "KVPstorage.h"
#include <stdlib.h>
#include <string.h>

/*
Filepath gets set, either with a path given as argument or the default file
*/

static char	*init_filepath(char *argv_1)
{
	char *filepath;

	if (argv_1 != NULL)
		filepath = argv_1;
	else
		filepath = DFLT_FILE;
	return (filepath);
}

/*
A file stream is opened with filepath
Any existing settings are saved to the settings list
Read loop is started
*/

int			main(int argc, char **argv)
{
	t_kvp		*settings;
	t_fileinfo	fileinfo;

	(void)argc;
	settings = NULL;
	fileinfo.filepath = init_filepath(argv[1]);
	fileinfo.stream = open_settings_file(fileinfo.filepath);
	settings = init_settings_list(fileinfo.stream);
	input_loop(&settings, &fileinfo);
	return (EXIT_SUCCESS);
}
