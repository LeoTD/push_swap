#include "push_swap.h"
#include "common.h"

struct s_vars
{
	int		l;
	int		reps;
	int		rem;
};

void			threeway_split() {}//TODO

static void		p_check_swaps(struct s_data *d)
{
	int			a;
	int			b;

	a = 0;
	b = 0;
	if (d->a->n >= 2 && d->a->arr[d->a->top] > d->a->arr[d->a->top - 1])
	{
		arr_swap(d->a);
		a = 1;
	}
	if (d->b->n >= 2 && d->b->arr[d->b->top] > d->b->arr[d->b->top - 1])
	{
		arr_swap(d->b);
		b = 1;
	}
	if (a && b)
		add_op(d->ops, ss);
	else if (a && !b)
		add_op(d->ops, sa);
	else if (!a && b)
		add_op(d->ops, sb);
}

void			push_merge(struct s_data *d, int len)
{
	int			i;
	int			a;

	a = 0;
	i = -1;
	while (++i < len)
		arr_push(d->b, d->a);
	i = -1;
	while (i < len * 2)
	{
		if (d->b->n > 0 && d->a->arr[d->a->top] > d->b->arr[d->b->top])
		{
			arr_push(d->a, d->b);
			arr_rot(d->a);
		}
		else
		{
			++a;
			if (a < 3)
				arr_rot(d->a);
		}
	}
}

int				sort_data(struct s_data *d)
{
	struct s_vars		v;
	int					i;
	int					done;

	v.l = 2;
	v.reps = d->a->n / v.l;
	v.rem = d->a->n % v.l;
	done = 0;
	while (!done)
	{
		i = -1;
		while (++i < v.reps)
			push_merge(d, v.l);
		i = -1;
		while (++i < v.rem)

	}
}
