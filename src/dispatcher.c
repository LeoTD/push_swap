#include "checker.h"
#include "common.h"

static void		dispatch_s(char *op, struct s_stack *a, struct s_stack *b)
{
	if (op[1] == 'a')
		arr_swap(a);
	else if (op[1] == 'b')
		arr_swap(b);
	else if (op[1] == 's')
	{
		arr_swap(a);
		arr_swap(b);
	}
}

static void		dispatch_p(char *op, struct s_stack *a, struct s_stack *b)
{
	if (op[1] == 'a')
		arr_push(a, b);
	else if (op[1] == 'b')
		arr_push(b, a);
}

static void		dispatch_r(char *op, struct s_stack *a, struct s_stack *b)
{
	if (op[1] == 'a')
		arr_rot(a);
	else if (op[1] == 'b')
		arr_rot(b);
	else if (op[1] == 'r')
	{
		if (op[2] != 'a' && op[2] != 'b' && op[2] != 'r')
		{
			arr_rot(a);
			arr_rot(b);
		}
		else if (op[2] == 'a')
			arr_rrot(a);
		else if (op[2] == 'b')
			arr_rrot(b);
		else if (op[2] == 'r')
		{
			arr_rrot(a);
			arr_rrot(b);
		}
	}
}

void			dispatcher(char *op, struct s_stack *a, struct s_stack *b)
{
	if (op[0] == 's')
		dispatch_s(op, a, b);
	if (op[0] == 'p')
		dispatch_p(op, a, b);
	if (op[0] == 'r')
		dispatch_r(op, a, b);
}
