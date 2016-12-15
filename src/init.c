/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:14:09 by kioulian          #+#    #+#             */
/*   Updated: 2016/12/15 16:31:47 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	init_termios(t_env *e)
{
	tgetent(NULL, getenv("TERM"));
	tcgetattr(0, &e->oattr);
	tcgetattr(0, &e->nattr);
	e->nattr.c_lflag &= ~(ICANON | ECHO);
	e->nattr.c_cc[VMIN] = 1;
	e->nattr.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &e->nattr);
	while(1)
		;	
}

void	init_args(char **argv, t_env *e, int argc)
{
	int	y;
	int	y_i;

	e->list = (char **)malloc(argc * sizeof(char*));
	y = 1;
	y_i = 0;
	while(argv[y])
	{
		e->list[y_i] = ft_strdup(argv[y]);
		y++;
		y_i++;
	}
	e->list[y_i] = 0;
}
