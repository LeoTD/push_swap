#include "push_swap.h"
#include "common.h"

#define IF_NULL(x,y) {if (NULL == (x)) { return y; }}

struct s_data			*init_data(int len, char **av)
{
	struct s_data	*tmp;
	int				i;
	long			err;

	IF_NULL((tmp = malloc(sizeof(*tmp))), NULL)
	IF_NULL((tmp->a = malloc(sizeof(struct s_stack))), NULL)
	IF_NULL((tmp->b = malloc(sizeof(struct s_stack))), NULL)
	IF_NULL((tmp->a->arr = malloc(sizeof(int) * len)), NULL)
	IF_NULL((tmp->b->arr = malloc(sizeof(int) * len)), NULL)
	i = 0;
	while (i < len)
	{
		err = xatoi(av[i]);
		if (err > INT_MAX || err < INT_MIN)
			return (NULL);
		tmp->a->arr[i] = err;
		tmp->b->arr[i] = 0;
		++i;
	}
	tmp->a->top = i - 1;
	tmp->b->top = 0;
	tmp->a->n = len;
	tmp->b->n = 0;
	return (tmp);
}

void					arr_swap(struct s_stack *s)
{
	int				tmp;

	if (s->n < 2)
		return;
	tmp = s->arr[s->top];
	s->arr[s->top] = s->arr[s->top - 1];
	s->arr[s->top - 1] = tmp;
}

void					arr_push(struct s_stack *to, struct s_stack *from)
{
	if (from->n < 1)
		return;
	to->top += 1;
	to->n += 1;
	to->arr[to->top] = from->arr[from->top];
	from->top -= 1;
	from->n -= 1;
}

void					arr_rot(struct s_stack *s)
{
	int				i;
	int				tmp;

	i = s->n - 1;
	tmp = s->arr[i];
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		--i;
	}
	s->arr[i] = tmp;
}

void					arr_rrot(struct s_stack *s)
{
	int				i;
	int				tmp;

	i = 0;
	tmp = s->arr[i];
	while (i < s->n - 1)
	{
		s->arr[i] = s->arr[i + 1];
		++i;
	}
	s->arr[i] = tmp;
}
