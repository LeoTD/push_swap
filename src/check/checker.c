#include "checker.h"
#include "common.h"

#define BUFF_SIZE 128

static void		check_stack(struct s_stack *s)
{
	(void)s;
	xputs("\033[2J");
	xputs("Checking...\n");
}

int				main(int ac, char **av)
{
	struct s_data		*data;
	int					i;
	char				buf[BUFF_SIZE];

	i = 1;
	data = init_data(ac - 1, av + 1);
	if (ac < 81)
		print_stacks(data->a, data->b);
	while ((i = read(0, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		dispatcher(buf, data->a, data->b);
		if (ac < 81)
			print_stacks(data->a, data->b);
	}
	check_stack(data->a);
	return (0);
}
