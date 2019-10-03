#ifndef KVPSTORAGE_H
# define KVPSTORAGE_H

# define INVALID	"Invalid input.\n"
# define USAGE		"Usage: KVPstorage: \nSET\t<KEY> [VALUE]\nGET\t<KEY>\nDELETE\t<KEY>\nGETALL\nexit\n"
# define KEYSIZE	4
# define VALUESIZE	6
# define DFLT_FILE	".settings"

# include <stdio.h>

typedef struct	s_kvp
{
	char			key[KEYSIZE + 1];
	char			value[VALUESIZE + 1];
	struct s_kvp	*next;
}				t_kvp;

typedef struct	s_fileinfo
{
	FILE	*stream;
	char	*filepath;
}				t_fileinfo;

void			exec_command(t_kvp **settings, t_fileinfo *fileinfo, char *line);
void			input_loop(t_kvp **settings, t_fileinfo *fileinfo);
FILE			*open_settings_file(char *filepath);
t_kvp			*init_settings_list(FILE *file_info);

void			add_kvp_to_list(t_kvp **settings, char kvp[KEYSIZE + VALUESIZE]);
ssize_t			get_key_from_line(char *line, char key[KEYSIZE + 1]);
ssize_t			get_value_from_line(char *line, char value[VALUESIZE + 1]);

t_kvp			*lst_new_setting(char key[KEYSIZE + 1], char value[VALUESIZE + 1]);
void			lst_add_setting(t_kvp **settings, t_kvp *new);
t_kvp			*get_kvp_from_list(t_kvp *settings, char *key);

void			update_file(t_fileinfo *fileinfo, t_kvp *settings);

void			cmd_set(t_kvp **settings, t_fileinfo *fileinfo, char *line);
void			cmd_get(t_kvp *settings, char *line);
void			cmd_delete(t_kvp **settings, t_fileinfo *fileinfo, char *line);
void			cmd_getall(t_kvp *settings);

#endif
