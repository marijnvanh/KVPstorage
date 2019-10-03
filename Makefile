NAME	= KVPstorage
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
SRCS	= main input_loop exec_command open_settings_file init_settings_list add_kvp_to_list lst_new_setting \
		lst_add_setting cmd_set get_kvp_from_line get_kvp_from_list cmd_get cmd_delete update_file cmd_getall
VPATH	= ./srcs

OBJECTS := $(SRCS:%=%.o)
SRCS	:= $(SRCS:%=%.c)

all: $(OBJECTS) $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) $^ -o $(NAME)
	@echo "[ + ] $(NAME) has been compiled"

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $< -I .

clean:
	@rm -f $(OBJECTS)
	@echo "[ - ] removed object files"

fclean: clean
	@rm -f $(NAME)
	@echo "[ - ] removed $(NAME)"

re: fclean all
