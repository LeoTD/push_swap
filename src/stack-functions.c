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
	tmp->top = NULL;
	tmp->bot = NULL;
	return (tmp);
}

void					pushStack(struct s_stack *s, int val)
{
	struct s_node		*tmp;

	if (NULL == (tmp = malloc(sizeof(*tmp))))
		return ;
	tmp->val = val;
	if (s->top != NULL)
		tmp->next = s->top;
	else
		tmp->next = NULL;
	s->top = tmp;
	if (s->bot == NULL)
		s->bot = tmp;
}

/*
**	This does not free the nodes!
*/
struct s_node			*popStack(struct s_stack *s)
{
	struct s_node		*tmp;

	if (s->top == NULL)
		return (NULL);
	if (s->top->next == NULL)
		s->bot = NULL;
	tmp = s->top;
	s->top = tmp->next;
	return (tmp);
}

struct s_node			*peekStack(struct s_stack *s)
{
	return (s->top == NULL ? NULL : s->top);
}

int						isEmptyStack(struct s_stack *s)
{
	return (s->top == NULL ? 1 : 0);
}
