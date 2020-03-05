##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## Makefile
##

SRC =	src/init_game.c			\
		src/my_put_nbr.c		\
		src/my_putchar.c		\
		src/my_putstr.c			\
		src/main.c				\
		src/open_file.c			\
		src/my_strcmp.c			\
		src/my_strlen.c			\
		src/init_map.c			\
		src/fill.c				\
		src/my_getnbr.c			\
		src/first_loop.c		\
		src/sec_loop.c			\
		src/my_revstr.c			\
		src/malloc_str.c		\
		src/check_hit.c			\
		src/sig_handler.c		\

OBJ = $(SRC:.c=.o)

LDFLAGS += -Wall -Wextra

NAME = navy

all: $(NAME)

$(NAME): $(OBJ)
		gcc -g -o $(NAME) $(SRC) $(LDFLAGS)

clean:
		rm -f $(OBJ)
		rm -f vgcore*

fclean: clean
		rm -f $(NAME)

re:		fclean all

debug:
		gcc -g $(SRC) $(LDFLAGS)
