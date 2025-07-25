NAME = server
NAME_CLIENT = client
SRC = server.c
SRC_CLIENT = client.c
SRC_SHARED = the_rest.c
LIBFT = libft/libft.a
OBJ = $(SRC:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SHARED = $(SRC_SHARED:.c=.o)
FLAGS = -Wall -Wextra -Werror
HEADER = minitalk.h

all: $(NAME) $(NAME_CLIENT)

$(NAME): $(OBJ) $(OBJ_SHARED) $(LIBFT) 
	cc $(FLAGS) $^ -o $@

$(NAME_CLIENT): $(OBJ_CLIENT) $(OBJ_SHARED) $(LIBFT) 
	cc $(FLAGS) $^ -o $@

$(LIBFT):
	make -C libft
	make -C libft clean

%.o: %.c $(HEADER)
	cc $(FLAGS) -c $<

clean:
	rm -f $(OBJ) $(OBJ_CLIENT) $(OBJ_SHARED)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(NAME_CLIENT)
	make -C libft fclean

re:
	fclean all

.PHONY: all re fclean clean
.SECONDARY: $(OBJ) $(OBJ_CLIENT) $(OBJ_SHARED)
