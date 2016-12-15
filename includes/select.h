#ifndef SELECT_H
# define SELECT_H

# include "../libft/includes/libft.h"
# include <termios.h>
# include <term.h>

typedef struct	s_env
{
	char			**list;
	struct termios	oattr;
	struct termios	nattr;
}				t_env;

typedef struct	s_sel
{
	int	selected;
	
}				t_sel;

void	init_args(char **argv, t_env *e, int argc);
void	init_termios(t_env *e);

#endif
