C_SRC = get_next_line.c get_next_line_utils.c main.c

COMP = clang

COMP_FLAGS = -Wall -Werror -Wextra -D

BUFFER = BUFFER_SIZE=3

RUN = ./a.out

RM = rm -rf

make:
	$(COMP) $(COMP_FLAGS) $(BUFFER) $(C_SRC)
	$(RUN)

clean:
	$(RM) ./a.out

push:
	make clean
	git add .
	git commit -m "Update"
	git push

corrupt:
	find .git/objects/ -type f -empty | xargs rm
	git fetch -p
	git fsck --full
