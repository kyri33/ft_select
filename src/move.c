/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:32:29 by kioulian          #+#    #+#             */
/*   Updated: 2017/05/25 11:08:53 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	ft_go_up(t_env *e)
{
	if (e->curr == e->head)
		e->curr = e->tail;
	else
		e->curr = e->curr->prev;
	write_list(e);
}

void	ft_go_down(t_env *e)
{
	if (e->curr == e->tail)
		e->curr = e->head;
	else
		e->curr = e->curr->next;
	write_list(e);
}

void	ft_enter(t_env *e)
{
	int		i;
	int		j;
	t_node	*temp;

	ft_restore(e);
	i = 0;
	j = 0;
	temp = e->head;
	while (i++ != e->size)
	{
		if (temp->sel == 1)
		{
			if (j > 0)
				ft_putstr(" ");
			ft_putstr(temp->data);
			j++;
		}
		temp = temp->next;
	}
	if (j != 0)
		ft_putstr("\n");
	ft_freelist(e);
	free(get_instance());
	exit(1);
}

void	ft_space(t_env *e)
{
	e->curr->sel = !e->curr->sel;
	ft_go_down(e);
}

void	ft_delete(t_env *e)
{
	t_node	*temp;

	if (e->size == 1)
		ft_exit(e);
	temp = e->curr;
	if (e->curr == e->head)
	{
		e->curr = e->curr->next;
		e->curr->prev = NULL;
		e->head = e->curr;
	}
	else if (e->curr == e->tail)
	{
		e->curr = e->curr->prev;
		e->curr->next = NULL;
		e->tail = e->curr;
	}
	else
	{
		e->curr->prev->next = e->curr->next;
		e->curr->next->prev = e->curr->prev;
		e->curr = e->curr->next;
	}
	free(temp);
}
