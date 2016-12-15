NAME = ft_select

SRC = src/main.c libft/libft.a src/init.c

FLAGS = clang -Werror -Wextra -Wall -g3 -I includes -o

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/ all
	$(FLAGS) $(NAME) $(SRC) -ltermcap

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all