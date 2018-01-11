##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CC	= gcc -c

NAME	= libmy.a

AR	= ar -cvr

SRC	= my_getnbr.c	\
	my_putchar.c	\

OBJ	= $(SRC:.c=.o)

INCLUDE	= include/my.h

RM	= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(SRC)

clean:
	$(RM) $(OBJ) *~

fclean: clean
	$(RM) $(NAME)

re: fclean all
