NAME = KVPstorage
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = main input_loop exec_command
VPATH = ./srcs

OBJECTS := $(SRCS:%=%.o)
SRCS := $(SRCS:%=%.c)

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
