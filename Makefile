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