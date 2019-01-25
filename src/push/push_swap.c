#include "push_swap.h"
#include "common.h"

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

	if (NULL == (data = init_data(ac - 1, av + 1)))
		return (p_exit("Bad input."));

	return (0);
}
