/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:53:10 by kioulian          #+#    #+#             */
/*   Updated: 2017/05/20 17:16:58 by kioulian         ###   ########.fr       */
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

void	ft_exit(t_env *e)
{
	ft_freelist(e);
	tputs(tgetstr("cl", NULL), 1, ft_ft_putchar);
	close(e->fd);
	free(get_instance());
	if (tcsetattr(0, 0, &e->oattr) == -1)
		exit(make_error(e, "Failed to restore terminal\n"));
	exit(1);
}
