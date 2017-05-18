/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:53:10 by kioulian          #+#    #+#             */
/*   Updated: 2017/05/18 17:34:15 by kioulian         ###   ########.fr       */
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
		//free(head->data);
		//head->data = NULL;
		free(e->head);
		e->head = NULL;
	}
	free(e->tail);
	e->tail = NULL;
}

void	ft_exit(t_env *e)
{
	ft_freelist(e);
	exit(1);
}
