/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:52:04 by kioulian          #+#    #+#             */
/*   Updated: 2017/01/07 15:54:18 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int	main(int argc, char **argv)
{
	t_env	e;

	if (argc == 1)
		exit(0);
	if (init_args(argv, &e, argc) == -1)
		return make_error("Error initializing arguments\n");
	if (init_termios(&e) == -1)
		return make_error("Error initializing terminal\n");
	t_node	*temp;

	temp = e.tail;
	while (temp != e.head)
	{
		ft_putstr(temp->data);ft_putstr("\n");
		temp = temp->prev;
	}
}
