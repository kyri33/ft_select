#include "select.h"

void	ft_loop(t_env *e)
{
	char b[6];
	(void)e;
	while(1)
	{
		ft_bzero(b, 6);
		read(0, b, 6);
		if(b[0] == 27 && b[1] == 91 && b[2] == 65 && b[3] == '\0')
			ft_go_up(e);
		else if (b[0] == 27 && b[1] == 91 && b[2] == 66 && b[3] == '\0')
			ft_go_down(e);
		else if (b[0] == 10 && b[1] == '\0')
			ft_enter(e);
		else if (b[0] == 32 && b[1] == '\0')
			ft_space(e);
		else if (b[0] == 127 && b[1] == '\0')
			ft_delete(e);
		else if (b[0] == 27)
			ft_exit(e);
		else
		{
			int i =0;
			ft_putstr("\n");
			while(b[i])
			{
				ft_putnbr(b[i]);
				ft_putchar(' ');
				i++;
			}
		}
	}
}
