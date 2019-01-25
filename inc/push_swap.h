#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

enum			e_inst
{
	pa,
	pb,
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

struct			s_inst
{
	char			type;
	struct s_inst	*next;
	struct s_inst	*prev;
};

struct			s_instlist
{
	int				n;
	struct s_inst	*head;
	struct s_inst	*tail;
};

#endif
