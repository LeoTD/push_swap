#include "common.h"

/*
**	No NULL checks on s_stack pointers is deliberate.
**	If these programs ever passed a NULL pointer to these functions
**	something else went wrong.
*/
struct s_stack			*initStack(void)
{
	struct s_stack		*tmp;

	if (NULL == (tmp = malloc(sizeof(*tmp))))
		return (NULL);
	tmp->n = 0;
	tmp->top = NULL;
	tmp->bot = NULL;
	return (tmp);
}

void					pushStack(struct s_stack *s, struct s_node *n)
{
	if (s->top != NULL)
	{
		n->next = s->top;
		n->prev = s->bot;
		s->top->prev = n;
		s->bot->next = n;
		s->top = n;
	}
	else
	{
		s->top = n;
		s->bot = n;
		n->next = n;
		n->prev = n;
	}
	s->n += 1;
}

/*
**	This does not free the nodes!
*/
struct s_node			*popStack(struct s_stack *s)
{
	struct s_node		*tmp;

	if (s->top == NULL)
		return (NULL);
	tmp = s->top;
	if (s->top == s->bot)
	{
		s->top = NULL;
		s->bot = NULL;
	}
	else
	{
		s->top = s->top->next;
		s->top->prev = s->bot;
		s->bot->next = s->top;
	}
	s->n -= 1;
	return (tmp);
}

struct s_node			*newNode(int val)
{
	struct s_node		*tmp;

	if (NULL == (tmp = malloc(sizeof(*tmp))))
		return NULL;
	tmp->val = val;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

int						isEmptyStack(struct s_stack *s)
{
	return (s->top == NULL ? 1 : 0);
}
