##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## A Makefile.
##

CC      = gcc
CFLAGS  = -g3
SRC     = ./*.c ./functions/*.c
NAME    = mysh

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

re: clean all

style:
	coding-style.sh . .
	clear
	cat coding-style-reports.log
	rm -rf coding-style-reports.log
fclean: clean

.PHONY: all clean re style
