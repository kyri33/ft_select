/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:14:09 by kioulian          #+#    #+#             */
/*   Updated: 2017/01/08 16:06:56 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int	init_termios(t_env *e)
{
	tgetent(NULL, getenv("TERM"));
	tcgetattr(0, &e->oattr);
	tcgetattr(0, &e->nattr);
	e->nattr.c_lflag &= ~(ICANON | ECHO);
	e->nattr.c_cc[VMIN] = 1;
	e->nattr.c_cc[VTIME] = 0;
	if ((tcsetattr(0, TCSADRAIN, &e->nattr)) == -1)
		return (-1);
	if ((e->fd = open("/dev/tty", O_RDWR)) == -1)
		return (make_error("Error opening fd\n"));
	return (1);
}

int	init_select(t_env *e)
{

	//TODO Signals
	e->curr = e->head;
	write_list(e);
	ft_loop(e);
	return (1);
}

void	add_node(t_env *e, char *val)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->sel = 0;
	new->data = val;
	if (e->head == NULL)
	{
		e->head = new;
		e->tail = new;
	}
	else
	{
		e->tail->next = new;
		new->prev = e->tail;
		e->tail = new;
	}
}

int	init_args(char **argv, t_env *e, int argc)
{
	int	y;

	y = 1;
	e->head = NULL;
	e->tail = NULL;
	while (y < argc)
	{
		add_node(e, argv[y]);
		e->size++;
		y++;
	}
	return (1);
}
