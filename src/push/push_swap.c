#include "common.h"
#include "push_swap.h"

static int		p_error_handling(struct s_data *d)
{
	int				i;

	i = 0;
	quick_sort(d->a->arr, d->a->n);
	while (++i < d->a->n)
		if (d->a->arr[i] == d->a->arr[i - 1])
			return -1;
	return 0;
}

static int		p_exit(char *msg)
{
	xputs("push_swap: Error! ");
	xputs(msg);
	xputs("\n");
	return (-1);
}

static char		*p_gettype(int n)
{
	if (n == pa)
		return ("pa");
	else if (n == pb)
		return ("pb");
	else if (n == sa)
		return ("sa");
	else if (n == sb)
		return ("sb");
	else if (n == ss)
		return ("ss");
	else if (n == ra)
		return ("ra");
	else if (n == rb)
		return ("rb");
	else if (n == rr)
		return ("rr");
	else if (n == rra)
		return ("rra");
	else if (n == rrb)
		return ("rrb");
	else if (n == rr)
		return ("rr");
	return (":(");
}

static void		p_print_inst(struct s_instlist *l)
{
	int				i;
	struct s_inst	*iter;

	i = -1;
	iter = l->head;
	while (++i < l->n && iter != NULL)
	{
		xputs(p_gettype(iter->type));
		xputs("\n");
		iter = iter->next;
	}
}

int				main(int ac, char **av)
{
	struct s_data	*data;
	struct s_data	*e;

	if (NULL == (e = init_data(ac - 1, av + 1)))
		return (p_exit("Bad input."));
	if (NULL == (data = init_data(ac - 1, av + 1)))
		return (p_exit("Malloc error."));
	if (p_error_handling(e))
		return (p_exit("Bad input."));
	// print_stacks(data->a, data->b);
	sort_data(data);
	// print_stacks(data->a, data->b);
	// XPRINTF("list len = %d\n", data->ops->n);
	// getchar();
	p_print_inst(data->ops);
	return (0);
}
