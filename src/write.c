/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 11:37:42 by kioulian          #+#    #+#             */
/*   Updated: 2017/05/20 17:12:44 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <stdio.h>

void	write_start(t_env *e)
{
	tputs(tgetstr("cl", NULL), 1, ft_ft_putchar);
	write(e->fd, "Make a choice !\n\n", 17);
	e->x = 4;
	e->y = 3;
	e->max_len = 0;
}

void	process_node(t_env *e, t_node *node)
{
	if ((int)ft_strlen(node->data) > e->max_len)
		e->max_len = ft_strlen(node->data);
	if (tgetnum("co") < (int)ft_strlen(node->data))
		node->h = ft_strlen(node->data) / tgetnum("co");
	else
		node->h = 1;
	if (e->y + node->h > tgetnum("li"))
	{
		e->x += e->max_len + 4;
		e->y = 3;
		e->max_len = 0;
	}
	node->x = e->x;
	node->y = e->y;
	e->y += node->h;
}

void		ft_underline(t_env *e)
{
	tputs(tgoto(tgetstr("cm", NULL), e->curr->x, e->curr->y), 1, ft_ft_putchar);
	//tputs(tgetstr("ec", NULL), 1, ft_ft_putchar);
	if (e->curr->sel == 1)
		tputs(tgetstr("mr", NULL), 1, ft_ft_putchar);
	tputs(tgetstr("us", NULL), 1, ft_ft_putchar);
	write(e->fd, e->curr->data, ft_strlen(e->curr->data));
	tputs(tgetstr("ue", NULL), 1, ft_ft_putchar);
	if (e->curr->sel == 1)
		tputs(tgetstr("me", NULL), 1, ft_ft_putchar);
}

int		write_list(t_env *e)
{
	int		i;
	t_node	*node;

	i = 0;
	tgetent(NULL, getenv("TERM"));
	node = e->head;
	write_start(e);
	while (i < e->size)
	{
		process_node(e, node);
		tputs(tgoto(tgetstr("cm", NULL), node->x, node->y), 1, ft_ft_putchar);
		if (node->sel == 1)
			tputs(tgetstr("mr", NULL), 1, ft_ft_putchar);
		write(e->fd, node->data, ft_strlen(node->data));
		if (node->sel == 1)
			tputs(tgetstr("me", NULL), 1, ft_ft_putchar);
		i++;
		node = node->next;
	}
	ft_underline(e);
	if (e->x + e->max_len > tgetnum("co") || tgetnum("li") < 4)
		error_small(e);
	return (1);
}
