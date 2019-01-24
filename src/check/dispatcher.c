#include "checker.h"
#include "common.h"

static void		_dispatchS(char *op, struct s_stack *a, struct s_stack *b)
{
	if (op[1] == 'a')
		inst_swap(a);
	else if (op[1] == 'b')
		inst_swap(b);
	else if (op[1] == 's')
	{
		inst_swap(a);
		inst_swap(b);
	}
}

static void		_dispatchP(char *op, struct s_stack *a, struct s_stack *b)
{

	if (op[1] == 'a')
		inst_push(a, b);
	else if (op[1] == 'b')
		inst_push(b, a);
}

static void		_dispatchR(char *op, struct s_stack *a, struct s_stack *b)
{
	if (op[1] == 'a')
		inst_rot(a);
	else if (op[1] == 'b')
		inst_rot(b);
	else if (op[1] == 'r')
	{
		if (op[2] != 'a' && op[2] != 'b' && op[2] != 'r')
		{
			inst_rot(a);
			inst_rot(b);
		}
		else if (op[2] == 'a')
			inst_rrot(a);
		else if (op[2] == 'b')
			inst_rrot(b);
		else if (op[2] == 'r')
		{
			inst_rrot(a);
			inst_rrot(b);
		}
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
