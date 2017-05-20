NAME = ft_select

SRC = src/main.c src/init.c src/ft_ft_putchar.c src/error.c \
	src/write.c src/ft_loop.c src/move.c src/signals.c src/ft_exit.c

FLAGS = clang -Werror -Wextra -Wall -g3 -I includes -o

all: $(NAME)

$(NAME): $(SRC)
	make -C libft/ fclean && make -C libft/ all
	$(FLAGS) $(NAME) libft/libft.a $(SRC) -ltermcap

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
