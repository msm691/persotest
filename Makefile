##
## EPITECH PROJECT, 2025
## my_printf
## File description:
## Makefile for libmy.a
##

NAME    = libmy.a
SRC     = lib/my/my_printf.c \
          lib/my/call.c \
          lib/my/my_putchar.c \
          lib/my/my_putstr.c \
          lib/my/my_put_nbr.c
OBJ     = $(SRC:.c=.o)
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -std=c99 -I include
AR      = ar
ARFLAGS = rc

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
