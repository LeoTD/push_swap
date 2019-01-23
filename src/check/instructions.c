#include "checker.h"

void		inst_swap(struct s_stack *s)
{
	struct s_node		*tmp;

	if (s->top == NULL || s->top->next == NULL)
		return ;
	if (s->bot == s->top->next)
		s->bot = s->top;
	tmp = s->top;
	s->top = s->top->next;
	tmp->next = s->top->next;
	s->top->next = tmp;
}

void		inst_push(struct s_stack *to, struct s_stack *from)
{
	struct s_node		*tmp;

	if (NULL == (tmp = popStack(from)))
		return ;
	if (to->bot == NULL)
		to->bot = tmp;
	tmp->next = to->top;
	to->top = tmp;
}

void		inst_rot(struct s_stack *s)
{
	struct s_node		*tmp;

	if (s->top == NULL || s->top->next == NULL)
		return ;
	tmp = s->top;
	s->top = s->top->next;
	s->bot->next = tmp;
	s->bot = tmp;
}

void		inst_rrot(struct s_stack *s)
{
	struct s_node		*tmp, *prev;

	if (s->top == NULL || s->top->next == NULL)
		return ;

}
