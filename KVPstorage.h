#ifndef KVP_STORAGE
# define KVP_STORAGE

# define USAGE	"SET\t<KEY> [VALUE]\nGET\t<KEY>\nDELETE\t<KEY>\nEXIT\n"

void	read_loop(void);
void	exec_command(char *line);
void	input_loop(void);


#endif
