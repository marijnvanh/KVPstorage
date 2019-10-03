#ifndef KVP_STORAGE
# define KVP_STORAGE

# define INVALID	"Invalid input.\n"
# define USAGE		"Usage: KVPstorage: \nSET\t<KEY> [VALUE]\nGET\t<KEY>\nDELETE\t<KEY>\nexit\n"
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
void	exec_command(t_kvp **settings, FILE **file_info, char *line);
void	input_loop(t_kvp **settings, FILE **file_info);
FILE	*open_settings_file(char *filepath);
t_kvp	*init_settings_list(FILE *file_info);
void	add_kvp_to_list(t_kvp **settings, char kvp[KEYSIZE + VALUESIZE]);
t_kvp	*lst_new_setting(char key[KEYSIZE + 1], char value[VALUESIZE + 1]);
void	lst_add_setting(t_kvp **settings, t_kvp *new);
void	add_kvp_to_list(t_kvp **settings, char *kvp);
ssize_t	get_value_from_line(char *line, char value[VALUESIZE + 1]);
ssize_t	get_key_from_line(char *line, char key[KEYSIZE + 1]);
t_kvp	*get_kvp_from_list(t_kvp *settings, char *key);
void	update_file(FILE **file_info, t_kvp *settings);
void	cmd_getall(t_kvp *settings);

void	cmd_set(t_kvp **settings, FILE **file_info, char *line);
void	cmd_get(t_kvp *settings, char *line);
void	cmd_delete(t_kvp **settings, FILE **file_info, char *line);

#endif
