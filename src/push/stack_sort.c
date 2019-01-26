#include "push_swap.h"
#include "common.h"

void			threeway_split() {}//TODO

static void		p_check_swaps(struct s_data *d)
{
	int			abool;
	int			bbool;

	abool = 0;
	bbool = 0;
	if (d->a->n >= 2 && d->a->arr[d->a->top] > d->a->arr[d->a->top - 1])
	{
		arr_swap(d->a);
		abool = 1;
	}
	if (d->b->n >= 2 && d->b->arr[d->b->top] > d->b->arr[d->b->top - 1])
	{
		arr_swap(d->b);
		bbool = 1;
	}
	if (abool && bbool)
		add_op(d->ops, ss);
	else if (abool && !bbool)
		add_op(d->ops, sa);
	else if (!abool && bbool)
		add_op(d->ops, sb);
}

void			inorder_push_tob(struct s_data *d, int a, int b, int invert)
{
	int			i;

	i = -1;
	while (++i < b)
	{
		DO_OP(arr_push(d->b, d->a), pb);
		if (invert)
			DO_OP(arr_rot(d->b), rb);
		if (a > 1 && !invert)
			p_check_swaps(d);
		else
		{
			if (d->b->n >= 2 && d->b->arr[d->b->top] > d->b->arr[d->b->top - 1])
				if (!invert)
					DO_OP(arr_swap(d->b), sb);
		}
	}
}

void			push_merge(struct s_data *d, int a, int b, int invert)
{
	int			i;
	int			end;

	i = -1;
	end = a + b;
	inorder_push_tob(d, a, b, invert);
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

int				sort_data(struct s_data *d)
{
	struct s_vars		v;
	int					i;

	v.l = 4;
	v.inv = 0;
	v.elems = d->a->n;
	while (v.l < v.elems)
	{
		v.reps = d->a->n / v.l;
		v.rem = d->a->n % v.l;
		i = -1;
		while (++i < v.reps)
			push_merge(d, v.l - (v.l / 2), v.l / 2, v.inv);
		push_merge(d, v.rem - (v.rem / 2), v.rem / 2, v.inv);
		v.l *= 2;
		v.inv = 1;
	}
	final_pass(d);
	return (0);
}
