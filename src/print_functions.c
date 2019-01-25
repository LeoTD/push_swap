#include "common.h"
#include <stdio.h>

#define CLR_SCRN "\033[2J"
#define GO_TO(x,y) XGO_TO(x,y)
#define XGO_TO(x,y) "\033[" #x ";" #y "H"
#define UPLN "\033[1A"
#define DNLN "\033[1B"

void	print_stacks(struct s_stack *a, struct s_stack *b)
{
	int					i;
	static int			ops = 0;

	XPRINTF("%s", CLR_SCRN);
	XPRINTF("%s   A", GO_TO(87, 19));
	XPRINTF("%s|-----", GO_TO(86, 19));
	XPRINTF("%s| ", GO_TO(85, 19));
	i = 0;
	while (i < a->n)
	{
		XPRINTF("%-10d%s%s", a->arr[i], UPLN, "\033[10D");
		++i;
	}
	XPRINTF("%s   B", GO_TO(87, 29));
	XPRINTF("%s|-----", GO_TO(86, 29));
	XPRINTF("%s| ", GO_TO(85, 29));
	i = 0;
	while (i < b->n)
	{
		XPRINTF("%-10d%s%s", b->arr[i], UPLN, "\033[10D");
		++i;
	}
	XPRINTF("%sPossible Commands: %s, ", GO_TO(1, 1), "Push [ pa, pb ]");
	XPRINTF("%s, %s, ", "Swap [ sa, sb, ss ]", "Rotate [ ra, rb, rr ]");
	XPRINTF("%s", "RevRotate [ rra, rrb, rrr ]");
	XPRINTF("%s%d%s--$> ", GO_TO(3, 1), ops, GO_TO(2, 1));
	fflush(stdout);
	++ops;
}
