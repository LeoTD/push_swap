#include "checker.h"
#include "common.h"

#define BUFF_SIZE 128

static void		compare_stacks(struct s_stack *a, struct s_stack *b)
{
	int			i;

	XPRINTF("\033[2J");
	xputs("Checking...\n");
	i = 0;
	while (i < a->n)
	{
		if (a->arr[i] != b->arr[i])
		{
			XPRINTF("\n%d != %d", a->arr[i], b->arr[i]);
			xputs("\n -- FAIL --\n");
			return ;
		}
		++i;
	}
	xputs("\n --  OK  --\n");
}

int				main(int ac, char **av)
{
	struct s_data		*data;
	struct s_data		*sorted_data;
	int					i;
	char				buf[BUFF_SIZE];

	i = 1;
	data = init_data(ac - 1, av + 1);
	sorted_data = init_data(ac - 1, av + 1);
	quick_sort(sorted_data->a->arr, sorted_data->a->n);
	print_stacks(sorted_data->a, data->a);
	while ((i = read(0, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (buf[0] == 'e')
			break ;
		dispatcher(buf, data->a, data->b);
		if (ac < 81)
			print_stacks(data->a, data->b);
	}
	compare_stacks(sorted_data->a, data->a);
	return (0);
}
