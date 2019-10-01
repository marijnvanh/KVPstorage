NAME = KVPstorage
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = main read_loop
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
