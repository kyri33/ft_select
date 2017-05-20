#ifndef SELECT_H
# define SELECT_H

# include "../libft/includes/libft.h"
# include <termios.h>
# include <term.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/ioctl.h>

typedef struct	s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				sel;
	char			*data;
	int				y;
	int				h;
	int				x;
}				t_node;

typedef struct	s_env
{
	t_node			*head;
	t_node			*tail;
	t_node			*curr;
	struct termios	oattr;
	struct termios	nattr;
	int				size;
	int				fd;
	int				x;
	int				max_len;
	int				y;
}				t_env;

typedef struct	s_stat
{
	struct s_env	*env;
}				t_stat;

int	init_args(char **argv, t_env *e, int argc);
int	init_termios(t_env *e);
int	ft_ft_putchar(int c);
int	make_error(t_env *e, char *error);
int	error_small(t_env *e);
int	init_select(t_env *e);
int	write_list(t_env *e);
void	ft_loop(t_env *e);
void	ft_go_up(t_env *e);
void	ft_go_down(t_env *e);
void	ft_enter(t_env *e);
void	ft_resize(int i);
void	*get_instance();
void	ft_delete(t_env *e);
void	ft_space(t_env *e);
void	ft_exit(t_env *e);
void	ft_stop(int i);
void	ft_cont(int i);
void	ft_freelist(t_env *e);

#endif
