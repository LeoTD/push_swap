#include "common.h"
#include "push_swap.h"

static int		p_exit(char *msg)
{
	xputs("push_swap: Error! ");
	xputs(msg);
	xputs("\n");
	return (-1);
}

int		main(int ac, char **av)
{
	struct s_data	*data;

	XPRINTF("Loading data... ");
	if (NULL == (data = init_data(ac - 1, av + 1)))
		return (p_exit("Bad input."));
	print_stacks(data->a, data->b);
	getchar();
	sort_data(data);
	print_stacks(data->a, data->b);
	XPRINTF("list len = %d\n", data->ops->n);
	getchar();

	return (0);
}
