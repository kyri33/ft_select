/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:53:10 by kioulian          #+#    #+#             */
/*   Updated: 2017/05/21 11:32:27 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	ft_freelist(t_env *e)
{
	t_node	*temp;

	temp = e->head;
	while (temp != e->tail)
	{
		e->head = temp;
		temp = e->head->next;
		free(e->head);
		e->head = NULL;
	}
	free(e->tail);
	e->tail = NULL;
}

void	ft_restore(t_env *e)
{
	tputs(tgetstr("cl", NULL), 1, ft_ft_putchar);
	close(e->fd);
	if (tcsetattr(0, 0, &e->oattr))
		exit(make_error(e, "Failed to restore terminal\n"));
}

void	ft_exit(t_env *e)
{
	ft_freelist(e);
	free(get_instance());
	ft_restore(e);
	exit(1);
}
