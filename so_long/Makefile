NAME = so_long

FILES = ./files/

GNL_FILES = ./get_next_line/

C_SRC = $(addprefix $(FILES), \
	main.c)\
	$(addprefix $(GNL_FILES), \
	get_next_line.c get_next_line_utils.c)\

INCLUDES = -I ./includes/

OBJ = $(C_SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra $(INCLUDES)

MLXFLAGS =  -lmlx -lXext -lX11 -L ./libft -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):	$(OBJ)
	make all -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) ./a.out
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all
