/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:59:16 by kioulian          #+#    #+#             */
/*   Updated: 2017/01/08 14:01:23 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int	error_small(t_env *e)
{
	tputs(tgetstr("cl", NULL), 1, ft_ft_putchar);
	write(e->fd, "Terminal too small", 18);
	return (-1);
}

int	make_error(char *error)
{
	ft_putstr(error);
	return (-1);
}
