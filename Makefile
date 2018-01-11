##
## EPITECH PROJECT, 2017
## Pushswap
## File description:
## Makefileflags.
##

.PHONY: clean fclean re

NAME	=	bsq

SRC	=	src/main.c	\
	src/algo_bsq.c	\
	src/manage_array.c

OBJ	=	$(SRC:.c=.o)

all:	lib $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy -lc_graph_prog

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my

lib:	Makefile
	make -C lib/my

re:	fclean all
