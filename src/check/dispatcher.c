#include "checker.h"
#include "common.h"

static void		_dispatchS(char *op, struct s_stack *a, struct s_stack *b)
{
	if (op[1] == 'a')
		;
	else if (op[1] == 'b')
		;
	else if (op[1] == 's')
		;
}

static void		_dispatchP(char *op, struct s_stack *a, struct s_stack *b)
{

	if (op[1] == 'a')
		;
	else if (op[1] == 'b')
		;
}

static void		_dispatchR(char *op, struct s_stack *a, struct s_stack *b)
{
	if (op[1] == 'a')
		;
	else if (op[1] == 'b')
		;
	else if (op[1] == 'r')
	{
		if (op[2] == '\0')
			;
		else if (op[2] == 'a')
			;
		else if (op[2] == 'b')
			;
		else if (op[2] == 'r')
			;
	}
}

void			dispatcher(char *op, struct s_stack *a, struct s_stack *b)
{
	if (op[0] == 's')
		_dispatchS(op, a, b);
	if (op[0] == 'p')
		_dispatchP(op, a, b);
	if (op[0] == 'r')
		_dispatchR(op, a, b);
}
