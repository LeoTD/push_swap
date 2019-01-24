#include "checker.h"
#include "common.h"

#define BUFF_SIZE 128


int		main(int ac, char **av)
{
	struct s_stack		*a, *b;
	int					i;
	char				buf[BUFF_SIZE];

	i = 1;
	a = initStack();
	b = initStack();
	while (i < ac)
	{
		//XPRINTF("%ld\n", xatoi(av[i]));
		pushStack(a, newNode(xatoi(av[i])));
		++i;
	}
	if (ac < 81)
		printStacks(a, b, ac - 1);
	while ((i = read(0, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		dispatcher(buf, a, b);
#ifdef PRINT_MODE
		if (ac < 81)
			printStacks(a, b, ac - 1);
#endif
	}
	return (0);
}
