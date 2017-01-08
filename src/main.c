/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:52:04 by kioulian          #+#    #+#             */
/*   Updated: 2017/01/08 15:04:11 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	*get_instance()
{
	static t_stat	*inst = NULL;

	if (inst == NULL)
		inst = (t_stat *)malloc(sizeof(*inst));
	return (inst);
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc == 1)
		exit(0);
	if (init_args(argv, &e, argc) == -1)
		return make_error("Error initializing arguments\n");
	if (init_termios(&e) == -1)
		return make_error("Error initializing terminal\n");
	((t_stat *)get_instance())->env = &e;
	if (init_select(&e) == -1)
		return make_error("Configuration error\n");
}
