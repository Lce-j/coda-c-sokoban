# Makefile

NAME = sokoban

SRCS = main.c \
	map.c \
	moves.c \
	position.c \
	game.c

all :  $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean: 
	rm -f $(NAME)

re: fclean all