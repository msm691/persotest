##
## EPITECH PROJECT, 2025
## my_printf
## File description:
## MakeFile
##

NAME    = libmy.a
BIN     = printf

SRC     = lib/my/my_printf.c \
          lib/my/core.c \
          lib/my/parse.c \
          lib/my/dispatch.c \
          lib/my/io.c \
          lib/my/out_basic.c \
          lib/my/ints_common.c \
          lib/my/out_ptr.c

OBJ     = $(SRC:.c=.o)
CC      = epiclang
CFLAGS  = -Wall -Wextra -Werror -std=c99 -I include
AR      = ar
ARFLAGS = rc

all: $(NAME) $(BIN)
	@rm -f $(OBJ)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

$(BIN): $(NAME) main.c
	$(CC) $(CFLAGS) main.c $(NAME) -o $(BIN)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(BIN)

re: fclean all
