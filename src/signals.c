/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:29:58 by kioulian          #+#    #+#             */
/*   Updated: 2017/05/20 16:55:25 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	ft_resize(int i)
{
	t_stat	*stat;

	stat = get_instance();
	write_list(stat->env);
	(void) i;
}

void	ft_stop(int i)
{
	char	c[2];
	t_stat	*stat;

	stat = get_instance();
	tputs(tgetstr("cl", NULL), 1, ft_ft_putchar);
	c[0] = stat->env->nattr.c_cc[VSUSP];
	c[1] = 0;
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, c);
	(void)i;
}

void	ft_cont(int i)
{
	t_stat	*stat;

	stat = get_instance();
	tcsetattr(0, 0, &stat->env->nattr);
	signal(SIGTSTP, ft_stop);
	write_list(stat->env);
	(void)i;
}
