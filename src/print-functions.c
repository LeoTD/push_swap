#include "common.h"

#define CLR_SCRN "\033[2J"
#define GO_TO(x,y) XGO_TO(x,y)
#define XGO_TO(x,y) "\033[" #x ";" #y "H"
#define UPLN "\033[1A"
#define DNLN "\033[1B"

void	printStacks(struct s_stack *a, struct s_stack *b)
{
	int					i;
	struct s_node		*node;
	static int			ops = 0;

	XPRINTF("%s", CLR_SCRN);
	XPRINTF("%s   A", GO_TO(87, 19));
	XPRINTF("%s|-----", GO_TO(86, 19));
	XPRINTF("%s| ", GO_TO(85, 19));
	node = a->bot;
	for (i = 0; i < a->n; ++i) {
		XPRINTF("%-10d%s%s", node->val, UPLN, "\033[10D");
		node = node->prev;
	}
	XPRINTF("%s   B", GO_TO(87, 29));
	XPRINTF("%s|-----", GO_TO(86, 29));
	XPRINTF("%s| ", GO_TO(85, 29));
	node = b->bot;
	for (i = 0; i < b->n; ++i) {
		XPRINTF("%-10d%s%s", node->val, UPLN, "\033[10D");
		node = node->prev;
	}
	XPRINTF("%sPossible Commands: %s, %s, %s, %s",
		GO_TO(1, 1),
		"Push [ pa, pb ]",
		"Swap [ sa, sb, ss ]",
		"Rotate [ ra, rb, rr ]",
		"RevRotate [ rra, rrb, rrr ]"
	);
	XPRINTF("%s%d", GO_TO(3, 1), ops);
	XPRINTF("%s--$> ", GO_TO(2, 1));
	fflush(stdout);
	++ops;
}
