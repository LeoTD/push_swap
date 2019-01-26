#include "common.h"
#include "push_swap.h"

void			pull_tob(struct s_data *d, int b)
{
	int			i;

	i = -1;
	while (++i < b)
	{
		DO_OP(arr_rrot(d->a), rra);
		DO_OP(arr_push(d->b, d->a), pb);
	}
}

void			pull_merge(struct s_data *d, int a, int b)
{
	int			i;
	int			end;

	i = -1;
	end = a + b;
	pull_tob(d, b);
	while (++i < end)
	{
		if (b > 0 && (d->a->arr[d->a->top] > d->b->arr[d->b->top] || !a))
		{
			DO_OP(arr_push(d->a, d->b), pa);
			DO_OP(arr_rot(d->a), ra);
			--b;
		}
		else
		{
			if (--a >= 0)
				DO_OP(arr_rot(d->a), ra);
		}
	}
}

void			final_pass(struct s_data *d)
{
	int					i;
	int					j;
	struct s_vars		v;

	i = 0;
	v.elems = d->a->n;
	while (++i < v.elems)
	{
		if (d->a->arr[i] < d->a->arr[i - 1])
			continue ;
		v.b = i;
		j = i;
		while (++j < v.elems)
			if (d->a->arr[j] > d->a->arr[j - 1])
				break ;
		v.a = j - i;
		pull_merge(d, v.a, v.b);
		i = 0;
	}
}
