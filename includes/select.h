#ifndef SELECT_H
# define SELECT_H

# include "../libft/includes/libft.h"
# include <termios.h>
# include <term.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_node
{
	struct	s_node	*next;
	struct	s_node	*prev;
	int				sel;
	char			*data;
}				t_node;

typedef struct	s_env
{
	t_node			*head;
	t_node			*tail;
	struct termios	oattr;
	struct termios	nattr;
	int				fd;
}				t_env;

int	init_args(char **argv, t_env *e, int argc);
int	init_termios(t_env *e);
int	ft_ft_putchar(int c);
int	make_error(char *error);

#endif
