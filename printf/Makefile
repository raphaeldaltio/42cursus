NAME = libftprintf.a

FILES = ./files/

C_SRC = $(addprefix $(FILES), \
	ft_printf.c \
)

INCLUDES = -I ./includes

OBJ = $(C_SRC:%.c=%.o)

COMP = clang

COMP_FLAGS = -Wall -Werror -Wextra $(INCLUDES)

RM = rm -rf

.PHONY: all clean fclean re push corrupt clang

all: $(NAME)

$(NAME):	$(OBJ)
	make all -C ./libft
	cp ./libft/libft.a libftprintf.a
	ar -rcs $(NAME) $(OBJ)

clean:
	$(RM) *.o
	$(RM) ./a.out
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all

push:
	make clean
	git add .
	git commit -m "Update"
	git push

corrupt:
	find .git/objects/ -type f -empty | xargs rm
	git fetch -p
	git fsck --full

clang:re
	$(COMP) $(COMP_FLAGS) $(OBJ) ./files/main.c libftprintf.a
	./a.out
