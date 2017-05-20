/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:59:16 by kioulian          #+#    #+#             */
/*   Updated: 2017/05/20 17:13:02 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int	error_small(t_env *e)
{
	tputs(tgetstr("cl", NULL), 1, ft_ft_putchar);
	write(e->fd, "Terminal too small", 18);
	return (-1);
}

int	make_error(t_env *e, char *error)
{
	write(e->fd, error, ft_strlen(error));
	return (-1);
}
