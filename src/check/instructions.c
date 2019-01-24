#include "checker.h"
#include "common.h"

void		inst_swap(struct s_stack *s)
{
	struct s_node		*tmp;

	if (s->top == NULL || s->top->next == NULL)
		return ;
	tmp = popStack(s);
	inst_rot(s);
	pushStack(s, tmp);
	inst_rrot(s);
}

void		inst_push(struct s_stack *to, struct s_stack *from)
{
	struct s_node		*tmp;

	if (NULL == (tmp = popStack(from)))
		return ;
	pushStack(to, tmp);
}

void		inst_rot(struct s_stack *s)
{
	if (s->top == NULL || s->top->next == NULL)
		return ;
	s->top = s->top->next;
	s->bot = s->bot->next;
}

void		inst_rrot(struct s_stack *s)
{
	if (s->top == NULL || s->top->prev == NULL)
		return ;
	s->top = s->top->prev;
	s->bot = s->bot->prev;
}
