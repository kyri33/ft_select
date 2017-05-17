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

void	ft_space(t_env *e)
{
	e->curr->sel = !e->curr->sel;
	ft_go_down(e);
}

void	ft_delete(t_env *e)
{
	t_node	*temp;

	temp = e->curr;
	if (e->curr == e->head)
	{
		e->curr = e->curr->next;
		e->curr->prev = NULL;
		e->head = e->curr;
	}
	else if (e->curr == e->tail)
	{
		e->curr = e->curr->prev;
		e->curr->next = NULL;
		e->tail = e->curr;
	}
	else
	{
		e->curr->prev->next = e->curr->next;
		e->curr->next->prev = e->curr->prev;
		e->curr = e->curr->next;
	}
	free(temp);
	e->size--;
	write_list(e);
}
