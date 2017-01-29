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
	e->curr->sel = !e->curr->sel;
	ft_go_down(e);
}
