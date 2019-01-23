#include "checker.h"
#include "common.h"

int		main(int ac, char **av)
{
	struct s_stack		*s;
	struct s_node		*n;
	int					i;
	char				buf[BUFSIZ];

	i = 1;
	s = initStack();
	while (i < ac)
	{
		XPRINTF("%ld\n", xatoi(av[i]));
		pushStack(s, xatoi(av[i]));
		++i;
	}

	while ((i = read(0, buf, BUFSIZ)))
	{
		buf[i] = '\0';
		_dispatch((int *)buf);
	}
	return (0);
}
