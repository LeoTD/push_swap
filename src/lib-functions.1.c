#include "common.h"

long			xatoi(char *s)
{
	long		res;
	int			i, n;

	i = 0;
	n = 10;
	res = 0;
	if (s[0] == '-')
	{
		++i;
		++n;
	}
	while (s[i] != 0 && i < n)
	{
		res = (res * 10) + (s[i] - '0');
		++i;
	}
	res *= (s[0] == '-' ? -1 : 1);
	return (res);
}

int				xstrlen(char *s)
{
	int			i;

	i = -1;
	while (s[++i] != 0)
		;
	return (i);
}

void			xprint(char *s)
{
	write(1, s, xstrlen(s));
}
