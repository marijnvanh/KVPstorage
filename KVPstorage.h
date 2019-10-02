#ifndef KVP_STORAGE
# define KVP_STORAGE

# define USAGE		"SET\t<KEY> [VALUE]\nGET\t<KEY>\nDELETE\t<KEY>\nEXIT\n"
# define KEYSIZE	4
# define VALUESIZE	6
# define DFLT_FILE	".settings"

# include <stdio.h>

typedef struct	s_kvp
{
	char 			key[KEYSIZE + 1];
	char 			value[VALUESIZE + 1];
	struct s_kvp	*next;
}				t_kvp;

void	read_loop(void);
void	exec_command(char *line);
void	input_loop(t_kvp **settings, char *filepath);
FILE	*open_settings_file(char *filepath);
t_kvp	*init_settings_list(char *filepath);
void	add_kvp_to_list(t_kvp **settings, char *kvp);
t_kvp	*lst_new_setting(char *key, char *value);
void	lst_add_setting(t_kvp **settings, t_kvp *new);
void	add_kvp_to_list(t_kvp **settings, char *kvp);

#endif
