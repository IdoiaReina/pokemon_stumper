##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC		=	gcc

RM		=	rm -f

OBJS		=	$(addprefix $(SRCDIR), $(SRCS:.c=.o))

SRCDIR		=	src/

MAKE		=	make

CFLAGS		=	-W -Wall -Wextra
CFLAGS		+=	-I./include/

NAME		=	pokemon

SRCS		=	main.c 			\
			init.c 			\
			my_str_compare.c 	\
			algo_fight_pokemon.c 	\
			fight_pokemon.c 	\
			my_str_to_tab.c 	\
			print_file.c 		\
			read_dir.c 		\
			players.c 		\

all: $(NAME) clean

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
