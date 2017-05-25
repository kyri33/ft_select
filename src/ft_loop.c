/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 10:41:19 by kioulian          #+#    #+#             */
/*   Updated: 2017/05/25 11:10:19 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	del(t_env *e)
{
	ft_delete(e);
	e->size--;
	write_list(e);
}

void	ft_loop(t_env *e)
{
	char b[6];

	(void)e;
	while (1)
	{
		ft_bzero(b, 6);
		read(0, b, 6);
		if (b[0] == 27 && b[1] == 91 && b[2] == 65 && b[3] == '\0')
			ft_go_up(e);
		else if (b[0] == 27 && b[1] == 91 && b[2] == 66 && b[3] == '\0')
			ft_go_down(e);
		else if (b[0] == 10 && b[1] == '\0')
			ft_enter(e);
		else if (b[0] == 32 && b[1] == '\0')
			ft_space(e);
		else if (b[0] == 127 && b[1] == '\0')
			del(e);
		else if (b[0] == 27 && b[1] == '\0')
			ft_exit(e);
		else if (b[0] == 27 && b[1] == 91 && b[2] == 51 && b[3] == 126)
			del(e);
	}
}
