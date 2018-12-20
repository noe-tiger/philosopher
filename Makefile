##
## EPITECH PROJECT, 2018
## *
## File description:
## *
##

CFLAGS  	=       -W -Wall -Wextra

CPPFLAGS	+=	-I ./include/

SRC     	=	src/main.c	\
			src/read.c	\
			src/philosopher.c

NAME    	=       philo

OBJ     	=       $(SRC:.c=.o)

CC      	=       gcc

RM      	=       rm -f

all:    $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

$(NAME):    $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lriceferee -lpthread -L.

re:     fclean all clean

.PHONY: all re clean fclean
