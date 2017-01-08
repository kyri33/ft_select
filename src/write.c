/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 11:37:42 by kioulian          #+#    #+#             */
/*   Updated: 2017/01/08 16:06:58 by kioulian         ###   ########.fr       */
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

int		write_list(t_env *e)
{
	int		i;
	t_node	*node;

	i = 0;
	node = e->head;
	write_start(e);
	while (i < e->size)
	{
		process_node(e, node);
		tputs(tgoto(tgetstr("cm", NULL), node->x, node->y), 1, ft_ft_putchar);
		write(e->fd, node->data, ft_strlen(node->data));
		i++;
		node = node->next;
	}
	return (1);
}
